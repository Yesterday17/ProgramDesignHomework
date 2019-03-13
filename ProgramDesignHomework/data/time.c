#include "time.h"

Time ReadTime() {
  Time t0;
  printf("Month: ");
  scanf("%d", &t0.month);
  printf("\nDay: ");
  scanf("%d", &t0.day);
  printf("/nHour: ");
  scanf("%d", &t0.hour);
  printf("/nMinute: ");
  scanf("%d", &t0.minute);
  return t0;
}