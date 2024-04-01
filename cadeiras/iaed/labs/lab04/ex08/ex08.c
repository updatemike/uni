#include <stdio.h>

int sLength(char s[]);

int main() {
  char num1[101], num2[101];
  int i, len;
  scanf("%100s %100s", num1, num2);
  len = sLength(num1);
  for(i = 0; i < len; i++) {
    if(num1[i] == num2[i]) continue;
    else num1[i] > num2[i] ? printf("%s", num1) : printf("%s", num2);
  }
  printf("\n");

  return 0;
}

int sLength(char s[]) {
  int count = 0;
  while(s[count] != '\0') count++;
  return count;
}