/**
  File holding functions related to user commands 'e' and 's'.
  Has handling and validation of Event, Car and Date structures.

  @file event.c
  
  @author ist163484 - Michael Maycock
*/

/* HEADER FILE INCLUSIONS */

#include "project.h"

/* MACROS */

/** Days in each month of a non leap year. */
const int DAYS_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define DAYS_IN_YEAR 365 /**< Number of days in a year. */ 
#define HOURS_IN_DAY 24 /** < Number of hours in a day. */
#define MINUTES_IN_HOUR 60 /** < Number of minutes in an hour. */

/* FUNCTION DECLARATIONS */

static Event getEventData(char* park_name, char* buffer);
static int validateEventData(char *name, Event *event, Context *context, 
                              int park_id);
static int checkCarInParks(char *licence, Park **cars_array);
static int checkCarInPark(char *licence, Park *park);
static int validateDateLimits(Date date);
static void addEvent(Event *event, int park_id, Context *p_context);
static void addCar(Event *event, int park_id, Context *p_context);
static void addCarToHash(Car *car, Park *park);
static void removeCar(Event *event, int park_id, Context *p_context);
static float calculatePay(Date entry, Date exit, Park *park);
static int calculateTimeDif(Date entry, Date exit);

/* FUNCTION DEFINITIONS */

/**
  Handles input commands 'e' and 's'.
  Handles event input by creating and processing events based on the provided
  user input.
  Checks validity of event data, printing a message if an error is found.
  If event data is valid, adds/removes event and corresponding car,
  depending on the command 'e'/'s'.

  @param context Pointer to the project context.
*/
void handleEvent(Context *context) {
  Event *p_event;
  int park_i;
  char park_name[strlen(context->buffer)];

  p_event = malloc(sizeof(Event));
  if(!p_event) allocFail(context);
  memset(p_event, 0, sizeof(Event));

  *p_event = getEventData(park_name, context->buffer);
  park_i = checkParkExists(park_name, context->parks_array);
  //Check validity of event data
  if(!validateEventData(park_name, p_event, context, park_i)) {
    free(p_event);
    return;
  }
  //Everything was validated, add event and car to park
  addEvent(p_event, park_i, context);
  if(p_event->type == 'e') 
    addCar(p_event, park_i, context);
  if(p_event->type == 's')
    removeCar(p_event, park_i, context);
}

/**
  Retrieves event data from the provided buffer and stores it in the given 
  event structure.
  Also retrieves the park name associated with the event.

  @param park_name Pointer to the character array where the park name will be 
  stored.
  @param buffer Pointer to the character array containing the event data.

  @return Returns an Event structure containing the parsed event data.
*/
static Event getEventData(char* park_name, char* buffer) {
  Event event;
  //Get licence and date (day, month, year, hour, minute)
  if(sscanf(buffer, "%c \"%[^\"]\" %8s %d-%d-%d %d:%d", &event.type, 
  park_name, event.licence, &event.date.day, &event.date.mon, 
  &event.date.year, &event.date.hour, &event.date.min) != 8) {
    sscanf(buffer, "%c %s %8s %d-%d-%d %d:%d", &event.type, park_name, 
    event.licence, &event.date.day, &event.date.mon, &event.date.year, 
    &event.date.hour, &event.date.min);
  }
  return event;
}

/**
  Validates the event data based on the provided park name, event, context 
  and park ID.
  Prints a custom message to stdout if a validation error is found.

  @param name Pointer to the character array containing the park name.
  @param event Pointer to the Event structure containing the event data.
  @param context Pointer to the project context.
  @param park_id Index of the park in the parks array.

  @return Returns TRUE if the event data is valid, FALSE otherwise.
*/
static int validateEventData(char *name, Event *event, Context *context, 
int park_id) {
  // Check if park exists
  if(park_id == NO_PARK) {
    printf("%s: no such parking.\n", name);
    return FALSE;
  }
  // Check if park is full
  if(event->type == 'e' && checkParkFull(context->parks_array[park_id])) {
    printf("%s: parking is full.\n", name);
    return FALSE;
  }
  // Check validity of input licence plate
  if(!validateLicence(event->licence)) {
    printf("%s: invalid licence plate.\n", event->licence);
    return FALSE;
  }
  // Check if car is already inside a park for entry event
  if(event->type=='e' 
  && checkCarInParks(event->licence, context->parks_array)) {
    printf("%s: invalid vehicle entry.\n", event->licence);
    return FALSE;
  }
  // Check if car is already inside given park for exit event
  if(event->type=='s' 
  && !checkCarInPark(event->licence, context->parks_array[park_id])) {
    printf("%s: invalid vehicle exit.\n", event->licence);
    return FALSE;
  }
  // Check if event date is valid
  if(!validateEventDate(event->date, *context->last_event_date)) {
    printf("invalid date.\n");
    return FALSE;
  }
  return TRUE;
}

