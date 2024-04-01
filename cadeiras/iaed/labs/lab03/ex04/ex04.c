#include <stdio.h>

#define NUMBER -2
#define NOT_NUMBER -1

int isSpace(int c);

int main() {
  char ch = 'a';
  int state = NOT_NUMBER;
  while(ch != '\n') {
    ch = getchar();
    if(isSpace(ch)) {
      if(state == NOT_NUMBER) printf("0");
      else state = NOT_NUMBER;
      printf("%c", ch);
    }
    else {
      if(ch == '0') {
        if(state == NOT_NUMBER) ;
        else printf("%c", ch);
      }
      else {
        printf("%c", ch);
        state = NUMBER;
      }
    }
  }
}

int isSpace(int c) {
  return (c == ' ');
}