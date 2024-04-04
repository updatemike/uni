#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int n;
} Node;

static int M;
static Node **table;

static void getCommand();
static int getSize();
int getNumber();

Node **init(int size) {
  M = size;
  Node **t = malloc(size*sizeof(Node *));
  for(int i = 0; i < size; i++) {
    t[i] = NULL;
  }
  return t;
}

int hash(int i) {
  return i % M;
}

int hash2(int i) {
  int h = 1 + 3 * i;
  if(h == M) h++;
  return h;
}

Node *createNode(int n) {
  Node *new = malloc(sizeof(Node));
  new->n = n;
  return new;
}

void searchHash() {
  int n = getNumber();
  int h = hash(n);
  int h2 = hash2(n);
  while(table[h] != NULL) {
    if(table[h]->n == n) {
      printf("Number %d is in the table.\n", n);
      return;
    }
    else h = (h + h2) % M;
  }
  printf("Number %d is not in the table.\n", n);
}

void insertHash(Node *node) {
  int h = hash(node->n);
  int h2 = hash2(node->n);
  while(table[h] != NULL)
    h = (h + h2) % M;
  table[h] = node;
}

/*After removing a node I'm rehashing everythign using a copy of my table.*/
void reHash() {
  Node **table_cpy = init(M);
  for(int i = 0; i < M; i++) {
    if(!table[i]) continue;
    table_cpy[i] = table[i];
    table[i] = NULL;
  }
  for(int i = 0; i < M; i++) {
    if(!table_cpy[i]) continue;
    insertHash(table_cpy[i]);
  }
  free(table_cpy);
}

void removeHash() {
  int n = getNumber();
  int h = hash(n);
  int h2 = hash2(n);
  while(table[h] != NULL) {
    if(table[h]->n == n) break;
    else h = (h + h2) % M;
  }
  if(table[h] == NULL) {
    printf("Number %d is not in the table.\n", n);
    return;
  }
  //Free the node and make room on the table 
  free(table[h]); 
  table[h] = NULL;
  //re-hash the rest of the table until you find an empty index
  reHash();
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
  int size = getSize();
  table = init(size);
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

static int getSize() {
  int size;
  printf("Size of the hash table: ");
  while(scanf("%d", &size) != 1 && size < 1)
    printf("Plese insert a valid number: ");
  return size;
}

int getNumber() {
  int i;
  printf("Type number: ");
  while(scanf("%d",&i) != 1) {
    
    printf("Type number: ");
  }
  return i;
}
