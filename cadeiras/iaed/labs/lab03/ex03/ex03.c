#include <stdio.h>

int main() {
  int N, lin, col;

  scanf("%d", &N);
  for(lin = 0; lin < N; lin++) {
    for(col = 0; col < N; col++) {
      if(col == lin || col == N - lin - 1) printf("*");
      else printf("-");
      if(col == N - 1) printf("\n");
      else printf(" ");
    }
  }
  return 0;
}