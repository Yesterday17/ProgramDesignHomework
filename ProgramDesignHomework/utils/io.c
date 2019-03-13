#include "io.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char* InputString(char* comment, char* defaultValue) {
  int len = 0, capability = 16;
  char c, *ans = malloc(capability * sizeof(char));

  // �����ʾ��Ϣ
  printf("%s: ", comment);
  c = getchar();

  // ����Ĭ��ֵ
  if (c == '\n') {
    return defaultValue;
  }

  // ������
  do {
    // ��������
    if (len == capability - 1) {
      capability *= 2;
      ans = realloc(ans, capability * sizeof(char));
    }
    ans[len] = c;
    len++;
    c = getchar();
  } while (c != '\n');

  // ���� \0
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