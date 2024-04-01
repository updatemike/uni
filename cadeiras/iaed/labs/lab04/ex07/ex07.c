#include <stdio.h>

void apagaCaracter(char s[], char c);
int sLength(char s[]);

int main() {
  char str[100], c;
  fgets(str, 100, stdin);
  scanf("%c", &c);
  apagaCaracter(str, c);
  return 0;
}

void apagaCaracter(char s[], char c) {
  int i, len = sLength(s);
  for(i = 0; i < len; i++) {
    if(s[i] != c) printf("%c", s[i]);
  }
}

int sLength(char s[]) {
  int count = 0;
  while(s[count] != '\0') count++;
  return count;
}
