#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

void init();
int getNumber();


//Pilha
static Node *top;

Node *createNewNode(int n) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = n;
  return node;
}

int is_empty() {
  return top == NULL;
}

void insertTop() {
  int i = getNumber();
  Node *node = createNewNode(i);
  node->next = top;
  top = node;
}

void removeTop() {
  if(!top)
    return;
  Node *node = top;
  top = top->next;
  free(node);

}

void countTop() {
  int count = 0;
  if(!top) {
    printf("Amount: %d\n", count);
    return;
  }
  Node *node = top;
  while(node != NULL) {
    count++;
    node = node->next;
  }
  printf("Amount: %d\n", count);
}



void init() {
  top = NULL;
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

static void getCommand();

int main() {
  init();
  getCommand();
  printf("Exiting.\n");
  return 0;
}

static void getCommand() {
  int command = -1;
  while(command != 0) {
    printf("1: Insert, 2: Remove, 3: Count 0: quit.\n");
    scanf("%d", &command);
    switch(command) {
      case 1:
        insertTop();
        break;
      case 2:
        removeTop();
        break;
      case 3:
        countTop();
        break;
      case 0:
        break;
      default:
        printf("1: Insert, 2: Remove, 3: Count 0: quit.\n");
        break;
    }
  }
}