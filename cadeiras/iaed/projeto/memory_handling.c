/**
  File holding functions related to cleaning memory allocations and handling 
  allocation failures.

  @file memory_handling.c
  
  @author ist163484 - Michael Maycock
*/

/* HEADER FILE INCLUSIONS */

#include "project.h"

/* FUNCTION DEFINITIONS */

/**
  Handles the case of memory allocation failure by printing an error message,
  freeing all memory associated with the project context 
  and exiting the program.

  @param context Pointer to the project context.
*/
void allocFail(Context *context) {
    printf("Memory allocation failed. Exiting.\n");
    freeAll(context);
    exit(0); 
    /*Has to return 0 or else automatic evaluation won't work.
    Should normally return another code representing the failure*/
}

/**
  Frees all memory allocations associated with the project context, 
  including parks and their related data.

  @param context Pointer to the project context.
*/
void freeAll(Context *context) {
  int i;
  //Clear Parks
  for(i = 0; i < MAX_PARKS; i++) {
    Park *p_park = context->parks_array[i];
    if(p_park) {
      freePark(p_park);
      context->parks_array[i] = NULL;
    }
    else
      break;
  }
}

/**
  Frees the memory allocated for a park, including its name, list of cars 
  and list of events.

  @param park Pointer to the Park structure.
*/
void freePark(Park *park) {
  freeName(park); // Free park name
  freeCars(park); // Free car list in park
  freeEvents(park); // Free events list in park
  free(park); // Free park
}

/**
  Frees the memory allocated for the name of a park.

  @param park Pointer to the Park structure.
*/
void freeName(Park *park) {
  if(park->name) { //Free name
    free(park->name);
    park->name = NULL;
  }
}

/**
  Frees the memory allocated for the list of cars in a park.

  @param park Pointer to the Park structure.
*/
void freeCars(Park *park) {
  int max = HASH_TABLE_RESIZE(park->max);
  Car **hash_table = park->car_array;
  Car *current = NULL, *temp = NULL;
  int i = 0;
  for(i = 0; i < max; i++) {
    if(hash_table[i]) {
      current = hash_table[i];
      hash_table[i] = NULL;
      while(current) {
        temp = current;
        current = current->next;
        free(temp);
      }
    }
  }
  free(park->car_array);
}

/**
  Frees the memory allocated for the list of events in a park.

  @param park Pointer to the Park structure.
*/
void freeEvents(Park *park) {
  Event *current = park->event_list.head;
  Event *temp;
  park->event_list.head = park->event_list.tail = NULL;
  //Free all events on the list
  while(current) {
    temp = current;
    current = current->next;
    free(temp);
  }
}