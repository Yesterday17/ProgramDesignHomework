#include "io.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

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

char* InputStr(char* comment) { return InputString(comment, ""); }