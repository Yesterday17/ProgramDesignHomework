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
    input = InputString(comment, STRING("\n"));
  }
  return ans;
}

int InputInt(string comment) {
  return InputInteger(comment, STRING("Error inputing integer, retry please."), 0);
}

string InputStr(string comment) { return InputString(comment, STRING("")); }