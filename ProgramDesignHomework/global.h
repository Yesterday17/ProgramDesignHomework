#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdint.h>
#include "utils/linkedlist.h"
#include "cstring_jslike/cstring_jslike.h"
#include "data/component.h"

/**
 * 声明全局变量的头文件
 */

extern const char NAME[];
extern const char VERSION[];

extern LinkedList* component;
extern LinkedList* purchase;
extern LinkedList* sales;

extern string nameToSearch;
extern uint64_t timeToSearch;
extern Component* componentToSearch;
extern string customerToSearch;
extern string retailerToSearch;
extern string typeToSearch;
extern string manufacturerToSearch;

#endif