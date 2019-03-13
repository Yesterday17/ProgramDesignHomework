#pragma once
#include "sales.h"
#include"time.h"
#include"component.h"


typedef struct sales {
	Time time;
	Component component;
	int price;       // ���۵���
	int quantity;    // ��������
	int total;      // ��Ʒ�ܼ�
	char *customer; //�ͻ���Ϣ
	Component gift; //��Ʒ
}Sales;

Sales ReadSales();