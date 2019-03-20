#include "time.h"

bool prime(int a) {
  if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    return true;
  else
    return false;
}

bool mistake(int year, int month, int day, int hour, int minute, int second) {
  if ((year < 1970) || (month < 1) || (month > 12) || (day < 0) || (day > 31))
    return false;
  if ((hour < 0) || (hour > 24) || (minute < 0) || (minute > 60) ||
      (second < 0) || (second > 60))
    return false;
  if ((prime(year)) && (month == 2) && (day > 29)) return false;
  if ((prime(year)) && (month == 2) && (day > 28)) return false;
  return true;
}

uint64_t timemaking() {
  int counts = 0, i, j, k;
  int day31[7] = {1, 3, 5, 7, 8, 10, 12};
  int day30[4] = {4, 6, 9, 11};
  uint64_t time = 0;
  int flag;
  int year, month, day, hour, minute, second;
  printf("请输入时间（例：2019-03-20--14:42:38):");
  scanf("%d-%d-%d--%d:%d:%d", &year, &month, &day, &hour, &minute, &second);
  while (mistake(year, month, day, hour, minute, second) == false) {
    printf("输入错误 请重新输入！\n");
    printf("请输入时间（例：2019-03-20--14:42:38):");
    scanf("%d-%d-%d--%d:%d:%d", &year, &month, &day, &hour, &minute, &second);
  }

  for (i = 1970; i < year; i++) {
    if (prime(i))
      time = time + 366 * 24 * 60 * 60;
    else
      time = time + 365 * 24 * 60 * 60;
  }
  for (i = 1; i < month; i++) {
    flag = 0;
    if ((i == 2) && (!prime(year))) {
      time = time + 28 * 24 * 60 * 60;
    }
    if ((i == 2) && (prime(year))) {
      time = time + 29 * 24 * 60 * 60;
    }
    for (j = 0; j < 7; j++) {
      if (i == day31[j]) {
        time = time + 31 * 24 * 60 * 60;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (k = 0; k < 4; k++) {
        if (i == day30[k]) {
          time = time + 30 * 24 * 60 * 60;
          break;
        }
      }
    }
  }
  for (i = 1; i < day; i++) {
    time = time + i * 24 * 60 * 60;
  }
  for (i = 1; i < hour; i++) {
    time = time + i * 60 * 60;
  }
  for (i = 1; i < minute; i++) {
    time = time + i * 60;
  }
  time += second;

  return time;
}
