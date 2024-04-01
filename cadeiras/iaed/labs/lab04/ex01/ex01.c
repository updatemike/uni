#include <stdio.h>

#define VECMAX 100

int main() {
  int n, n1, i, j, vec[VECMAX];

  scanf("%d", &n);
  if( n < 1 || n > VECMAX) return -1;

  for(i = 0; i < n; i++) {
    scanf("%d", &n1);
    vec[i] = n1;
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < vec[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}