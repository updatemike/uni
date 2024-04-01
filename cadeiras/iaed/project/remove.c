/**
  File holding functions related to user command 'r'.
  Handles validation of input and removal of a given Park.

  @file remove.c
  
  @author ist163484 - Michael Maycock
*/

#include "project.h"

/* FUNCTION DECLARATIONS */

static void deletePark(Park **parks_array, int park_id);
static void reorderParksArray(Park **parks_array, int park_id);
static void printParks(Park **array, int length);

/* FUNCTION DEFINITIONS */

/**
  Handles the 'r' command.
  Deletes a park from the parks array and prints the updated list of parks.

  @param context The context containing the parks array.
*/
void handleR(Context *context) {
  int park_id, length = getParksArrayL(context->parks_array);
  char name[strlen(context->buffer)];
  Park *temp_array[length];

  getParkName(name, context->buffer);

  park_id = checkParkExists(name, context->parks_array);
  if(park_id == NO_PARK) {
    printf("%s: no such parking.\n", name);
    return;
  }
  deletePark(context->parks_array, park_id);

  length = getParksArrayL(context->parks_array);
  copyParks(context->parks_array, temp_array);
  //Sorting of parks by park name
  parksort(temp_array, length);

  printParks(temp_array, length);
}

/**
  Deletes a park from the parks array.

  @param parks_array The array of parks.
  @param park_id The index of the park to be deleted.
*/
static void deletePark(Park **parks_array, int park_id) {
  Park *park = parks_array[park_id];
  // Free and delete all data inside the Park structure
  freeName(park);
  freeCars(park);
  freeEvents(park);
  free(park);
  reorderParksArray(parks_array, park_id);
}

/**
  Reorders the parks array after deleting a park.

  @param parks_array The array of parks.
  @param park_id The index of the park that was deleted.
*/
static void reorderParksArray(Park **parks_array, int park_id) {
  int i;
  for(i = park_id; i < MAX_PARKS; i++){
    if(i == MAX_PARKS - 1) {
      parks_array[i] = NULL;
      break;
    }
    parks_array[i] = parks_array[i+1];
  }
}

/**
  Prints the name of each park in the given array.

  @param array The array of parks to print.
  @param length The length of the array.
*/
static void printParks(Park **array, int length) {
  int i;
  for(i = 0; i < length; i++) {
    printf("%s\n", array[i]->name);
  }
}
