#include "fs.h"

// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/access-waccess?view=vs-2017
int FileExist(char* fileName) { return (_access(fileName, 04) != -1); }

// https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c
char* ReadFile(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    perror("Failed to open file!");
    exit(1);
  }

  char* buffer;
  long fileSize;

  fseek(fp, 0L, SEEK_END);
  fileSize = ftell(fp);
  rewind(fp);

  buffer = (char*)calloc(1, fileSize + 1);
  if (!buffer) {
    fclose(fp);
    fputs("memory alloc fails", stderr);
    exit(1);
  }

  if (1 != fread(buffer, fileSize, 1, fp)) {
    fclose(fp);
    free(buffer);
    fputs("entire read fails", stderr);
    exit(1);
  }
  fclose(fp);
  return buffer;
}