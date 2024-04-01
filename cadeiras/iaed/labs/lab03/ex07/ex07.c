#include <stdio.h>

int isOp(int ch);
int isSpace(int ch);

int main() {
  int temp, n1 = 0, n2 = 0;
  char ch = 'a', op = '\0';

  while(ch != '\n') {
    ch = getchar();
    temp = ch - '0';

    if(ch == '\n') {
      n1 = op == '+' ? n1 + n2 : n1 - n2;
      printf("%d\n", n1);
      break;
    }
    if(!isOp(ch) && !isSpace(ch)) {
      n2 = n2 * 10 + temp;
    }
    if(isOp(ch)) {
      if(op == '\0') n1 += n2;
      else n1 = op == '+' ? n1 + n2 : n1 - n2;
      op = ch;
      n2 = 0;
    }
  }
  return 0;
}

int isOp(int ch) {
  return ch == '+' || ch == '-';
}

int isSpace(int ch) {
  return ch == ' ' || ch == '\n';
}