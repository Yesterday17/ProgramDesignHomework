#pragma once
#include "time.h"

typedef struct {
  Time time;
  int price;       // ��������
  int quantity;    // ��������
  int total;       //��Ʒ�ܼ�
  char *retailer;  //��Ʒ������
} Purchase;