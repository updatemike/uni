#include <stdio.h>

typedef struct _complexo_ {
  float real;
  float imag;
} Complexo;

int main() {
  Complexo c1, c2;

  scanf("%f+%fi", &c1.real, &c1.imag);
  scanf("%f+%fi", &c2.real, &c2.imag);

  printf("%.2f+%.2f\n", 
          (double)(c1.real + c2.real), (double)(c1.imag + c2.imag));

  return 0;
}