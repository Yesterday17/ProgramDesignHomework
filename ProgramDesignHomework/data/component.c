#include "component.h"

#include "../global.h"
#include "../utils/io.h"
#include "../utils/fs.h"

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
Component* ReadComponent() {
  Component *component = NewComponent();
  freeAssign(&component->name, InputString(LITERAL("配件名称:"), LITERAL("未知")));
  freeAssign(&component->type, InputString(LITERAL("配件类型:"), LITERAL("未知")));
  freeAssign(&component->manufacturer, InputString(LITERAL("制造商："), LITERAL("未知")));
  return component;
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
