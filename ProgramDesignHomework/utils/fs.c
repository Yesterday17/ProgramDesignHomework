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
