﻿#include "time.h"
#include "../utils/io.h"

bool isPrime(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
  else
    return false;
}

bool IsTimeValid(int year, int month, int day, int hour, int minute, int second) {
  if ((year < 1970) || (month < 1) || (month > 12) || (day < 0) || (day > 31))
    return false;
  if ((hour < 0) || (hour > 24) || (minute < 0) || (minute > 60) ||
    (second < 0) || (second > 60))
    return false;
  if ((isPrime(year)) && (month == 2) && (day > 29)) return false;
  if ((isPrime(year)) && (month == 2) && (day > 28)) return false;
  return true;
}

//时间读取函数
uint64_t ReadTime() {
  int counts = 0, i, j, k;
  int day31[7] = { 1, 3, 5, 7, 8, 10, 12 };
  int day30[4] = { 4, 6, 9, 11 };
  uint64_t time = 0;
  int flag;
  int year, month, day, hour, minute, second;
  string str = InputString(LITERAL("请输入时间（例：2019-03-20--14:42:38):"), LITERAL("2019-03-20--14:42:38"));
  sscanf(U8_CSTR(str), "%d-%d-%d--%d:%d:%d", &year, &month, &day, &hour, &minute, &second);
  while (!IsTimeValid(year, month, day, hour, minute, second)) {
    PrintLITERAL("输入错误 请重新输入！\n");
    freeAssign(&str, InputString(LITERAL("请输入时间（例：2019-03-20--14:42:38):"), LITERAL("2019-03-20--14:42:38")));
    sscanf(U8_CSTR(str), "%d-%d-%d--%d:%d:%d", &year, &month, &day, &hour, &minute, &second);
  }

  for (i = 1970; i < year; i++) {
    if (isPrime(i))
      time = time + 366 * 24 * 60 * 60;
    else
      time = time + 365 * 24 * 60 * 60;
  }
  for (i = 1; i < month; i++) {
    flag = 0;
    if ((i == 2) && (!isPrime(year))) {
      time = time + 28 * 24 * 60 * 60;
    }
    if ((i == 2) && (isPrime(year))) {
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

//时间转换函数
string TimeToString(uint64_t time)
{
  int counts = 0, i, j, k;
  int day31[7] = { 1, 3, 5, 7, 8, 10, 12 };
  int day30[4] = { 4, 6, 9, 11 };
  uint64_t test = 0;
  int flag = 0;
  int year = 1970, month = 1, day = 1, hour = 0, minute = 0, second = 0;
  while (test < time)
  {
    flag = 1;
    if (isPrime(year))
    {
      test += 366 * 24 * 60 * 60;
      year++;
      flag = 2;
    }
    else
    {
      test += 365 * 24 * 60 * 60;
      year++;
      flag = 3;
    }
  }
  year--;
  if (flag == 2)
    test -= 366 * 24 * 60 * 60;
  if (flag == 3)
    test -= 365 * 24 * 60 * 60;
  month = 1;
  int flags = 1;
  while (time > test)
  {
    if ((month == 2) && (!isPrime(year))) {
      test = test + 28 * 24 * 60 * 60;
      month++;
      flags = 1;
    }
    else if ((month == 2) && (isPrime(year))) {
      test = test + 29 * 24 * 60 * 60;
      month++;
      flags = 2;
    }
    else {
      flag = 0;
      for (j = 0; j < 7; j++) {
        if (month == day31[j]) {
          test = test + 31 * 24 * 60 * 60;
          flag = 1;
          month++;
          flags = 3;
          break;
        }
      }
      if (flag == 0) {
        time = time + 30 * 24 * 60 * 60;
        month++;
        flags = 4;
        break;
      }
    }

  }
  month--;
  if (flags == 1)
    test -= 28 * 24 * 60 * 60;
  else if (flags == 2)
    test -= 29 * 24 * 60 * 60;
  else if (flags == 3)
    test -= 31 * 24 * 60 * 60;
  else if (flags == 4)
    test -= 30 * 24 * 60 * 60;
  while (test < time)
  {
    test += 24 * 60 * 60;
    day++;
  }
  day--;
  test -= 24 * 60 * 60;
  while (test < time)
  {
    test += 60 * 60;
    hour++;
  }
  hour--;
  test -= 60 * 60;
  while (test < time)
  {
    test += 60;
    minute++;
  }
  minute--;
  test -= 60;
  second = time - test;
  char str[200];
  sprintf(str, u8"%d年%d月%d日%d时%d分%d秒", year, month, day, hour, minute, second);
  return newString(str);
}
