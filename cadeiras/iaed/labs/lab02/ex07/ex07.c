#include <stdio.h>

int main() {
  int N, d, count = 0;

  scanf("%d", &N);
  for(d = N; d > 0; d--) {
    if(N % d == 0) count++;
  }

  printf("%d\n", count);

  return 0;
}