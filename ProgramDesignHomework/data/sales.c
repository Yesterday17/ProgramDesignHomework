#include "sales.h"
#include"component.h"
#include "../global.h"
#include"../utils/fs.h"
#include "../utils/io.h"

Sales *ReadSales() {
  Sales *prime = malloc(sizeof(Sales));
  prime->prime = ReadComponent();
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
    sales->prime = ReadComponentJSON(item);
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

  item = cJSON_GetObjectItem(root, "total");
  if (item != NULL) {
    sales->total = item->valueint;
  }

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
  cJSON_AddItemToObject(root, "component", ComponentToJSON(prime->prime));
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
  return STR_BUF(" 名称  型号  制造商 销售模式  数量  单价  总价  客户信息  赠品\n");
}

string PrintSales(void *node, uint8_t id) {
  return concat2(((Sales *)node)->customer, STRING("\n"));
}

bool FindCustomer_Sales(LinkedListNode *node) {
  return compareString(((Sales *)(node->data))->customer, customerToSearch) == STRING_EQUAL;
}
bool FindComponentName_Sales(LinkedListNode *node) {
  return compareString(((Sales*)(node->data))->prime->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Sales(LinkedListNode *node) {
  return compareString(((Sales*)(node->data))->prime->type, typeToSearch) == STRING_EQUAL;
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