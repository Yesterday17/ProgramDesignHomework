#include "purchase.h"
#include"../utils/fs.h"
#include "../global.h"
#include "../utils/io.h"

Purchase * NewPurchase()
{
  Purchase *purchase = (Purchase *)malloc(sizeof(Purchase));
  purchase->component = NewComponent();
  purchase->time = 0;
  purchase->price = 1;
  purchase->quantity = 1;
  purchase->total = 1;
  purchase->retailer = newString("3021");
  return purchase;
}

void FreePurchase(Purchase * purchase)
{
  FreeComponent(purchase->component);
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

  free(purchase->component);
  purchase->component = ReadComponent();

  // FIXME: 输入时间字符串而非整数
  purchase->time = InputInt(LITERAL("进货时间: "));
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
Purchase *readjson_purchase(cJSON *root) {
  cJSON *object = cJSON_GetObjectItem(root, "purchase"), *item;
  Purchase *purchase = (Purchase*)malloc(sizeof(Purchase));
  item = cJSON_GetObjectItem(object, "prime");
  if (item != NULL) {
    FreeComponent(purchase->component);
    purchase->component = ReadComponentJSON(item);
  }
  item = cJSON_GetObjectItem(object, "time");
  if (item != NULL) {
    purchase->time = item->valueint;
  }

  item = cJSON_GetObjectItem(object, "price");
  if (item != NULL) {
    purchase->price = item->valueint;
  }

  item = cJSON_GetObjectItem(object, "quantity");
  if (item != NULL) {
    purchase->quantity = item->valueint;
  }

  purchase->total = purchase->price * purchase->quantity;

  item = cJSON_GetObjectItem(object, "retailer");
  if (item != NULL) {
    freeAssign(&purchase->retailer, newString(item->valuestring));
  }
  return purchase;
}
cJSON *PurchaseToJSON(Purchase *prime)
{
  cJSON *root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "time", cJSON_CreateNumber(prime->time));//根节点下添加
  cJSON_AddItemToObject(root, "component", ComponentToJSON(prime->component));
  cJSON_AddItemToObject(root, "price", cJSON_CreateNumber(prime->price));
  cJSON_AddItemToObject(root, "quantity", cJSON_CreateNumber(prime->quantity));
  cJSON_AddItemToObject(root, "total", cJSON_CreateNumber(prime->total));
  cJSON_AddItemToObject(root, "retailer", cJSON_CreateString(U8_CSTR(prime->retailer)));

  return root;
}

string PrintPurchaseTitle() {
  return STR_BUF("");
}

string PrintPurchase(void *node, uint8_t id) {
  return STR_BUF("");
}

bool FindTime_Purchase(LinkedListNode *node) {
  return (((Purchase *)node->data)->time <= timeToSearchearly
    && ((Purchase *)node->data)->time >= timeToSearchearly);
}

bool FindRetailer_Purchase(LinkedListNode *node) {
  return compareString(((Purchase *)node->data)->retailer, retailerToSearch) == STRING_EQUAL;
}

bool FindComponentName_Purchase(LinkedListNode *node) {
  return compareString(((Purchase*)(node->data))->component->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Purchase(LinkedListNode *node) {
  return compareString(((Purchase*)(node->data))->component->type, nameToSearch) == STRING_EQUAL;
}

LinkedList* ReadPurchaseJSON(string filename)
{
  LinkedList *list = CreateLinkedList();
  if (FileExist(filename))
  {
    string prime;
    prime = ReadFile(filename);
    cJSON * root = cJSON_Parse(U8_CSTR(prime));
    int count = cJSON_GetArraySize(root);
    for (int i = 0; i < count; i++) {
      InsertLinkedList(list, readjson_purchase(cJSON_GetArrayItem(root, i)));
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