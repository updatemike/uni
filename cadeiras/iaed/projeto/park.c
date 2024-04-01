/**
  File holding functions related to user command 'p' and other Park structure 
  related functions.

  @file park.c
  
  @author ist163484 - Michael Maycock
*/

/* HEADER FILE INCLUSIONS */

#include "project.h"

/* FUNCTION DECLARATIONS */

static void createPark(Context *context);
static void listParks(Park **parks_array);
static void getParkData(Park *p_park, char *buffer);
static int checkParkData(Park *p_park, Park **parks_array);
static Car **createCarArray(int max_cap);
static void addPark(Park **parks_array, Park *p_new_park);

/* FUNCTION DEFINITIONS */

/**
  Handles the 'p' command by either calling createPark if user input has 
  arguments other than the command, or calling listParks if there are no 
  additional arguments.

  @param context Pointer to the project context.
*/
void handleP(Context *context){
  hasArguments(context->buffer) ? createPark(context) 
  : listParks(context->parks_array);
}

/**
  Creates a new park based on the data provided by the user.
  If the input arguments are correct and there is space for a new park, 
  adds new park to park array.

  @param context Pointer to the project context.
*/
static void createPark(Context *context){
  Park *p_new_park = malloc(sizeof(Park));
  if(!p_new_park) allocFail(context);
  memset(p_new_park, 0, sizeof(Park));
  // Allocating and verifying memory. 
  p_new_park->name = malloc(strlen(context->buffer)*sizeof(char));
  if(!p_new_park->name){
    free(p_new_park);
    allocFail(context);
    exit(0);
  }
  // Get all data for new_park.
  getParkData(p_new_park, context->buffer);
  // Verify if the data for new_park is valid
  if(!checkParkData(p_new_park, context->parks_array)) {
    free(p_new_park->name);
    free(p_new_park);
    return;
  }
  // Create car array for new park
  p_new_park->car_array = createCarArray(p_new_park->max);
  if(!p_new_park->car_array) {
    free(p_new_park->name);
    free(p_new_park);
    allocFail(context);
    exit(0);
  }
  memset(p_new_park->car_array, 0, 
    HASH_TABLE_RESIZE(p_new_park->max) * sizeof(Car *));
  // If all verification passed, add new_park to parks_array
  addPark(context->parks_array, p_new_park);
}

/**
  Lists the parks stored in the provided array of park pointers.

  @param parks_array Pointer to an array of pointers to Park structures.
*/
static void listParks(Park **parks_array){
  int i = 0;
  for(i = 0; i < MAX_PARKS; i++) {
    if(!parks_array[i])
      return;
    else 
      printf("%s %d %d\n", parks_array[i]->name, parks_array[i]->max, 
      parks_array[i]->avail);
  }
}

/**
  Retrieves park data from the provided buffer and stores it in the given 
  park structure.

  @param p_park Pointer to the Park structure where the data will be stored.
  @param buffer Pointer to the character array containing the park data.
*/
static void getParkData(Park *p_park, char *buffer) {
  // If sscanf returns 5 then the park arguments have a name with "name"
  if(sscanf(buffer, "%*c \"%[^\"]\" %d %f %f %f ", p_park->name, 
  &p_park->max, &p_park->x, &p_park->y, &p_park->z) != 5)
    sscanf(buffer, "%*c %s %d %f %f %f ", p_park->name, &p_park->max,
    &p_park->x, &p_park->y, &p_park->z);
  // Available park available capacity is the same as max park capacity
  p_park->avail = p_park->max;
}

/**
  Checks the validity of the park data stored in the given park structure.

  @param p_park Pointer to the Park structure containing the park data to be 
                checked.
  @param parks_array Pointer to an array of pointers to Park structures for 
  checking name uniqueness.

  @return Returns TRUE if the park data is valid, FALSE otherwise.
*/
static int checkParkData(Park *p_park, Park **parks_array) {
  //Check if park name already exists in park_array
  if(checkParkExists(p_park->name, parks_array) != NO_PARK) {
    printf("%s: parking already exists.\n", p_park->name);
    return FALSE;
  }
  //Check max capacity
  if(p_park->max <= 0) {
    printf("%d: invalid capacity.\n", p_park->max);
    return FALSE;
  }
  //Check billing values
  if(p_park->x<=0||p_park->y<=0||p_park->z<=0||p_park->x>=p_park->y||
  p_park->x>=p_park->z||p_park->y>=p_park->z) {
    printf("invalid cost.\n");
    return FALSE;
  }
  return TRUE;
}

/**
  Checks if a park with the given name already exists in the array of park 
  pointers.

  @param name Pointer to the character array containing the name of the park 
  to be checked.
  @param parks_array Pointer to an array of pointers to Park structures.

  @return Returns the index of the park if it exists, or NO_PARK if it 
  doesn't.
*/
int checkParkExists(char *name, Park **parks_array) {
  int i;
  for(i = 0; i < MAX_PARKS; i++) {
    if(!parks_array[i])
      break;
    if(parks_array[i] && !strcmp(parks_array[i] -> name, name)) {
      return i;
    }
  }
  return NO_PARK;
}

/**
  Creates an array of car pointers with a size determined by resizing the 
  given maximum capacity.

  @param max The maximum capacity of the park.

  @return Returns a pointer to the newly created array of car pointers.
*/
static Car **createCarArray(int max) {
  Car **car_array = malloc(HASH_TABLE_RESIZE(max) * sizeof(Car *));
  return car_array;
}

/**
  Adds a new park to the array of park pointers.

  @param parks_array Pointer to an array of pointers to Park structures.
  @param p_new_park Pointer to the new Park structure to be added.
*/
static void addPark(Park **parks_array, Park *p_new_park) {
  int i;
  for(i = 0; i < MAX_PARKS; i++) {
    //if parks_array[i] == NULL, there is an empty position
    if(!parks_array[i]) {
      parks_array[i] = p_new_park;
      return;
    }
  }
  printf("too many parks.\n");
  free(p_new_park->name);
  free(p_new_park);
}

/**
  Checks if the given park is full.

  @param park Pointer to the Park structure to be checked.

  @return Returns 1 if the park is full, 0 otherwise.
*/
int checkParkFull(Park *park) {
  // If full returns 1, if not returns 0
  return !(park->avail);
}

/**
  Extracts the park name from the given buffer and stores it in the provided
  character array.

  @param name Pointer to the character array to store the park name.
  @param buffer Pointer to the character array containing the input buffer.
*/
void getParkName(char *name,char *buffer) {
  if(sscanf(buffer, "%*c \"%[^\"]\" ", name) != 1)
    sscanf(buffer, "%*c %s ", name);
}

/**
  Copies the contents of the parks array to a temporary array.

  @param parks_array Pointer to the array of pointers to Park structures 
  to be copied.
  @param temp_array Pointer to the array of pointers to Park structures to 
  store the copied data.
*/
void copyParks(Park **parks_array, Park **temp_array) {
  int i;
  for(i = 0; i < MAX_PARKS; i++) {
    if(!parks_array[i])
      break;
    temp_array[i] = parks_array[i];
  }
}

/**
  Calculates the length of an array of park pointers.

  @param parks_array Pointer to the array of pointers to Park structures.

  @return Returns the length of the parks array.
*/
int getParksArrayL(Park **parks_array) {
  int i, length = 0;
  for(i = 0; i < MAX_PARKS; i++) {
    if(!parks_array[i])
      break;
    length++;
  }
  return length;
}