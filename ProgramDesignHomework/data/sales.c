#include "sales.h"
#include"component.h"
#include "../global.h"
#include"../utils/fs.h"
#include "../utils/io.h"

Sales *ReadSales() {
  Sales *prime = malloc(sizeof(Sales));
  prime->component = ReadComponent();
  prime->price = InputInt(LITERAL("批发/零售价格: "));
  prime->quantity = InputInt(LITERAL("批发/零售数量: "));
  prime->total = prime->price * prime->quantity;
  prime->customer = InputString(LITERAL("客户信息: "), LITERAL("无"));
  return prime;
}
Sales *JSONToSales(cJSON *root) {
  Sales *sales = (Sales*)malloc(sizeof(Sales));

  cJSON *item = cJSON_GetObjectItem(root, "time");
  if (item != NULL) {
    sales->time = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "component");
  if (item != NULL) {
    sales->component = ReadComponentJSON(item);
  }

  item = cJSON_GetObjectItem(root, "sales_mode");
  if (item != NULL) {
    sales->sales_mode = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "price");
  if (item != NULL) {
    sales->price = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "quantity");
  if (item != NULL) {
    sales->quantity = item->valueint;
  }

  sales->total = sales->price * sales->quantity;

  item = cJSON_GetObjectItem(root, "customer");
  if (item != NULL) {
    sales->customer = newString(item->valuestring);
  }

  item = cJSON_GetObjectItem(root, "gift");
  if (item != NULL) {
    sales->gift = ReadComponentJSON(item);
  }

  return sales;
}
cJSON*SalesToJSON(Sales *prime)
{

  cJSON * root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "time", cJSON_CreateNumber(prime->time));//根节点下添加
  cJSON_AddItemToObject(root, "component", ComponentToJSON(prime->component));
  cJSON_AddItemToObject(root, "sales_mode", cJSON_CreateNumber(prime->sales_mode));
  cJSON_AddItemToObject(root, "price", cJSON_CreateNumber(prime->price));
  cJSON_AddItemToObject(root, "quantity", cJSON_CreateNumber(prime->quantity));
  cJSON_AddItemToObject(root, "total", cJSON_CreateNumber(prime->total));

  if (root)
    return root;
  else
    return NULL;
}

string PrintSalesTitle() {
  char ans[200];
  sprintf(ans, "   %-12s|%-12s|%-13s|%-14s|%-12s|%-12s|%-12s|%-14s|%-12s\n",
    U8_CSTR(LITERAL("名称")),
    U8_CSTR(LITERAL("型号")),
    U8_CSTR(LITERAL("制造商")),
    U8_CSTR(LITERAL("销售模式")),
    U8_CSTR(LITERAL("数量")),
    U8_CSTR(LITERAL("单价")),
    U8_CSTR(LITERAL("总价")),
    U8_CSTR(LITERAL("客户信息")),
    U8_CSTR(LITERAL("赠品")));
  return newString(ans);
}

string PrintSales(void *node, uint8_t id) {
  Sales* sales = (Sales *)node;
  char ans[200];
  sprintf(ans, "%-10s|%-10s|%-10s|%-12s|%-10d|%-10d|%-10d|%-10s|%-10s\n", 
    U8_CSTR(sales->component->name),
    U8_CSTR(sales->component->type),
    U8_CSTR(sales->component->manufacturer), 
    ((sales->sales_mode == 1) ? U8_CSTR(LITERAL("批发")) : U8_CSTR(LITERAL("零售"))),
    sales->quantity,
    sales->price,
    sales->total,
    U8_CSTR(sales->customer),
    U8_CSTR(sales->gift->name));
  return newString(ans);
}

bool FindCustomer_Sales(LinkedListNode *node) {
  return compareString(((Sales *)(node->data))->customer, customerToSearch) == STRING_EQUAL;
}
bool FindComponentName_Sales(LinkedListNode *node) {
  return compareString(((Sales*)(node->data))->component->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Sales(LinkedListNode *node) {
  return compareString(((Sales*)(node->data))->component->type, typeToSearch) == STRING_EQUAL;
}

LinkedList* Gift(LinkedList *node) {

  LinkedListNode *head, *p;
  LinkedList *prime, *q;
  prime = CreateLinkedList();
  int size = 0, counts = 3;
  for (p = node->top->next; p != NULL; p = p->next)
  {
    size++;
  }
  q = CreateLinkedList();
  q = prime;
  prime->rear = NULL;
  while (counts--)
  {
    int t = rand() % size;
    head = node->top->next;
    while (t--)
    {
      head = head->next;
    }
    InsertLinkedList(prime, head->data);
    free(head);
  }
  return prime;
}


bool FindTime_Sales(LinkedListNode *node) {
  if (((Sales *)node->data)->time <= timeToSearchearly && ((Sales *)node->data)->time >= timeToSearchlate)
    return true;
  else
    return false;
}

LinkedList* ReadSalesJSON(string filename)
{
  LinkedList *list = CreateLinkedList();
  if (FileExist(filename))
  {
    string prime = ReadFile(filename);
    cJSON * root = cJSON_Parse(U8_CSTR(prime));
    int count = cJSON_GetArraySize(root);
    for (int i = 0; i < count; i++) {
      InsertLinkedList(list, JSONToSales(cJSON_GetArrayItem(root, i)));
    }
  }
  return list;
}