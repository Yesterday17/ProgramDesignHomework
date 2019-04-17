#include <stdbool.h>

#ifndef _DATA_COMPONENT_H_
#define _DATA_COMPONENT_H_

#include "../cstring_jslike/cstring_jslike.h"
#include "../cJson/cJSON.h"
#include "../utils/linkedlist.h"

/**
 * 计算机配件 - 管理系统所管理物品
 */
typedef struct Component {
  int index;           // 索引
  string name;          // 配件名称
  string type;         // 配件型号
  string manufacturer;  // 制造商
} Component;

bool FindName_Component(LinkedListNode *node);
bool FindType_Component(LinkedListNode *node);
bool FindMan_Component(LinkedListNode *node);

Component *NewComponent();
void FreeComponent(Component* component);
int ReadComponent();
LinkedList* ReadComponentJSON(string filename);
Component *JSONToComponent(cJSON *root);
cJSON *ComponentToJSON(Component *prime);

extern Component* NO_Gift;
#endif