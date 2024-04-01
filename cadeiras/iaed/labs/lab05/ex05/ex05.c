#include <stdio.h>

typedef struct _hora_ {
  int h;
  int m;
} Hora;

#define MIN_IN_HOUR 60
#define HOUR_IN_DAY 24

int main() {
  Hora total, hora1, hora2;

  scanf("%d:%d %d:%d", &hora1.h, &hora1.m, &hora2.h, &hora2.m);
  total.h = (hora1.h + hora2.h + 
            (hora1.m + hora2.m) / MIN_IN_HOUR) 
            % HOUR_IN_DAY;
  total.m = (hora1.m + hora2.m) % MIN_IN_HOUR;

  printf("%02d:%02d\n", total.h, total.m);

  return 0;
}