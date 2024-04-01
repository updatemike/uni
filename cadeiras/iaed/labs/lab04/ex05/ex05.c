#include <stdio.h>

int leLinha(char s[]) {
  int count = 0;
  while(s[count] != '\0') count++;
  return count;
}


int main() {
  char string[100];
  fgets(string, 100, stdin);
  printf("%s", string);
  return 0;
}

void alternative() {
  int i = 0;
  char ch = 'a';
  char string[100];
  while(ch != '\n' && ch != EOF) {
    scanf("%c", &ch);
    string[i++] = ch;
  }
  printf("%s", string);
}