/**
  Validates the licence plate string.

  @param licence Pointer to the character array containing the licence plate.

  @return Returns TRUE if the licence plate format is valid, FALSE otherwise.
*/
int validateLicence(char *licence) {
  int i, n_digits = 0, n_letters = 0;
  // Test pairs or numbers or uppercase letters
  for(i = 0; i < LICENCE_SIZE; i+=3) {
    if(isupper(licence[i]) && isupper(licence[i+1]))
      n_letters++;
    else if(isdigit(licence[i]) && isdigit(licence[i+1]))
      n_digits++;
    else
      return FALSE;
  }
  // Test '-' seperators
  for(i = 2; i < 8; i+=3) {
    if(licence[i] != '-')
      return FALSE;
  }
  // Test at least 1 of each pair exists (uppercase letters and numbers)
  if(!n_letters || !n_digits)
    return FALSE;
  return TRUE;
}  

/**
  Checks if a car with the given licence plate is parked in any of the parks 
  in the provided array.

  @param licence Pointer to the character array containing the licence plate.
  @param parks_array Pointer to an array of pointers to Park structures.

  @return Returns TRUE if the car is parked in any of the parks, 
  FALSE otherwise.
*/
static int checkCarInParks(char *licence, Park **cars_array) {
  int i;
  for(i = 0; i < MAX_PARKS; i++) {
    //If no more parks to check, car is not inside
    if(!cars_array[i])
      break;
    //If there are no cars in the car park, skip car park
    if(checkCarInPark(licence, cars_array[i]))
      return TRUE;
    }
  return FALSE;
}

/**
  Checks if a car with the given licence plate is parked in the specified 
  park.

  @param licence Pointer to the character array containing the licence plate.
  @param park Pointer to the Park structure representing the park to 
  be checked.

  @return Returns TRUE if the car is parked in the park, FALSE otherwise.
*/
static int checkCarInPark(char *licence, Park *park) {
  int hash = hashLicence(licence, HASH_TABLE_RESIZE(park->max));
  Car **car_array = park->car_array;
  Car *tmp = car_array[hash];

  while(tmp != NULL && strcmp(tmp->car_event->licence, licence) != 0) {
    tmp = tmp->next;
  }
  return tmp != NULL;
}
  

/**
  Validates the limits of a given date.
  Also checks if the date is newer than the last event date.

  @param new The Date structure representing the new event date.
  @param last_event_date The Date structure representing the date of the last 
  event.

  @return Returns TRUE if the new event date is valid, FALSE otherwise.
*/
int validateEventDate(Date new, Date last_event_date) {
  //Compare limits
  if(!validateDateLimits(new))
    return FALSE;
  //Compare years
  if(new.year < last_event_date.year)
    return FALSE;
  //Compare months
  if(new.year == last_event_date.year) {
    if(new.mon < last_event_date.mon)
      return FALSE;
    //Compare days
    if(new.mon == last_event_date.mon) {
      if(new.day < last_event_date.day)
        return FALSE;
      //Compare hours
      if(new.day == last_event_date.day) {
        if(new.hour < last_event_date.hour)
          return FALSE;
        //Compare minutes
        if(new.hour == last_event_date.hour) {
          if(new.min < last_event_date.min)
            return FALSE;
        }
      }
    }
  }
  return TRUE; //Pass all validations
}

