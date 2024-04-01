#include <stdio.h>

int absolute(int n);

int main() {
  int N, M, lin, col, n;

  scanf("%d", &N);
  for(lin = 1; lin <= N; lin++) {
    M = N + lin;
    for(col = 1; col < M; col++) {
      n = lin - absolute(N - col);
      if(col == M - 1) printf("%d\n", n);
      else if(n < 1) printf("  ");
      else printf("%d ", n);
    }
  }

  return 0;
}

int absolute(int n) {
  if(n < 0) return n * -1;
  else return n;
}