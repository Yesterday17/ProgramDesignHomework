#pragma once
#include "time.h"
#include"component.h"
typedef struct {
  Component prime;
  Time time;
  int price;       // ��������
  int quantity;    // ��������
  int total;       //��Ʒ�ܼ�
  char *retailer;  //��Ʒ������
} Purchase;


#ifndef UNIT_TEST

Purchase ReadPurchase();

#endif