/**
  File holding functions related to user command 'f'.
  Handles validation of input, calculating and printing the billing of a 
  given park, either at a given date or overall.

  @file billing.c
  
  @author ist163484 - Michael Maycock
*/

#include "project.h"

/* FUNCTION DECLARATIONS */

static int getArgsF(char* name, Date *date, char *buffer);
static void getAllBilling(char *park_name, Context *context);
static void getBilling(char *park_name, Date date, Context*context);
static void printAllBilling(Date date, float value);

/* FUNCTION DEFINITIONS */

/**
  Handles the 'f' command by processing the input buffer to retrieve the 
  arguments, then either calls getAllBilling() or getBilling() based on the 
  presence of arguments.

  @param context Pointer to the Context structure containing program data.
*/
void handleF(Context *context) {
  char *buffer = context->buffer, name[strlen(buffer)];
  int no_arg = FALSE;
  Date date = {0};
  //Get args
  no_arg = getArgsF(name, &date, buffer);
  //Input has argument ? ternary
  no_arg ? getAllBilling(name, context)
  : getBilling(name, date, context);
  //Free mem allocation
}

/**
  Retrieves the arguments for the 'f' command from the input buffer.
  Stores these arguments on the given parameters.

  @param name Pointer to a character array to store the park name.
  @param date Pointer to a Date structure to store the date.
  @param buffer Pointer to the input buffer containing the command and 
  arguments.

  @return TRUE if no arguments other than the park name are found, 
  FALSE otherwise.
*/
static int getArgsF(char* name, Date *date, char *buffer) {
  //Check if name has ""
  if(sscanf(buffer, "%*c \"%[^\"]\"", name) != 1) {
    if(sscanf(buffer, "%*c %s %d-%d-%d ",
    name, &date->day, &date->mon, &date->year) != 4)
      return TRUE; //if sscanf != 4 no other args than name exist
  }
  else {
    if(sscanf(buffer, "%*c \"%[^\"]\" %d-%d-%d ",
    name, &date->day, &date->mon, &date->year) != 4)
      return TRUE;
  }
  //input has arguments
  return FALSE;
}

/**
  Retrieves all billing information for a specific park from the context.
  Prints valid event data by calling printAllBilling().
  Print format for each date billed for the given park:
  <date> <value-billed>

  @param park_name The name of the park for which to retrieve billing 
  information.
  @param context Pointer to the Context structure containing park and event 
  data.
*/
static void getAllBilling(char *park_name, Context *context) {
  Date date = {0}; 
  int park_id, first_event = TRUE;
  Event *event; float value = 0;
  park_id = checkParkExists(park_name, context->parks_array);
  if(park_id == NO_PARK) {
    printf("%s: no such parking.\n", park_name);
    return;
  }
  event = context->parks_array[park_id]->event_list.head;
  while(event) {
    // Check event type
    if(event->type == 's') {
      // If the event is the first event to be evaluated
      if(first_event) {
        updateDate(&date, event->date);
        first_event = FALSE;
      }
      if(areDatesEqual(date, event->date))
        value += event->bill;
      else {
        printAllBilling(date, value);
        value = 0;
        updateDate(&date, event->date);
        value = event->bill;
      }
    }
    event = event->next;
  }
  if(value) 
    printAllBilling(date, value);
}

/**
  Retrieves billing information for a specific park on a given date from the 
  context.
  If the data is valid, prints in the format:
  <licence> <exit-hour> <value-paid>

  @param park_name The name of the park for which to retrieve billing 
  information.
  @param date The date for which to retrieve billing information.
  @param context Pointer to the Context structure containing park and event 
  data.
*/
static void getBilling(char *park_name, Date date, Context *context) {
  int park_id;
  Event *event;
  park_id = checkParkExists(park_name, context->parks_array);
  if(park_id == NO_PARK) {
    printf("%s: no such parking.\n", park_name);
    return;
  }
  if(!validateEventDate(*context->last_event_date, date)) {
    printf("invalid date.\n");
    return;
  }
  event = context->parks_array[park_id]->event_list.head;
  while(event) {
    if(event->type == 's') {
      if(areDatesEqual(date, event->date))
        printf("%s %02d:%02d %.2f\n",
        event->licence, event->date.hour, event->date.min, 
        (double)event->bill);
    }
    event = event->next;
  }
}

/**
  Prints billing information for a specific date.
  Format: <date> <value-billed>

  @param date The date of the bill to print.
  @param value The billing value to be printed.
*/
static void printAllBilling(Date date, float value) {
  printf("%02d-%02d-%04d ", date.day, date.mon, date.year);
  printf("%.2f\n", (double)value);
}
