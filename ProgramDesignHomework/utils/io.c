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

#include "io.h"

string InputString(string comment, string defaultValue) {
  int len = 0, capability = 16;
  char buf[2];
  string ans = newSizedString(127);

  // 输出提示信息
  PrintString(comment);
  buf[0] = getchar();
  buf[1] = '\0';

  // 采用默认值
  if (buf[0] == '\n') {
    return cloneString(defaultValue);
  }

  // 有输入
  do {
    freeAssign(&ans, concat2(ans, STRING(buf)));
    buf[0] = getchar();
  } while (buf[0] != '\n');

  return ans;
}

int InputInteger(string comment, string errorMessage, int defaultValue) {
  string input = InputString(comment, STRING("\n"));
  int ans;

  if (compareString(input, STRING("\n")) == STRING_EQUAL) {
    return defaultValue;
  }

  while (sscanf(U8_CSTR(input), "%d", &ans) != 1) {
    printf("%s\n", U8_CSTR(errorMessage));
    $STR_BUF(input);
    freeAssign(&input, InputString(comment, STRING("\n")));
  }
  return ans;
}

int InputMoney(string comment, string errorMessage)
{
  string input = InputString(comment, "\n");
  int number = 0;
  char a, b;

  if (compareString(input, STRING("\n")) == STRING_EQUAL) {
    return 100000;
  }

  while (sscanf(U8_CSTR(input), "%d.%c%c", &number, &a, &b) != 3
    || a<'0' || a>'9' || b<'0' || b>'9') {
    PrintString(errorMessage);
    freeAssign(&input, InputString(comment, errorMessage, "\n"));
  }
  return number * 100 + ((a - '0') * 10) + (b - '0');
}

int InputInt(string comment) {
  return InputInteger(comment, STRING("Error inputing integer, retry please."), 0);
}

string InputStr(string comment) { return InputString(comment, STRING("")); }