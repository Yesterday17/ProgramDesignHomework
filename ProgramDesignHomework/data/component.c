#include "component.h"

#include "../global.h"
#include "../utils/io.h"

/**
 * 从控制台读取数据
 * @return Component*
 */
Component* ReadComponent() {
  Component *comp = (Component*)malloc(sizeof(Component));
  comp->name = InputString(LITERAL("配件名称:"), LITERAL("未知"));
  comp->type = InputString(LITERAL("配件类型:"), LITERAL("未知"));
  comp->manufacturer = InputString(LITERAL("制造商："), LITERAL("未知"));
  return comp;
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
Component* readjson_component(cJSON *root, Component *comp)
{
  cJSON *item;
  if (!root)
  {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    cJSON_Delete(root);
    return NULL;
  }

  else
  {
    cJSON *object = cJSON_GetObjectItem(root, "comp");
    if (object == NULL)
    {
      printf("Error before: [%s]\n", cJSON_GetErrorPtr());
      cJSON_Delete(root);
      return NULL;
    }
    else
    {
      item = cJSON_GetObjectItem(object, "index");
      if (item != NULL)
      {
        comp->index = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "name");
      if (item != NULL)
      {
        memcpy(comp->name, item->valuestring, comp->name->bufSize);
      }
      item = cJSON_GetObjectItem(object, "type");
      if (item != NULL)
      {
        memcpy(comp->type, item->valuestring, comp->type->bufSize);
      }
      item = cJSON_GetObjectItem(object, "manufacturer");
      if (item != NULL)
      {
        memcpy(comp->manufacturer, item->valuestring, comp->manufacturer->bufSize);
      }
    }
  }
  return comp;
}
cJSON*component_cjson(Component *prime)
{
  cJSON * root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "index", cJSON_CreateNumber(prime->index));//根节点下添加
  cJSON_AddItemToObject(root, "name", cJSON_CreateString(U8_CSTR(prime->name)));
  cJSON_AddItemToObject(root, "type", cJSON_CreateString(U8_CSTR(prime->type)));
  cJSON_AddItemToObject(root, "manufacturer", cJSON_CreateString(U8_CSTR(prime->manufacturer)));

  if (root)
    return root;
  else
    return NULL;
}
