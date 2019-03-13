#include "sales.h"

Sales ReadSales() {
  Sales prime;
  prime.time = ReadTime();
  printf("批发/零售价格：");  //批发零售价格
  scanf("%d", &prime.price);
  printf("批发/零售数量：");//批发/零售数量：
  scanf("%d", &prime.quantity);
  prime.total = prime.price * prime.quantity;
  prime.customer=InputString("please input customer：", "3021 bosses");
  ReadComponent();
  return prime;
}