/**
  Validates the limits of a given date, including month, day, hour, 
  and minute.

  @param date The Date structure representing the date to be validated.

  @return Returns TRUE if the date limits are valid, FALSE otherwise.
*/
static int validateDateLimits(Date date) {
  if(date.mon > 12 || date.mon < 1)
    return FALSE;
  if(date.day < 1 || date.day > DAYS_MONTH[date.mon - 1])
    return FALSE;
  if(date.hour < 0 || date.hour > 23)
    return FALSE;
  if(date.min < 0 || date.min > 59)
    return FALSE;
  return TRUE;
}

/**
  Adds a new event to the event list of the specified park.

  @param event Pointer to the Event structure representing the new event.
  @param park_id Index of the park in the parks array.
  @param p_context Pointer to the project context. Contains parks_array.
*/
static void addEvent(Event *event, int park_id, Context *p_context) {
  Park *park = p_context->parks_array[park_id];
  //If there are no events inside the park
  if(!park->event_list.head) {
    park->event_list.head = event;
    park->event_list.tail = event;
  }
  else {
    park->event_list.tail->next = event;
    park->event_list.tail = event;
  }
  event->next = NULL;
  //The new event date becomes the last event date between all parks
  updateDate(p_context->last_event_date, event->date);
}

/**
  Updates the given Date structure with the values from another Date 
  structure.

  @param date Pointer to the Date structure to be updated.
  @param date2 The Date structure containing the new date values.
*/
void updateDate(Date *date, Date date2) {
  *date = date2;
}

/**
  Adds a car to the specified park in the project context.

  @param event Pointer to the Event structure representing the event 
  related to the new car.

  @param park_id Index of the park in the parks array.
  @param p_context Pointer to the project context.
*/
static void addCar(Event *event, int park_id, Context *p_context) {
  Park *park = p_context->parks_array[park_id];
  Car *car = malloc(sizeof(Car));
  if(!car) {
    free(event);
    allocFail(p_context);
    exit(0);
  }
  memset(car, 0, sizeof(Car));
  //Park event related to car
  car->car_event = event;
  // Add car to the hash table inside park
  addCarToHash(car, park);
  park->avail-=1;
  printf("%s %d\n", park->name, park->avail);
}

/**
  Adds a car to the hash table inside the specified park.

  @param car Pointer to the Car structure representing the car to be added.
  @param park Pointer to the Park structure representing the park.
*/
static void addCarToHash(Car *car, Park *park) {
  int table_size = HASH_TABLE_RESIZE(park->max);
  int hash = hashLicence(car->car_event->licence, table_size);
  car->next = park->car_array[hash];
  park->car_array[hash] = car;
}

/**
  Removes a car from the car array of the specified park in the project 
  context.

  @param event Pointer to the Event structure representing the exit event of 
  the car.
  @param park_id Index of the park in the parks array.
  @param p_context Pointer to the project context.
*/
static void removeCar(Event *event, int park_id, Context *p_context) {
  // Park where the car is located
  Park *park = p_context->parks_array[park_id];
  Event *entry = NULL, *exit = event;
  char *licence = event->licence;
  float pay = 0;

  int table_size = HASH_TABLE_RESIZE(park->max);
  int hash = hashLicence(event->licence, table_size);
  Car **car_array = park->car_array;
  Car *tmp = car_array[hash], *prev = NULL;

  while(tmp != NULL && strcmp(tmp->car_event->licence, licence) != 0) {
    prev = tmp;
    tmp = tmp->next; 
  }
  // Case for deleting the head
  if (prev == NULL)
    car_array[hash] = tmp->next;
  else // Case for deleting in the middle of the list 
    prev->next = tmp->next;
  
  park->avail+=1; // Increase park availability by 1 because car left Park
  entry = tmp->car_event; // Pointer to car entry event
  pay = calculatePay(entry->date, event->date, park); //Calculate pay
  // Print successful exit event message
  printf("%s %02d-%02d-%d %02d:%02d %02d-%02d-%d %02d:%02d %.2f\n",
  licence, entry->date.day, entry->date.mon, entry->date.year,
  entry->date.hour, entry->date.min, exit->date.day, exit->date.mon,
  exit->date.year, exit->date.hour, exit->date.min, (double)pay);
  // Set bill field to pay ammount for exit event
  event->bill = pay;
  // Free memory allocated to car (left the car park)
  free(tmp);
}

