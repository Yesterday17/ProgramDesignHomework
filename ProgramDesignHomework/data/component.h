/*
 * MIT License
 *
 * Copyright (c) 2019 Yesterday17 and ProgramDesignHomework contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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