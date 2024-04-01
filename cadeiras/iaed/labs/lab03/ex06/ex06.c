#include <stdio.h>

int main() {
  char ch;
  int value, sum = 0;
  while(ch != '\n') {
    ch = getchar();
    if(ch == '\n') {
      value % 9 == 0 ? printf("yes") : printf("no");
      printf("\n");
    } 
    else {
      value = ch - '0';
      sum += value;
    }
  }

  return 0;
}