#include "purchase.h"
#include"../utils/fs.h"
#include "../global.h"
#include "../utils/io.h"

Purchase * NewPurchase()
{
  Purchase *purchase = (Purchase *)malloc(sizeof(Purchase));
  purchase->component = -1;
  purchase->time = 0;
  purchase->price = 1;
  purchase->quantity = 1;
  purchase->total = 1;
  purchase->retailer = newString(u8"UNKNOWN");
  return purchase;
}

void FreePurchase(Purchase * purchase)
{
  $STR_BUF(purchase->retailer);
  free(purchase);
}

/**
 * 从控制台读取数据
 * @return Purchase*
 */
Purchase *ReadPurchase()
{
  Purchase *purchase = NewPurchase();

  purchase->component = -1;

  // FIXME: 输入时间字符串而非整数
  purchase->time = timemaking();
  freeAssign(&purchase->retailer, InputString(LITERAL("供应商: "), LITERAL("3021")));
  purchase->price = InputInt(LITERAL("进价单价: "));
  purchase->quantity = InputInt(LITERAL("进货数量: "));
  purchase->total = purchase->price * purchase->quantity;
  return purchase;
}

/**
 * 从 Json 读取数据
 * @param root
 * @param purchase
 * @return
 */
Purchase *JSONToPurchase(cJSON *root) {
  Purchase *purchase = NewPurchase();

  cJSON *item = cJSON_GetObjectItem(root, "component");
  if (item != NULL) {
    purchase->component = item->valueint;
  }
  item = cJSON_GetObjectItem(root, "time");
  if (item != NULL) {
    purchase->time = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "price");
  if (item != NULL) {
    purchase->price = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "quantity");
  if (item != NULL) {
    purchase->quantity = item->valueint;
  }

  purchase->total = purchase->price * purchase->quantity;

  item = cJSON_GetObjectItem(root, "retailer");
  if (item != NULL) {
    freeAssign(&purchase->retailer, newString(item->valuestring));
  }

  return purchase;
}
cJSON *PurchaseToJSON(Purchase *prime)
{
  cJSON *root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "time", cJSON_CreateNumber(prime->time));//根节点下添加
  cJSON_AddItemToObject(root, "component", cJSON_CreateNumber(prime->component));
  cJSON_AddItemToObject(root, "price", cJSON_CreateNumber(prime->price));
  cJSON_AddItemToObject(root, "quantity", cJSON_CreateNumber(prime->quantity));
  cJSON_AddItemToObject(root, "total", cJSON_CreateNumber(prime->total));
  cJSON_AddItemToObject(root, "retailer", cJSON_CreateString(U8_CSTR(prime->retailer)));
  return root;
}

string PrintPurchaseTitle() {
  char ans[200];
  sprintf(ans, "   %-12s|%-12s|%-13s|%-12s|%-12s|%-12s|%-14s\n",
    U8_CSTR(LITERAL("名称")),
    U8_CSTR(LITERAL("型号")),
    U8_CSTR(LITERAL("制造商")),
    U8_CSTR(LITERAL("数量")),
    U8_CSTR(LITERAL("单价")),
    U8_CSTR(LITERAL("总价")),
    U8_CSTR(LITERAL("经销商")));
  return newString(ans);
}

string PrintPurchase(void *node, uint8_t id) {
  Purchase* purchase = (Purchase *)node;
  Component* comp = AtLinkedList(component, purchase->component)->data;
  char ans[200];
  sprintf(ans, "%-10s|%-10s|%-10s|%-10d|%-10.2f|%-10.2f|%-10s\n",
    U8_CSTR(comp->name),
    U8_CSTR(comp->type),
    U8_CSTR(comp->manufacturer),
    purchase->quantity,
    purchase->price / 100.0f,
    purchase->total / 100.0f,
    U8_CSTR(purchase->retailer));
  return newString(ans);
}

bool FindTime_Purchase(LinkedListNode *node) {
  return (((Purchase *)node->data)->time <= timeToSearchearly
    && ((Purchase *)node->data)->time >= timeToSearchearly);
}

bool FindRetailer_Purchase(LinkedListNode *node) {
  return compareString(((Purchase *)node->data)->retailer, retailerToSearch) == STRING_EQUAL;
}

bool FindComponentName_Purchase(LinkedListNode *node) {
  Component *comp = AtLinkedList(component, ((Purchase*)(node->data))->component)->data;
  return compareString(comp->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Purchase(LinkedListNode *node) {
  Component *comp = AtLinkedList(component, ((Purchase*)(node->data))->component)->data;
  return compareString(comp->type, nameToSearch) == STRING_EQUAL;
}

LinkedList* ReadPurchaseJSON(string filename)
{
  LinkedList *list = CreateLinkedList();
  if (FileExist(filename))
  {
    string content = ReadFile(filename);
    cJSON * root = cJSON_Parse(U8_CSTR(content));
    int count = cJSON_GetArraySize(root);
    for (int i = 0; i < count; i++) {
      InsertLinkedList(list, JSONToPurchase(cJSON_GetArrayItem(root, i)));
    }
  }
  return list;
}

bool WritePurchaseJSON(string filename) {
  cJSON *result = cJSON_CreateArray();
  for (LinkedListNode *p = purchase->top; p != NULL; p = p->next) {
    cJSON_AddItemReferenceToArray(result, PurchaseToJSON(p->data));
  }
  return WriteFile(filename, cJSON_Print(result));
}