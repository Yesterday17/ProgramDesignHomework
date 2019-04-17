#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdint.h>
#include "utils/linkedlist.h"
#include "cstring_jslike/cstring_jslike.h"
#include "data/component.h"

/**
 * 声明全局变量的头文件
 */

#define COMPONENT_FILENAME LITERAL("component.json")
#define SALES_FILENAME LITERAL("sales.json")
#define PURCHASE_FILENAME LITERAL("purchase.json")

extern const char NAME[];
extern const char VERSION[];

extern LinkedList* globalComponentLinkedList;
extern LinkedList* purchase;
extern LinkedList* sales;
extern LinkedList* globalStorage;
extern LinkedList* globalGift;

extern uint64_t salesFunds;
extern uint64_t purchaseFunds;
extern long globalFunds;

extern string nameToSearch;
extern uint64_t timeToSearchearly;
extern uint64_t timeToSearchlate;
extern Component* componentToSearch;
extern string customerToSearch;
extern string retailerToSearch;
extern string typeToSearch;
extern string manufacturerToSearch;

#endif