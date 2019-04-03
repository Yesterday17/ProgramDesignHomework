 #pragma once

#include "../utils/linkedlist.h"
#include"cJSON.h"

/**
 * 计算机配件 - 管理系统所管理物品
 */
typedef struct {
  int index;           // 索引
  char* name;          // 配件名称
  char* type;         // 配件型号
  char* manufacturer;  // 制造商
} Component;


#ifndef UNIT_TEST

Component ReadComponent();
Component* readjson_component(cJSON *item, Compoment *comp);

#endif