#include <stdio.h>
#include <stdlib.h>
typedef struct item {
  int v;
} Item;

Item *createItem(int v) {
  Item *item = malloc(sizeof(Item));
  item->v = v;
  return item;
}

typedef struct node {
  Item *item;
  struct node *l;
  struct node *r;
} Node;

typedef Node *Link;

static Link head;

void init() {
  head = NULL;
}

Link createNode(Item *item, Link left, Link right) {
  Link new = malloc(sizeof(Node));
  new->item = item;
  new->l = left;
  new->r = right;
  return new;
}

Link search(Link h, int v) {
  if(h == NULL)
    return NULL;
  if(h->item->v)
    return h;
  if(v < h->item->v)
    return search(h->l, v);
  else 
    return search(h->r, v);
}

Link insert(Link h, Item *item) {
  if(h == NULL)
    return createNode(item, NULL, NULL);
  if(h->item->v == item->v)
    return h;
  if(item->v < h->item->v)
    h->l = insert(h->l, item);
  else
    h->r = insert(h->r, item);
  return h;
}

Link max(Link h) {
  while(h != NULL && h->r != NULL)
    h = h->r;
  return h;
}

Link min(Link h) {
  while(h != NULL && h->l != NULL)
    h = h->l;
  return h;
}

void print(Item *item) {
  printf("%d ", item->v);
}

void preOrder(Link h) {
  if(h == NULL)
    return;
  print(h->item);
  preOrder(h->l);
  preOrder(h->r);
}

void inOrder(Link h) {
  if(h == NULL)
    return;
  inOrder(h->l);
  print(h->item);
  inOrder(h->r);
}

void postOrder(Link h) {
  if(h == NULL)
    return;
  preOrder(h->l);
  preOrder(h->r);
  print(h->item);
}

Link delete(Link h, int v) {
  Link aux;
  if(h == NULL) return h;
  else if(v < h->item->v) h->l = delete(h->l, v);
  else if(v > h->item->v) h->r = delete(h->r, v);
  else {
    if(h->l != NULL && h->r != NULL) {
      Item *tmp = h->item;
      aux = max(h->l);
      h->item = aux->item;
      aux->item = tmp;
      h->l = delete(h->l, v);
    }
    else{
      aux = h;
      if(h->l == NULL && h->r == NULL) h = NULL;
      else if(h->l == NULL) h = h->r;
      else h = h->l;
      free(aux->item);
      free(aux);
    }
  }
  return h;
}

int count(Link h) {
  if(h == NULL) return 0;
  return count(h->l) + count(h->r) + 1;
}

int height(Link h) {
  int l, r;
  if(h == NULL) return 0;
  l = height(h->l);
  r = height(h->r);
  if(l > r) return l + 1;
  else      return r + 1;
}

//Main prog
int getNumber() {
  int i;
  printf("Type number: ");
  while(scanf("%d",&i) != 1) {
    
    printf("Type number: ");
  }
  return i;
}

static void getCommand() {
  int command = -1;
  int n;
  Item *item;
  Link node;
  while(command != 0) {
    n = 0; item = NULL; node = NULL;
    printf("1: Insert, 2: Remove, 3: Count, 4: Search, 5: Pre Order, 6: In Order, 7: Post Order, 0: quit.\n");
    printf("Input: ");
    scanf("%d", &command);
    switch(command) {
      case 1:
        n = getNumber();
        item = createItem(n);
        head = insert(head, item);
        break;
      case 2:
        n = getNumber();
        head = delete(head, n);
        break;
      case 3:
        n = count(head);
        printf("There are %d nodes.\n", n);
        break;
      case 4:
        n = getNumber();
        node = search(head, n);
        node == NULL ? printf("No such node.\n") : printf("Node found.\n");
        break;
      case 5:
        preOrder(head);
        printf("\n");
        break;
      case 6:
        inOrder(head);
        printf("\n");
        break;
      case 7:
        postOrder(head);
        printf("\n");
        break;
      case 0:
        break;
      default:
        printf("Invalid number.\n");
        break;
    }
  }
}

int main() {
  init();
  getCommand();
  printf("Exiting.\n");
  return 0;
}