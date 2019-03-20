#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <cstdio>

#ifndef UNIT_TEST

bool prime(int a);
bool mistake(int year, int month, int day, int hour, int minute, int second);
uint64_t timemaking();

#endif