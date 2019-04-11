#ifndef _DATA_TIME_H_
#define _DATA_TIME_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * 处理时间相关
 */

bool prime(int a);
bool mistake(int year, int month, int day, int hour, int minute, int second);
uint64_t timemaking();

#endif