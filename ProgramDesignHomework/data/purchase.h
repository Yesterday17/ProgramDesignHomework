#pragma once
#include "time.h"

typedef struct {
  Time time;
  int price;       // 进货单价
  int quantity;    // 进货数量
  int total;       //商品总价
  char *retailer;  //商品销售商
} Purchase;


#ifndef UNIT_TEST

Purchase ReadPurchase();

#endif