/**
  Calculates the parking fee for a car based on the entry and exit dates 
  and the park's pricing.

  @param entry The Date structure representing the entry date of the car.
  @param exit The Date structure representing the exit date of the car.
  @param park Pointer to the Park structure representing the park where the 
  car parked.

  @return Returns the calculated parking fee for the car.
*/
static float calculatePay(Date entry, Date exit, Park *park) {
  float pay=0, price_15=park->x, price_15_1h=park->y, price_day=park->z;
  int i, minutes = 0, days = 0, n_mins15 = 0;
  // Calculate minutes between entry and exit
  minutes = calculateTimeDif(entry, exit);
  // Calculate days and remaining minutes
  days = minutes / (MINUTES_IN_HOUR * HOURS_IN_DAY); // Number of 24h blocks
  minutes -= (days * MINUTES_IN_HOUR * HOURS_IN_DAY); // Remaining minutes
  n_mins15 = minutes / 15; // Number of 15 minute blocks
  minutes -= n_mins15 * 15; // Remaining minutes
  // Calculate bill for all 15min blocks spent in park
  for(i = 1; i <= n_mins15; i++) {
    if(i <= 4) // Calculate bill for every 15m block before 1h
      pay += price_15;
    else
      pay += price_15_1h; // Calculate bill for every 15m block after 1h
  }
  // Calculate left over minutes
  if(minutes != 0)
    // Check if an hour has already passed to apply correct price
    pay = n_mins15 >= 4 ? pay + price_15_1h : pay + price_15;
  // If the bill from the minutes is greater than daily max
  if(pay > price_day)
    pay = price_day;  // Bill daily max
  pay += days * price_day; // Add number of 24h blocks to bill
  return pay;
}

/**
  Calculates the time difference in minutes between two dates.

  @param entry The Date structure representing the entry date.
  @param exit The Date structure representing the exit date.

  @return Returns the time difference in minutes between the two dates.
*/
static int calculateTimeDif(Date entry, Date exit) {
  int i, minutes = 0;
  /* Subtract from minutes variable, the number of minutes between the start 
  of entry.year to the entry date */
  for(i=0; i<entry.mon-1; i++) {
    minutes -= DAYS_MONTH[i]*HOURS_IN_DAY*MINUTES_IN_HOUR; 
  }
  minutes -= (entry.day*HOURS_IN_DAY*MINUTES_IN_HOUR)+
  (entry.hour*MINUTES_IN_HOUR)+entry.min;
  /* Add to minutes variable, the number of minutes between the start 
  of exit.year to the exit date */
  for(i = 0; i<exit.mon-1; i++){
    minutes += DAYS_MONTH[i]*HOURS_IN_DAY*MINUTES_IN_HOUR;
  }
  minutes += (exit.day*HOURS_IN_DAY*MINUTES_IN_HOUR)+
  (exit.hour*MINUTES_IN_HOUR)+exit.min;
  /* Add to minutes variable, the difference in minutes between exit.year and 
  entry.year */
  if(exit.year > entry.year){
    for(i = exit.year; i > entry.year; i--){
      minutes += DAYS_IN_YEAR*HOURS_IN_DAY*MINUTES_IN_HOUR;
    }
  }
  return minutes;
}

/**
  Checks if two Date structures represent the same day.

  @param date1 The first Date structure.
  @param date2 The second Date structure.
  @return Returns 1 if the dates are equal, otherwise returns 0.
*/
int areDatesEqual(Date date1, Date date2) {
  return (date1.year == date2.year && date1.mon == date2.mon
  && date1.day == date2.day);
}

/**
  Generates a hash value for a given licence plate string based on the
  provided table size.

  @param licence Pointer to the character array containing the licence plate.
  @param table_size The size of the hash table.

  @return Returns the hash value for the licence plate.
*/
unsigned int hashLicence(char *licence, int table_size) {
  unsigned int hash = 0;
  unsigned char *p;

  for (p = (unsigned char*)licence; *p != '\0'; p++)
    hash = 37 * hash + *p;

  return hash % table_size;
}