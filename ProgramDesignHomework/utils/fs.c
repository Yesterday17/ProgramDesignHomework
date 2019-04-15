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
  FILE *fp = fopen(U8_CSTR(filename), "r");
  if (!fp) {
    perror("Failed to open file!");
    exit(1);
  }

  long fileSize;

  fseek(fp, 0L, SEEK_END);
  fileSize = ftell(fp);
  rewind(fp);

  char* str = calloc(1, fileSize + 1);

  if (fread(str, fileSize, 1, fp) != 0u) {
    fclose(fp);
    fputs("entire read fails", stderr);
    exit(1);
  }
  string ans = newString(str);

  fclose(fp);
  free(str);
  return ans;
}