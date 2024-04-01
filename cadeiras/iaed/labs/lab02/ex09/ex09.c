#include <stdio.h>

#define MIN_IN_HOUR 60
#define SEC_IN_MIN 60

int main() {
  int N, h, m, s;

  scanf("%d", &N);
  h = N / (SEC_IN_MIN * MIN_IN_HOUR);
  m = (N % (SEC_IN_MIN * MIN_IN_HOUR)) / SEC_IN_MIN;
  s = N - (h * (SEC_IN_MIN * MIN_IN_HOUR)) - (m * SEC_IN_MIN);

  printf("%02d:%02d:%02d\n", h, m, s);

  return 0;
}