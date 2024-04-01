/**
  File holding functions related to user command 'v'.
  Has handling and validation of input.
  Relates to the printing of entry and exit events for a given car.

  @file handle_v.c
  
  @author ist163484 - Michael Maycock
*/

/* HEADER FILE INCLUSIONS */

#include "project.h"

/* FUNCTION DECLARATIONS */

static void v_getLicence(char *licence, Context *context);
static void printCarEvents(Park **array,char *licence, int length);

/* FUNCTION DEFINITIONS */

/**
  Handles the 'v' command by retrieving the license plate from the context 
  buffer, validating it, allocating memory for temporary array for sorting, 
  making a copy of parks to the temporary array, sorting the parks 
  alphabetically, printing events related to the specified license plate, 
  and freeing the allocated memory.

  @param context Pointer to the project context.
*/
void handleV(Context *context) {
  int length = 0;
  char licence[LICENCE_SIZE + 1] = {'\0'};
  Park **temp_array = NULL;
  //Get the licence plate from buffer and verify value
  v_getLicence(licence, context);
  if(!validateLicence(licence)) {
    printf("%s: invalid licence plate.\n", licence);
    return;
  }
  //Allocate temp_array for sorting
  length = getParksArrayL(context->parks_array);
  temp_array = malloc(length*sizeof(Park *));
  if(!temp_array) allocFail(context);
  memset(temp_array, 0, length*sizeof(Park *));
  //Make a copy of parks to temp_array (non destructive sorting)
  copyParks(context->parks_array, temp_array);
  //Sort dos parques por ordem alfabetica
  parksort(temp_array, length);

  printCarEvents(temp_array, licence, length); //Print events for licence
  
  free(temp_array);
}

/**
  Retrieves the license plate from the buffer in the project context.

  @param licence Pointer to the character array to store the license plate.
  @param context Pointer to the project context.
*/
static void v_getLicence(char *licence, Context *context) {
  char *buffer = context->buffer;
  sscanf(buffer, "%*c %s", licence);
}

/**
  Prints the events related to the specified license plate across all parks.
  The events are ordered by Park name.
  Format: <pakr-name> <entry-date> <entry-hour> <exit-date> <exit-hour>
  Prints only entry event if car is inside a park for the last print.

  @param array Pointer to the array of pointers to Park structures.
  @param licence Pointer to the character array representing the license 
  plate.
  @param length The length of the parks array.
*/
static void printCarEvents(Park **array,char *licence, int length) {
  int i, count = 0;
  Event *event;
  char last_event = '\0';
  for(i = 0; i < length; i++) {
    event = array[i]->event_list.head;
    while(event) {
      //if licence and the licence of the event are the same
      if(!strcmp(licence, event->licence)){
        if(event->type == 'e') {
          printf("%s %02d-%02d-%04d %02d:%02d", array[i]->name, 
          event->date.day, event->date.mon, event->date.year, 
          event->date.hour, event->date.min); last_event = 'e';
        }
        if(event->type == 's') {
          printf(" %02d-%02d-%04d %02d:%02d\n", 
          event->date.day,event->date.mon, event->date.year, 
          event->date.hour, event->date.min);
          last_event = 's';
        }
        count++;
      }
      event = event->next;
    }
    if(last_event == 'e')
      printf("\n");
    last_event = '\0';
  }
  if(!count)
    printf("%s: no entries found in any parking.\n", licence);
}

/**
  Sorts an array of pointers to Park structures alphabetically based on park 
  name.
  Uses insertion sort because maximum number of parks is below or equal to 20.

  @param arr Pointer to the array of pointers to Park structures.
  @param len The length of the array.
*/
void parksort(Park *arr[], int len) {
  int i, j;
  char *comp;
  Park *temp;
  //arr[0] is already sorted
  for(i = 1; i < len; i++){
    temp = arr[i]; //save the value of arr[i]
    comp = arr[i]->name; //value of name to sort
    j = i - 1;
    //While name of arr[j] is higher than comp alphanumerically, swap them
    while(j >= 0 && strcmp(arr[j]->name, comp) > 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    //Insert the Park in it's ordered position
    arr[j + 1] = temp;
  }
}