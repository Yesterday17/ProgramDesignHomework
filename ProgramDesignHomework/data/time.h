#ifndef _DATA_TIME_H_
#define _DATA_TIME_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include"../cstring_jslike/cstring_jslike.h"

/**
 * 处理时间相关
 */

bool IsTimeValid(int year, int month, int day, int hour, int minute, int second);
uint64_t ReadTime();
string TimeToString(uint64_t time);

#endif