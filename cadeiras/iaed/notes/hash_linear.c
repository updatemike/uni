#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int n;
} Node;

static int M;
static Node **table;

static void getCommand();
static void getSize();
int getNumber();

void init() {
  table = malloc(M*sizeof(Node *));
  for(int i = 0; i < M; i++) {
    table[i] = NULL;
  }
}

int hash(int i) {
  return i % M;
}

Node *createNode(int n) {
  Node *new = malloc(sizeof(Node));
  new->n = n;
  return new;
}

void searchHash() {
  int n = getNumber();
  int h = hash(n);
  for(int i = 0; i < M; i++) {
    if(table[h]->n == n) {
      printf("Number %d is in the table.\n", n);
      return;
    }
  }
  printf("Number %d is not in the table.\n", n);
}

void insertHash(Node *node) {
  int h = hash(node->n);
  while(table[h] != NULL)
    if(h == M - 1) h = 0; //If last index, goes back to index 0
    else h++;
  table[h] = node;
}

/*After removing a node you have to re-add all adjacent nodes until you find
and empty index.*/
void reHash(int n) {
  for(int i = (n + 1) % M; table[i] != NULL; i = (i + 1) % M) {
    Node *node = table[i];
    table[i] = NULL;
    insertHash(node);
  }
}

void removeHash() {
  int n = getNumber();
  int h = hash(n);
  while(table[h] != NULL) {
    if(table[h]->n == n) break;
    else h = (h + 1) % M;
  }
  if(table[h] == NULL) {
    printf("Number %d is not in the table.\n", n);
    return;
  }
  //Free the node and make room on the table 
  free(table[h]); 
  table[h] = NULL;
  //re-hash the rest of the table until you find an empty index
  reHash(h);
}

void countHash() {
  int count = 0;
  for(int i = 0; i < M; i++) {
    if(table[i]) count++;
  }
  printf("There are %d elements in the table.\n", count);
}

void printHash() {
  for(int i = 0; i < M; i++) {
    if(table[i]) printf("| %d |", table[i]->n);
    else printf("| NULL |");
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
  int n;
  Node *node;
  while(command != 0) {
    printf("1: Insert, 2: Remove, 3: Count, 4: Search, 5: Print, 0: quit.\n");
    printf("Input: ");
    scanf("%d", &command);
    switch(command) {
      case 1:
        n = getNumber();
        node = createNode(n);
        insertHash(node);
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
        printf("Invalid number.\n");
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
    
    printf("Type number: ");
  }
  return i;
}
