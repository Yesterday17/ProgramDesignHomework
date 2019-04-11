#ifndef _DATA_PURCHASE_H_
#define _DATA_PURCHASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cstring_jslike/cstring_jslike.h"
#include "component.h"
#include "time.h"

typedef struct {
  Component *prime;
  uint64_t time;
  int price;       // ��������
  int quantity;    // ��������
  int total;       //��Ʒ�ܼ�
  string retailer;  //��Ʒ������
} Purchase;

Purchase* ReadPurchase();
Purchase* readjson_purchase(char *json_string, Purchase *purchase);

string PrintPurchaseTitle();/*����\n*/
string PrintPurchase(void* node, uint8_t id);/*����\n*/
bool FindTime_Purchase(LinkedListNode *node);

#endif