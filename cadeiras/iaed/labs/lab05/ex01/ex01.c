#include <stdio.h>

#define ALUNOS 10
#define DISCIPLINAS 5

int melhor_disciplina(int valores[ALUNOS][DISCIPLINAS]);
int melhor_aluno(int valores[ALUNOS][DISCIPLINAS]);

int main() {
  int valores[ALUNOS][DISCIPLINAS] = {0};
  int N, A, D, V;

  scanf("%d", &N);
  while(N > 0) {
    scanf("%d %d %d", &A, &D, &V);
    valores[A][D] = V;
    N--;
  }

  printf("%d\n%d\n", 
          melhor_disciplina(valores),
          melhor_aluno(valores)
        );

  return 0;
}

int melhor_disciplina(int valores[ALUNOS][DISCIPLINAS]) {
  int i, j, sum, max = 0, res;

  for(j = 0; j < DISCIPLINAS; j++) {
    sum = 0;
    for(i = 0; i < ALUNOS; i++) {
      sum += valores[i][j];
    }
    if(sum > max) {
      max = sum;
      res = j;
    }
  }
  return res;
}

int melhor_aluno(int valores[ALUNOS][DISCIPLINAS]) {
  int i, j, sum, max = 0, res;

  for(i = 0; i < ALUNOS; i++) {
    sum = 0;
    for(j = 0; j < DISCIPLINAS; j++) {
      sum += valores[i][j];
    }
    if(sum > max) {
      max = sum;
      res = i;
    }
  }
  return res;
}