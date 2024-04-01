#include <stdio.h>

typedef struct _stock_ {
  char nome[11]; //11 porque string tem que ter '\0' no fim.
  float valor;
  float rend;
} Stock;

int getBest(Stock *array, int n);

int main() {
  int N, best;

  scanf("%d", &N);
  Stock array[N];

  for(int i = 0; i < N; i++) {
    scanf("%10s %f %f", array[i].nome, &array[i].valor, &array[i].rend);
  }

  best = getBest(array, N);
  printf("%s %.2f %.2f\n", 
          array[best].nome, 
          (double)array[best].valor, 
          (double)array[best].rend);

  return 0;
}

int getBest(Stock *array, int n) {
  int best;
  float max = 0;

  for(int i = 0; i < n; i++) {
    if(array[i].rend > max) best = i;
  }
  return best;
}
