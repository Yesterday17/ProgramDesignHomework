#ifndef _UTILS_FS_H_
#define _UTILS_FS_H_

#include <io.h>
#include <stdio.h>
#include <stdlib.h>


int FileExist(const char* fileName);
char* ReadFile(char* filename);

#endif