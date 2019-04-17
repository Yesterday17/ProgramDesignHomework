#ifndef _DATA_PURCHASE_H_
#define _DATA_PURCHASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cstring_jslike/cstring_jslike.h"
#include "component.h"
#include "time.h"

typedef struct Purchase {
  int component;
  uint64_t time;
  int price;       // 进货单价
  int quantity;    // 进货数量
  int total;       //商品总价
  string retailer;  //商品销售商
} Purchase;

Purchase *NewPurchase();
void FreePurchase(Purchase *purchase);
Purchase *ReadPurchase();
Purchase *JSONToPurchase(cJSON *root);
LinkedList* ReadPurchaseJSON(string filename);
bool WritePurchaseJSON(string filename);

string PrintPurchaseTitle();/*带上\n*/
string PrintPurchase(void *node, uint8_t id);/*带上\n*/
bool FindRetailer_Purchase(LinkedListNode *node);
bool FindTime_Purchase(LinkedListNode *node);
bool FindComponentName_Purchase(LinkedListNode *node);
bool FindComponentType_Purchase(LinkedListNode *node);
#endif