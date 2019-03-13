#include "io.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char* InputString(char* comment, char* defaultValue) {
  int len = 0, capability = 16;
  char c, *ans = malloc(capability * sizeof(char));

  // 输出提示信息
  printf("%s: ", comment);
  c = getchar();

  // 采用默认值
  if (c == '\n') {
    return defaultValue;
  }

  // 有输入
  do {
    // 容量已满
    if (len == capability - 1) {
      capability *= 2;
      ans = realloc(ans, capability * sizeof(char));
    }
    ans[len] = c;
    len++;
    c = getchar();
  } while (c != '\n');

  // 加入 \0
  if (len == capability - 1) {
    capability++;
    ans = realloc(ans, capability * sizeof(char));
  }
  ans[len] = '\0';
  return ans;
}

int InputInteger(char* comment, char* errorMessage, int defaultValue) {
  char* input = InputString(comment, "\n");
  int ans;

  if (strcmp(input, "\n") == 0) {
    return defaultValue;
  }

  while (sscanf(input, "%d", &ans) != 1) {
    printf("%s\n", errorMessage);
    free(input);
    input = InputString(comment, "\n");
  }
  return ans;
}

int InputInt(char* comment) { return InputInteger(comment, "Error inputing integer, retry please.", 0); }

char* InputStr(char* comment) { return InputString(comment, ""); }