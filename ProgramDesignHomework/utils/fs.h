#ifndef _UTILS_FS_H_
#define _UTILS_FS_H_

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include "../cstring_jslike/cstring_jslike.h"

/**
 * 文件读写相关函数封装
 */

bool FileExist(string fileName);
string ReadFile(string filename);

#endif