/**
  Project header file containing global macros, structure definitions, 
  and function declarations for managing a vehicle parking system.

  @file project.h

  @author ist163484 - Michael Maycock
*/

#ifndef PROJECT_H // Check if PROJECT_H is not defined.
#define PROJECT_H // Define PROJECT_H to avoid multiple inclusion.

/* LIBRARY INCLUSIONS */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* MACROS */

#define BUFFER_SIZE BUFSIZ /**< Size of the buffer used to hold user input. */
#define INPUT_STREAM stdin /**< Define input stream. */
#define MAX_PARKS 20 /**< Maximum amount of parks. */
#define TRUE 1 /**< Used for truthy values. */
#define FALSE 0 /**< Used for falsy values. */
#define NO_PARK -1 /**< Used when no parks were found on the given context. */
#define LICENCE_SIZE 8 /**< Size of a licence plate in this project. */
/**
  Calculate the size of a hash table based on input.

  @param A The current maximum capacity of the park.

  @return Returns the new maximum capacity after resizing.
*/
#define HASH_TABLE_RESIZE(A) ((A) * 2 + 1)

/* STRUCTURES */

/**
  Represents a date structure containing day, month, year, hour 
  and minute components.
*/
typedef struct _date_ {
  int day; /**< (int) Day of the Date structure */
  int mon; /**< (int) Month of the Date structure */
  int year; /**< (int) Year of the Date structure */
  int hour; /**< (int) Hour of the Date structure */
  int min; /**< (int) Minute of the Date structure */
} Date;

/**
  Represents an event structure containing license plate, event type, date, 
  next event pointer and bill.
  Events represent an entry or exit of a vehicle from a vehicle park.
*/
typedef struct _event_ {
  /** (char *) Licence plate of the car of the event. */
  char licence[LICENCE_SIZE + 1]; 
  char type; /**< (char) Type of event. 'e' for entrance. 's' for exit. */
  Date date; /**< (Date) Date and time of the event. */
  struct _event_ *next; /**< (Event *) Pointer to the next event. */
  float bill; /**< (float) Amount to pay when exiting car park. */
} Event;

/**
  Represents a list of events containing head and tail pointers.
*/
typedef struct _event_list_ {
  /** (Event *) Pointer to the first element of an event list. */
  Event *head;
  /** (Event *) Pointer to the last element of an event list. */
  Event *tail;
} Event_List;

/**
  Represents a car structure containing a pointer to the car's last entry 
  event and a pointer to the next car on the list.
*/
typedef struct _car_ {
  /** (Event *) Pointer to the entry event related to car.*/
  Event *car_event;
  /** (Car *) Pointer to the next Car in the car list. */
  struct _car_ *next;
} Car;

/**
  Represents a park structure containing name, maximum capacity, 
  available capacity, cost per 15 minutes before one hour, 
  cost per 15 minutes after one hour, max cost per 24 hours, list of entry 
  and exit events, and a list of the cars inside the park.
*/
typedef struct _park_ {
  char *name; /**< (char) Park's name. */
  int max; /**< (int) Park's maximum vehicle capacity. */
  int avail; /**< (int) Park's available vehicle capacity. */
  float x; /**< (float) Cost per 15 minutes in the park before one hour. */
  float y; /**< (float) Cost per 15 minutes in the park after one hour. */
  float z; /**< (float) Max cost per 24 hours in the park. */
  Event_List event_list; /**< List of entry/exit events from the park. */
  Car **car_array; /**< List of cars inside the park. */
} Park;

/**
  Represents the application context, holding a buffer for temporary data, 
  an array of pointers to Park structures and a pointer to a Date structure 
  tracking the last entry/exit event across all parks.
*/
typedef struct _context_ {
  char *buffer; /**< (char *) Buffer used for the project. */
  Park **parks_array; /**< (Park **) Array containing pointers to Parks. */
  Date *last_event_date; /**< Tracks the date and time of the last event. */
} Context;

/* FUNCTION DECLARATIONS */

// main
int hasArguments(char *buffer);

// memory_handling
void allocFail(Context *context);
void freeAll(Context *context);
void freePark(Park *park);
void freeName(Park *park);
void freeCars(Park *park);
void freeEvents(Park *park);

// park
void handleP(Context *context);
int checkParkExists(char *name, Park **parks_array);
int checkParkFull(Park *park);
int validateEventDate(Date new, Date last_event);
void getParkName(char *name,char *buffer);
void copyParks(Park **parks_array, Park **temp_array);
int getParksArrayL(Park **parks_array);

// event
void handleEvent(Context *p_context);
void updateDate(Date *date, Date date2);
int validateLicence(char *licence);
int areDatesEqual(Date date1, Date date2);
unsigned int hashLicence(char *licence, int table_size);

// sort
void handleV(Context *context);
void parksort(Park *arr[], int len);

// fact
void handleF(Context *context);

//r
void handleR(Context *context);

#endif // End of conditional block.