#include "purchase.h"
#include <cstdio>
#include "io.h"
#include "time.h"

Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  prime.price = InputString("�������������","1");//�����������
  prime.quantity=InputString("�������������","1");              //�����������
  prime.total = prime.price * prime.quantity;  //������Ʒ�ܼ�
  prime.retailer =
      InputString("please input retailer", "3021");  //���������Ӧ��
  return prime;
}