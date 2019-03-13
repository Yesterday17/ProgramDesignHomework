#include "purchase.h"
#include <stdio.h>
#include "io.h"
#include "time.h"

Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  scanf("%d", &prime.price);                   //输入进货单价
  scanf("%d", &prime.quantity);                //输入进货数量
  prime.total = prime.price * prime.quantity;  //输入商品总价
  prime.retailer =
      InputString("please input retailer", "3021");  //输入进货供应商
  return prime;
}