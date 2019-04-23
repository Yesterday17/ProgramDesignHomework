/*
 * MIT License
 *
 * Copyright (c) 2019 Yesterday17 and ProgramDesignHomework contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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