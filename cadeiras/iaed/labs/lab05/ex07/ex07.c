#include <stdio.h>

const int YEAR[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int LEAP_YEAR[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct _date_ {
  int day;
  int month;
  int year;
} Date;

int isLeap(int year);

int main() {
  Date date1 = {0}, date2 = {0};
  int last_day;
  scanf("%d-%d-%d", &date1.day, &date1.month, &date1.year);
  last_day = isLeap(date1.year) ? LEAP_YEAR[date1.month - 1]
                                : YEAR[date1.month - 1];
  date2 = date1;
  if(date1.day == last_day) {
    if(date1.month == 12) {
      date2.year++;
      date2.month = 1;
    } else {
      date2.month++;
    }
    date2.day = 1;
  }

  printf("%02d-%02d-%04d\n", date2.day, date2.month, date2.year);
  
  return 0;
}

int isLeap(int year) {
  return ((year % 4 == 0 && year % 100 != 0) 
          || year % 400 == 0);
}