 #pragma once

#include "../utils/linkedlist.h"
#include"cJSON.h"

/**
 * �������� - ����ϵͳ��������Ʒ
 */
typedef struct {
  int index;           // ����
  char* name;          // �������
  char* type;         // ����ͺ�
  char* manufacturer;  // ������
} Component;


#ifndef UNIT_TEST

Component ReadComponent();
Component* readjson_component(cJSON *item, Compoment *comp);

#endif