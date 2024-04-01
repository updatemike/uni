/**
  File holding the main function and some functions to handle the user input.

  @file main.c
  
  @author ist163484 - Michael Maycock
*/

/* HEADER FILE INCLUSIONS */

#include "project.h"

/* FUNCTION DECLARATIONS */

static Context createContext(char* buffer, Park **parks_array, 
                              Date *last_event_date);
static char getInput(char *buffer);
static void handleInput(char command, Context *context);

/* FUNCTION DEFINITIONS */

/**
  Initializes project variables char buffer[], char command, 
  Park *parks_array[] and Date last_event_date.
  Wraps variables in a project context.

  This function reads input commands from the buffer until the command 'q' is 
  entered.
  Each command is handled by the handleInput() function.

  @return Always returns 0
*/
int main() {
  char buffer[BUFFER_SIZE*sizeof(char)] = {'\0'};
  char command = '\0';
  Park *parks_array[MAX_PARKS] = {NULL};
  Date last_event_date = {0};
  Context app_context = createContext(buffer, parks_array, &last_event_date); 
  // Read input from the buffer until the command 'q' is entered.
  while(command != 'q') {
    command = getInput(buffer);
    handleInput(command, &app_context);
  }
  // At program end, free all allocated memory.
  freeAll(&app_context);

  return 0;
}

/**
  Creates a new context for the project with the provided buffer, parks_array 
  and last_event_date pointers.

  @param buffer Pointer to the character array buffer used for inputs.
  @param parks_array Pointer to an array of pointers to Park structures.
  @param last_event_date Pointer to a Date structure representing the last 
  event date.

  @return Returns a Context structure initialized with the provided pointers.
*/
static Context createContext(char* buffer, Park **parks_array, 
Date *last_event_date) {
  Context new_context;
  new_context.buffer = buffer;
  new_context.parks_array = parks_array;
  new_context.last_event_date = last_event_date;
  return new_context;
}

/**
  Reads the input from INPUT_STREAM and stores it in the provided buffer.

  @param buffer Pointer to the character array buffer where the input will be 
  stored.

  @return Returns the first character read from the input stream.
*/
static char getInput(char *buffer) {
  fgets(buffer, BUFFER_SIZE, INPUT_STREAM);
  return buffer[0];
}

/**
   Handles input commands based on the provided command character.

   @param command The command character to be handled.
   @param context Pointer to the project context.
*/
static void handleInput(char command, Context *context) {
  switch(command) {
    case 'q':
      return;
    case 'p':
      handleP(context);
      break;
    case 'e':
      handleEvent(context);
      break;
    case 's':
      handleEvent(context);
      break;
    case 'v':
      handleV(context);
      break;
    case 'f':
      handleF(context);
      break;
    case 'r':
      handleR(context);
      break;
    default:
      break;
  }
}

/**
  Checks if the given buffer contains additional arguments beyond the command.

  @param buffer Pointer to the character array containing the input buffer.

  @return Returns 1 if additional arguments exist, 0 otherwise.
*/
int hasArguments(char *buffer) {
  char ch;
  return sscanf(buffer, "%*c %c", &ch) == 1;
}

