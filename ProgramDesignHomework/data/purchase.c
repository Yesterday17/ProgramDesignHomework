#include "purchase.h"
#include <cstdio>
#include "io.h"
#include "time.h"

Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  prime.price = InputString("请输入进货单价","1");//输入进货单价
  prime.quantity=InputString("请输入进货数量","1");              //输入进货数量
  prime.total = prime.price * prime.quantity;  //输入商品总价
  prime.retailer =
      InputString("please input retailer", "3021");  //输入进货供应商
  return prime;
}