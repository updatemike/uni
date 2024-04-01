#include <stdio.h>

int main() {
  int N, count;
  float input, media = 0;

  scanf("%d", &N);
  for(count = 1; count <= N; count++) {
    scanf("%f", &input);
    media += input;
  }
  printf("%.2f\n", (double)(media / N));

  return 0;
}