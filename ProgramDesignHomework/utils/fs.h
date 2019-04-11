#ifndef _UTILS_FS_H_
#define _UTILS_FS_H_

#include <io.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 文件读写相关函数封装
 */

int FileExist(const char *fileName);
char *ReadFile(char *filename);

#endif