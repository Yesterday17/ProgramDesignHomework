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

#include "component.h"

#include "../global.h"
#include "../utils/io.h"
#include "../utils/fs.h"

Component* NO_Gift = NULL;

Component * NewComponent()
{
  Component *component = (Component*)malloc(sizeof(Component));
  component->index = -1;
  component->manufacturer = newString(u8"UNKNOWN");
  component->name = newString(u8"UNKNOWN");
  component->type = newString(u8"UNKNOWN");
  return component;
}

void FreeComponent(Component * component)
{
  $STR_BUF(component->manufacturer);
  $STR_BUF(component->name);
  $STR_BUF(component->type);
  free(component);
}

/**
 * 从控制台读取数据
 * @return Component*
 */
int ReadComponent() {
  int len = 0;
  LinkedList *nameSearch, *typeSearch, *manufacturerSearch;
  LinkedListNode *node;
  int *idMap, *idMap2, *idMap3;

  do {
    freeAssign(&nameToSearch, InputString(LITERAL("配件名称:"), LITERAL("GTX")));
    nameSearch = FindLinkedList(globalComponentLinkedList, FindName_Component);
    len = LengthLinkedList(nameSearch);

    idMap = (int*)malloc(sizeof(int) * len);
    node = nameSearch->top;
    for (int i = 0; i < len && node != NULL; i++, node = node->next) {
      idMap[i] = ((LinkedListResult*)(node->data))->count - 1;
    }
  } while (len < 1);
  if (len == 1) {
    int ans = idMap[0];
    FreeLinkedList(nameSearch);
    free(idMap);
    return ans;
  }

  do {
    freeAssign(&typeToSearch, InputString(LITERAL("配件类型:"), LITERAL("GTX-1080")));
    typeSearch = FindLinkedList(MapLinkedList(nameSearch, UnpackLinkedListResult), FindType_Component);
    len = LengthLinkedList(typeSearch);

    idMap2 = (int*)malloc(sizeof(int) * len);
    node = typeSearch->top;
    for (int i = 0; i < len && node != NULL; i++, node = node->next) {
      idMap2[i] = idMap[((LinkedListResult*)(node->data))->count - 1];
    }
  } while (len < 1);
  if (LengthLinkedList(typeSearch) == 1) {
    int ans = idMap2[0];
    FreeLinkedList(nameSearch);
    FreeLinkedList(typeSearch);
    free(idMap);
    free(idMap2);
    return ans;
  }

  do {
    freeAssign(&manufacturerToSearch, InputString(LITERAL("制造商："), LITERAL("NVIDIA")));
    manufacturerSearch = FindLinkedList(MapLinkedList(typeSearch, UnpackLinkedListResult), FindMan_Component);
    len = LengthLinkedList(manufacturerSearch);

    idMap3 = (int*)malloc(sizeof(int) * len);
    node = manufacturerSearch->top;
    for (int i = 0; i < len && node != NULL; i++, node = node->next) {
      idMap3[i] = idMap2[((LinkedListResult*)(node->data))->count - 1];
    }
  } while (len < 1);
  if (LengthLinkedList(manufacturerSearch) == 1) {
    int ans = idMap3[0];
    FreeLinkedList(nameSearch);
    FreeLinkedList(typeSearch);
    FreeLinkedList(manufacturerSearch);
    free(idMap);
    free(idMap2);
    free(idMap3);
    return ans;
  }

  return -1;
}

/**
 * 判断链表节点是否与 name 匹配的回调函数
 * @param node
 * @return
 */
bool FindName_Component(LinkedListNode *node) {
  return compareString(((Component*)(node->data))->name, nameToSearch) == STRING_EQUAL;
}

/**
 * 判断链表节点是否与 Component 类型匹配的回调函数
 * @param node
 * @return
 */
bool FindType_Component(LinkedListNode *node) {
  return compareString(((Component *)node->data)->type, typeToSearch) == STRING_EQUAL;
}

/**
 * 判断链表节点是否与 manufacturer 匹配的回调函数
 * @param node
 * @return
 */
bool FindMan_Component(LinkedListNode *node) {
  return compareString(((Component *)node->data)->manufacturer, manufacturerToSearch) == STRING_EQUAL;
}

/**
 * 从 Json 读取数据
 * @param root
 * @param comp
 * @return
 */
Component* JSONToComponent(cJSON *root)
{
  Component *comp = NewComponent();

  cJSON* item = cJSON_GetObjectItem(root, "index");
  if (item != NULL)
  {
    comp->index = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "name");
  if (item != NULL)
  {
    freeAssign(&comp->name, newString(item->valuestring));
  }

  item = cJSON_GetObjectItem(root, "type");
  if (item != NULL)
  {
    freeAssign(&comp->type, newString(item->valuestring));
  }

  item = cJSON_GetObjectItem(root, "manufacturer");
  if (item != NULL)
  {
    freeAssign(&comp->manufacturer, newString(item->valuestring));
  }

  return comp;
}
cJSON *ComponentToJSON(Component *prime)
{
  cJSON * root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "index", cJSON_CreateNumber(prime->index));//根节点下添加
  cJSON_AddItemToObject(root, "name", cJSON_CreateString(U8_CSTR(prime->name)));
  cJSON_AddItemToObject(root, "type", cJSON_CreateString(U8_CSTR(prime->type)));
  cJSON_AddItemToObject(root, "manufacturer", cJSON_CreateString(U8_CSTR(prime->manufacturer)));
  return root;
}

LinkedList* ReadComponentJSON(string filename)
{
  LinkedList *list = CreateLinkedList();
  if (FileExist(filename))
  {
    string content = ReadFile(filename);
    cJSON * root = cJSON_Parse(U8_CSTR(content));
    int count = cJSON_GetArraySize(root);
    for (int i = 0; i < count; i++) {
      InsertLinkedList(list, JSONToComponent(cJSON_GetArrayItem(root, i)));
    }
  }
  return list;
}
