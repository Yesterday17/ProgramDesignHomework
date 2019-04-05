#pragma once
#include "component.h"
#include "time.h"

typedef struct sales {
  uint64_t time;
  Component* component;
  int  sales_mode; // ����ģʽ��1��ʾ������0��ʾ���ۣ�
  int price;       // ���۵���
  int quantity;    // ��������
  int total;       // ��Ʒ�ܼ�
  char *customer;  //�ͻ���Ϣ
  Component* gift;  //��Ʒ
} Sales;


#ifndef UNIT_TEST

Sales* ReadSales();

void PrintSalesTitle();
char* PrintSales(void* node, uint8_t id);

#endif