#include <stdio.h>

int sLength(char *word) {
  int count = 0;
  while(word[count] != '\0') count++;
  return count;
}

int main() {
  char word[100];
  int len = 0, i, max;

  scanf("%99s", word);
  len = sLength(word);
  max = len / 2;
  for(i = 0; i < max; i++) {
    if(word[i] != word[max - i]) {
      printf("no\n");
      return 0;
    }
  }
  printf("yes\n");


  return 0;
}