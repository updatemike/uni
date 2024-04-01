#include <stdio.h>

int main() {
  int counter, N;
  float min, max, input;

  if(scanf("%d", &N) != 1) return -1;
  for(counter = 0; counter < N; counter++) {
    if(scanf("%f", &input) != 1) return -1;
    if(counter == 0) min = max = input;
    if(min>input) min = input;
    else if(max < input) max = input;
  }

  printf("min: %f, max: %f\n", (double)min, (double)max);

  return 0;
}