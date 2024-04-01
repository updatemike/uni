#include <stdio.h>

int main() {
  int N, counter = 0, sum = 0;

  scanf("%d", &N);
  while(N) {
    sum += N % 10;
    N /= 10;
    counter++;
  }

  printf("%d\n%d\n", counter, sum);

  return 0;
}