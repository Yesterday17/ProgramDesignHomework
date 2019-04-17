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
LinkedList *purchase;//进货记录
LinkedList *sales;//售货记录
LinkedList *globalStorage = NULL;//库存链表
LinkedList* globalGift = NULL;//赠品链表

long globalFunds;
uint64_t salesFunds;
uint64_t purchaseFunds;