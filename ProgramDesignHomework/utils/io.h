#ifndef _UTILS_IO_H_
#define _UTILS_IO_H_

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "../cstring_jslike/cstring_jslike.h"

/**
 * 控制台输入输出相关函数
 */

string InputString(string comment, string defaultValue);
int InputInteger(string comment, string errorMessage, int defaultValue);
int InputMoney(string comment, string errorMessage);

string InputStr(string comment);
int InputInt(string comment);

#define PrintString(str) printf(U8_CSTR(str))
#define PrintLITERAL(str) printf(U8_CSTR(LITERAL(str)))
#define NewLine() printf("\n")

#endif