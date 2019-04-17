#include "global.h"

/**
 * 定义全局变量的源文件
 */

const char NAME[] = "SALES_MANAGEMENT_SYSTEM";
const char VERSION[] = "0.0.1-SNAPSHOT";

string nameToSearch;
string customerToSearch;
string retailerToSearch;
string manufacturerToSearch;
string typeToSearch;
uint64_t timeToSearchearly;
uint64_t timeToSearchlate;
Component *componentToSearch = NULL;

LinkedList *globalComponentLinkedList;
LinkedList *purchase;
LinkedList *sales;
LinkedList *globalStorage;

long globalFunds;
uint64_t salesFunds;
uint64_t purchaseFunds;