#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LICENCE_SIZE 8

typedef struct _car_ {
  char *licence;
} Car;

typedef struct _node_ {
  Car *car;
  struct _node_ *next;
} Node;

typedef struct _node_list_ {
  Node *head, *tail;
} Node_List;

//Global variables
static Node_List node_list;
static Node *head;

//Init
static void init();

//Input
static void getCommand();
static char *getLicence();

//Node
static Node *createNode(Car *car);
static void freeNode(Node *node);

//Car
static Car *createCar(char *licence);
static void insertCarStart();
static void insertCarEnd();
static void removeCar();
static void findCar();
static void printCars();




int main() {
  init();
  getCommand();
  printf("Exiting.\n");
  return 0;
}

static void init() {
  node_list.head = NULL;
  node_list.tail = NULL;
  //Initiate head to show without a tail ofr adding to the end of linked list
  head = NULL;
}

static void getCommand() {
  int command = -1;
  while(command != 0) {
    printf("1: Insert car at start, 2: Insert Car at end, 3: Remove car," 
          "4: Find car, 5: Print car list, 0: quit.\n");
    scanf("%d", &command);
    switch(command) {
      case 1:
        insertCarStart();
        break;
      case 2:
        insertCarEnd();
        break;
      case 3:
        removeCar();
        break;
      case 4:
        findCar();
        break;
      case 5:
        printCars();
        break;
      case 0:
        break;
      default:
        printf("1: Insert car at start, 2: Insert Car at end, 3: Remove car," 
              "4: Find car, 5: Print car list\n");
        printf("1: Insert car, 2: Remove car, 3: Print car\n");
        break;
    }
  }
}

static char *getLicence() {
  char *licence = calloc(LICENCE_SIZE + 1, sizeof(char));
  printf("Insert your 8 digit licence (XX-XX-XX):");
  scanf("%8s", licence);
  return licence;
}

static Node *createNode(Car *car) {
  Node *node = calloc(1, sizeof(Node));
  node->car = car;
  return node;
}

static void freeNode(Node *node) {
  free(node->car->licence);
  free(node->car);
  free(node);
}


static Car *createCar(char *licence) {
  Car *car = calloc(1, sizeof(car));
  car->licence = licence;
  return car;
}

static void insertCarStart() {
  char *licence = getLicence();
  Car *car = createCar(licence);
  Node *node = createNode(car);
  if(!head)
    head = node;
  else {
    node->next = head;
    head = node;
  }
}
static void insertCarEnd() {
  char *licence = getLicence();
  Car *car = createCar(licence);
  Node *node = createNode(car);
  if(head == NULL)
    head = node;
  else {
    Node *h = head;
    while(h->next != NULL)
      h = h->next;
    h->next = node;
  }
}

static void removeCar() {
  char *licence = getLicence();
  Node *h = head, *prev = NULL;
  while(h != NULL && strcmp(h->car->licence, licence) != 0) {
    prev = h;
    h = h->next;    
  }
  if(h == NULL) {
    printf("No such car.\n");
    return;
  }
  else{
    if(prev == NULL) {
      head = NULL;
    }
    else {
      prev->next = h->next;
    }
    freeNode(h);
  }
}

static void findCar() {
  char *licence = getLicence();
  if(!head) {
    printf("No such car.\n");
    return;
  }
  else {
    Node *h = head;
    while(h != NULL && strcmp(h->car->licence, licence) != 0)
      h = h->next;
    h == NULL ? printf("No such car.\n") : printf("Car found.\n");
  }
}
static void printCars() {
  Node *h = head;
  while(h != NULL) {
    printf("%s\n", h->car->licence);
    h = h->next;
  }
}

