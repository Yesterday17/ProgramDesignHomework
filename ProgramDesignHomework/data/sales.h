#pragma once
#include "component.h"
#include "time.h"

typedef struct sales {
  Time time;
  Component component;
  bool sales_mode; // ����ģʽ��true��ʾ������false��ʾ���ۣ�
  int price;       // ���۵���
  int quantity;    // ��������
  int total;       // ��Ʒ�ܼ�
  char *customer;  //�ͻ���Ϣ
  Component gift;  //��Ʒ
} Sales;


#ifndef UNIT_TEST

Sales ReadSales();

#endif