#include "sales.h"

Sales ReadSales() {
  Sales prime;
  prime.time = ReadTime();
  printf("����/���ۼ۸�");  //�������ۼ۸�
  scanf("%d", &prime.price);
  printf("����/����������");//����/����������
  scanf("%d", &prime.quantity);
  prime.total = prime.price * prime.quantity;
  prime.customer=InputString("please input customer��", "3021 bosses");
  ReadComponent();
  return prime;
}