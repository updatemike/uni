#include <stdio.h>

void quadrado(int N);

int main() {
  int N;
  
  scanf("%d", &N);
  quadrado(N);

  return 0;
}

void quadrado(int N) {
  int i;
  for(i = 1; i <= N; i++) {
    int j, max = i + 4;
    for(j = i; j <= max; j++) {
      if(j == max) printf("%d\n", j);
      else printf("%d\t", j);
    }
  }
}
