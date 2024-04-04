#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

static Node *head;

static void getCommand();

void init() {
  head = NULL;
}

int getNumber() {
  int i;
  printf("Type number: ");
  while(scanf("%d",&i) != 1) {
    printf("Invalid number.\n");
    printf("Type number: ");
  }
  return i;
}

Node *createNewNode(int n) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = n;
  return node;
}

void insertStart() {
  int i = getNumber();
  Node *node = createNewNode(i);
  node->next = head;
  head = node;
}

void insertEnd() {
  int i = getNumber();
  Node *node = createNewNode(i);
  if(!head)
    head = node;
  else {
    Node *h = head;
    while(h->next != NULL)
      h = h->next;
    h->next = node;
  }
}

//In this case removes all nodes = i;
void removeNum() {
  int i = getNumber();
  Node *h = head, *prev = NULL;
  while(h != NULL) {
    if(h->value == i) {
      if(!prev) {
        head = head->next;
        free(h);
        h = head;
      }
      else {
        prev->next = h->next;
        free(h);
        h = prev->next;
      }
    }
    else {
      prev = h;
      h = h->next;
    }
  }
}

Node *find() {
  int i = getNumber();
  Node *h = head;
  while(h != NULL && h->value != i)
    h = h->next;
  return h;
}

void print() {
  Node *h = head;
  if(!h)
    printf("List is empty!\n");
  else {
    while(h->next != NULL) {
      printf("%d, ", h->value);
      h = h->next;
    }
    printf("%d.\n", h->value);
  }
}

int main() {
  init();
  getCommand();
  printf("Exiting.\n");
  return 0;
}

static void getCommand() {
  int command = -1;
  Node *n = NULL;
  while(command != 0) {
    printf("1: Insert at start, 2: Insert at end, 3: Remove, " 
          "4: Find, 5: Print number list, 0: quit.\n");
    scanf("%d", &command);
    switch(command) {
      case 1:
        insertStart();
        break;
      case 2:
        insertEnd();
        break;
      case 3:
        removeNum();
        break;
      case 4:
        n = find();
        if(n == NULL)
          printf("No matchning number found.\n");
        else
          printf("Number found\n");
        break;
      case 5:
        print();
        break;
      case 0:
        break;
      default:
        printf("1: Insert at start, 2: Insert at end, 3: Remove, " 
              "4: Find, 5: Print number list, 0: quit.\n");
        break;
    }
  }
}