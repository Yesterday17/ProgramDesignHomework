#include <stdbool.h>

#ifndef _DATA_COMPONENT_H_
#define _DATA_COMPONENT_H_

#include "../cstring_jslike/cstring_jslike.h"
#include "../cJson/cJSON.h"
#include "../utils/linkedlist.h"

/**
 * �������� - ����ϵͳ��������Ʒ
 */
typedef struct {
  int index;           // ����
  string name;          // �������
  string type;         // ����ͺ�
  string manufacturer;  // ������
} Component;

Component* ReadComponent();
Component* readjson_component(cJSON *root, Component *comp);

bool FindName_Component(LinkedListNode *node);
bool FindType_Component(LinkedListNode *node);
bool FindMan_Component(LinkedListNode *node);

#endif