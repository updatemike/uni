#include <stdio.h>

#define VECMAX 100

int main() {
  int n, i, j, n1, vec[VECMAX], max = 0;
  scanf("%d", &n);
  if(n < 1 || n > VECMAX) return -1;

  for(i = 0; i < n; i++) {
    scanf("%d", &n1);
    vec[i] = n1;
    if(n1 > max) max = n1;
  }

  for(i = 0; i < max; i++) {
    for(j = 0; j < n; j++) {
      if(i <= vec[j] - 1) printf("*");
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}