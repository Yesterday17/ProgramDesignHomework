#include "purchase.h"
#include "time.h"

Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  scanf("%d", &prime.price);                   //�����������
  scanf("%d", &prime.quantity);                //�����������
  prime.total = prime.price * prime.quantity;  //������Ʒ�ܼ�
  scanf("%s", &prime.retailer);                //���������Ӧ��
  return prime;
}