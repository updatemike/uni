#include <stdio.h>

#define IN_QUOTES -1
#define OUT_QUOTES -2

int isQuote(int ch);

int main() {
  char ch = 'a';
  int state = OUT_QUOTES;
  while(ch != '\n') {
    ch = getchar();
    if(isQuote(ch)) {
      state = state == IN_QUOTES ? OUT_QUOTES : IN_QUOTES;
      continue;
    }
    if(ch == ' ') {
      state == IN_QUOTES ? printf(" ") : printf("\n");
    }
    else printf("%c", ch);
  }

  return 0;
}

int isQuote(int ch) {
  return ch == '\"';
}