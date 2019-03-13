#pragma once
#include "component.h"
#include "sales.h"
#include "time.h"

typedef struct sales {
  Time time;
  Component component;
  int price;       // 销售单价
  int quantity;    // 销售数量
  int total;       // 商品总价
  char *customer;  //客户信息
  Component gift;  //赠品
} Sales;


#ifndef UNIT_TEST

Sales ReadSales();

#endif