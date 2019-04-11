#ifndef _DATA_SALES_H_
#define _DATA_SALES_H_

#include <malloc.h>

#include "../cstring_jslike/cstring_jslike.h"
#include "component.h"
#include "time.h"

typedef struct sales {
  uint64_t time;
  Component* component;
  int  sales_mode; // ����ģʽ��1��ʾ������0��ʾ���ۣ�
  int price;       // ���۵���
  int quantity;    // ��������
  int total;       // ��Ʒ�ܼ�
  string customer;  //�ͻ���Ϣ
  Component* gift;  //��Ʒ
} Sales;

Sales* ReadSales();

string PrintSalesTitle();
string PrintSales(void* node, uint8_t id);

#endif