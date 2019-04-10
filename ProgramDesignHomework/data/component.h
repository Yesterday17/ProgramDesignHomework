 #pragma once

#include "../utils/linkedlist.h"
#include "../cJson/cJSON.h"

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

Component* ReadComponent();
Component* readjson_component(cJSON *root, Component *comp);

bool FindName_Component(LinkedListNode *node);
bool FindType_Component(LinkedListNode *node);
bool FindMan_Component(LinkedListNode *node);

#endif