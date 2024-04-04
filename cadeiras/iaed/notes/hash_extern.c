#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int n;
  struct node *next;
} Node;

static int M;
static Node **table;

static void getCommand();
static void getSize();
int getNumber();
int searchList(Node *head, int n);
Node *insertList(Node *h, int n);
Node *removeList(Node *h, int n);
int countList(Node *h);
void printList(Node *h);

void init() {
  table = malloc(M*sizeof(Node *));
  for(int i = 0; i < M; i++) {
    table[i] = NULL;
  }
}

int hash(int i) {
  return i % M;
}

void searchHash() {
  int n = getNumber();
  int h = hash(n);
  searchList(table[h], n) ? printf("Number %d is in the table.\n", n) :
                            printf("Number %d is not in the table.\n", n);
}

void insertHash() {
  int n = getNumber();
  int h = hash(n);
  if(!searchList(table[h], n)){
    table[h] = insertList(table[h], n);
  }
}

void removeHash() {
  int n = getNumber();
  int h = hash(n);
  table[h] = removeList(table[h], n);
}

void countHash() {
  int count = 0;
  for(int i = 0; i < M; i++) {
    count += countList(table[i]);
  }
  printf("There are %d elements in the table.\n", count);
}

void printHash() {
  for(int i = 0; i < M; i++) {
    printList(table[i]);
  }
  printf("\n");
}

int main() {
  getSize();
  init();
  getCommand();
  printf("Exiting.\n");
  return 0;
}

static void getCommand() {
  int command = -1;
  while(command != 0) {
    printf("1: Insert, 2: Remove, 3: Count, 4: Search, 5: Print, 0: quit.\n");
    printf("Input: ");
    scanf("%d", &command);
    switch(command) {
      case 1:
        insertHash();
        break;
      case 2:
        removeHash();
        break;
      case 3:
        countHash();
        break;
      case 4:
        searchHash();
        break;
      case 5:
        printHash();
        break;
      case 0:
        break;
      default:
        printf("1: Insert, 2: Remove, 3: Count, 4: Search, 5: Print, 0: quit.\n");
        break;
    }
  }
}

static void getSize() {
  printf("Size of the hash table: ");
  while(scanf("%d", &M) != 1 && M < 1)
    printf("Plese insert a valid number: ");
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

//List
int searchList(Node *head, int n) {
  Node *h = head;
  while(h != NULL) {
    if(h->n == n)
      return h != NULL;
    else
      h = h->next;
  }
  return h != NULL;
}

Node *insertList(Node *h, int n) {
  Node *new = malloc(sizeof(Node));
  new->n = n;
  if(h)
    new->next = h;
  h = new;
  return h;
}

Node *removeList(Node *h, int n) {
  Node *curr = h, *prev = NULL;
  while(curr != NULL && curr->n != n) {
    prev = curr;
    curr = curr->next;
  }
  if(!curr)
    return h;
  if(!prev)
    return NULL;
  prev->next = curr->next;
  free(curr);
  return h;
}

int countList(Node *h) {
  int count = 0;
  Node *n = h;
  while(n != NULL) {
    count++;
    n = n->next;
  }
  return count;
}

void printList(Node *h) {
  Node *n = h;
  while(n != NULL) {
    printf("%d ", n->n);
    n = n->next;
  }
}
