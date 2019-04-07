#pragma once
#include "time.h"
#include"component.h"
typedef struct {
  Component *prime;
  uint64_t time;
  int price;       // ��������
  int quantity;    // ��������
  int total;       //��Ʒ�ܼ�
  char *retailer;  //��Ʒ������
} Purchase;


#ifndef UNIT_TEST

Purchase* ReadPurchase();
Purchase* readjson_purchase(char *json_string, Purchase *purchase);

char* PrintPurchaseTitle();/*����\n*/
char* PrintPurchase(void* node, uint8_t id);/*����\n*/

#endif