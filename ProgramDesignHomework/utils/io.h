#ifndef _UTILS_IO_H_
#define _UTILS_IO_H_

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "../cstring_jslike/cstring_jslike.h"

string InputString(string comment, string defaultValue);
int InputInteger(string comment, string errorMessage, int defaultValue);

string InputStr(string comment);
int InputInt(string comment);

#define PrintString(str) printf("%s", CSTR(str))
#define PrintLITERAL(str) printf("%s", CSTR(LITERAL(str)))

#endif