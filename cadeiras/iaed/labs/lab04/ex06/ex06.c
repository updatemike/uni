#include <stdio.h>

#define UPPER 'A'-'a'

void maiusculas(char str[]);
int sLength(char str[]);

int main() {
  char string[100];
  fgets(string, 100, stdin);
  maiusculas(string);
  printf("%s", string);
}

void maiusculas(char str[]) {
  int i, len = sLength(str);
  for(i = 0; i < len; i++) {
    if( str[i] >= 'a' && str[i] <= 'z' ) 
      str[i] += UPPER;
  }
}

int sLength(char str[]) {
  int count = 0;
  while(str[count] != EOF && str[count] != '\n')
    count++;
  return count;
}

