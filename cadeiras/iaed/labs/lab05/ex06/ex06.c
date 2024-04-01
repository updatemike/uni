#include <stdio.h>

typedef struct _date_ {
  int day;
  int month;
  int year;
} Date;

int main() {
  Date d1 = {0}, d2 = {0}, temp = {0};

  scanf("%d-%d-%d %d-%d-%d",
        &d1.day, &d1.month, &d1.year,
        &d2.day, &d2.month, &d2.year);

  if(d1.year > d2.year) {
    temp = d1;
    d1 = d2;
    d2 = temp;
  }
  else if(d1.year == d2.year) { 
    if(d1.month > d2.month) {
    temp = d1;
    d1 = d2;
    d2 = temp;
    }
    else if(d1.month == d2.month) {
      temp = d1;
      d1 = d2;
      d2 = temp;
    }
  }

  printf("%02d-%02d-%04d %02d-%02d-%04d\n",
          d1.day, d1.month, d1.year,
          d2.day, d2.month, d2.year);


  return 0;
}