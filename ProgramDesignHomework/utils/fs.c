#include "fs.h"

/**
 * 判断文件是否存在
 * https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/access-waccess?view=vs-2017
 * @param fileName 文件名
 * @return
 */
bool FileExist(string fileName) { return (_access(CSTR(fileName), 04) != -1); }

// https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c
string ReadFile(string filename) {
  FILE *fp;
  if (fopen_s(&fp, U8_CSTR(filename), "r") != 0) {
    perror("Failed to open file!");
    exit(1);
  }

  long fileSize;

  fseek(fp, 0L, SEEK_END);
  fileSize = ftell(fp);
  rewind(fp);

  char* str = calloc(1, fileSize + 1);

  // auto numread = fread_s(str, fileSize, fileSize, 1, fp);
  fread(str, fileSize, 1, fp);
  string ans = newString(str);

  fclose(fp);
  free(str);
  return ans;
}

bool WriteFile(string fileName, char *content)
{
  FILE *fp = fopen(U8_CSTR(fileName), "w");
  if (fp == NULL) {
    return false;
  }

  fprintf(fp, "%s", content);
  fclose(fp);
  return true;
}
