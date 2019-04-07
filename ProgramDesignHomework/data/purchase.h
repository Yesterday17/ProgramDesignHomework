#pragma once
#include "time.h"
#include"component.h"
typedef struct {
  Component *prime;
  uint64_t time;
  int price;       // 进货单价
  int quantity;    // 进货数量
  int total;       //商品总价
  char *retailer;  //商品销售商
} Purchase;


#ifndef UNIT_TEST

Purchase* ReadPurchase();
Purchase* readjson_purchase(char *json_string, Purchase *purchase);

char* PrintPurchaseTitle();/*带上\n*/
char* PrintPurchase(void* node, uint8_t id);/*带上\n*/

#endif