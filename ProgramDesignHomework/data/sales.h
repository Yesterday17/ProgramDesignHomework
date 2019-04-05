#pragma once
#include "component.h"
#include "time.h"

typedef struct sales {
  uint64_t time;
  Component* component;
  int  sales_mode; // 销售模式（1表示批发，0表示零售）
  int price;       // 销售单价
  int quantity;    // 销售数量
  int total;       // 商品总价
  char *customer;  //客户信息
  Component* gift;  //赠品
} Sales;


#ifndef UNIT_TEST

Sales* ReadSales();

void PrintSalesTitle();
char* PrintSales(void* node, uint8_t id);

#endif