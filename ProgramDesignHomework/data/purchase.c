#include "purchase.h"
#include "time.h"
#include"io.h"
Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  scanf("%d", &prime.price);                   //�����������
  scanf("%d", &prime.quantity);                //�����������
  prime.total = prime.price * prime.quantity;  //������Ʒ�ܼ�
  prime.retailer=InputString("please input retailer", "3021");  //���������Ӧ��
  return prime;
}