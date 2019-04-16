#include "sales.h"
#include"component.h"
#include "../global.h"
#include"../utils/fs.h"
#include "../utils/io.h"

#define Ltotal 1000000  //规定额度
#define Lquantity 9     //规定数量

Sales * NewSales()
{
  Sales *sales = (Sales*)malloc(sizeof(Sales));
  sales->component = NewComponent();
  sales->gift = NewComponent();
  sales->time = 0;
  sales->sales_mode = 1;
  sales->price = 1;
  sales->quantity = 1;
  sales->total = 1;
  sales->customer = newString("未知");
  return sales;
}

void FreeSales(Sales * sales)
{
  FreeComponent(sales->component);
  FreeComponent(sales->gift);
  $STR_BUF(sales->customer);
  free(sales);
}

Sales *ReadSales() {
  Sales *sales = NewSales();
  sales->component = ReadComponent();
  //prime->time=
  sales->sales_mode = InputInt(LITERAL("批发(0)/零售(1): ")) % 2;
  sales->price = InputInt(LITERAL("批发/零售价格: "));
  sales->quantity = InputInt(LITERAL("批发/零售数量: "));
  sales->total = sales->price * sales->quantity;
  freeAssign(&sales->customer, InputString(LITERAL("客户信息: "), LITERAL("未知")));
  if (sales->sales_mode == 0)
    if (sales->total > Ltotal || sales->quantity > Lquantity)
      sales->gift = Gift(sales);
  return sales;
}

Sales *JSONToSales(cJSON *root) {
  Sales *sales = NewSales();

  cJSON *item = cJSON_GetObjectItem(root, "time");
  if (item != NULL) {
    sales->time = item->valueint;
  }

  item = cJSON_GetObjectItem(root, "component");
  if (item != NULL) {
    FreeComponent(sales->component);
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
    freeAssign(&sales->customer, newString(item->valuestring));
  }

  item = cJSON_GetObjectItem(root, "gift");
  if (item != NULL) {
    FreeComponent(sales->gift);
    sales->gift = ReadComponentJSON(item);
  }

  return sales;
}
cJSON *SalesToJSON(Sales *prime)
{
  cJSON * root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "time", cJSON_CreateNumber(prime->time));//根节点下添加
  cJSON_AddItemToObject(root, "component", ComponentToJSON(prime->component));
  cJSON_AddItemToObject(root, "sales_mode", cJSON_CreateNumber(prime->sales_mode));
  cJSON_AddItemToObject(root, "price", cJSON_CreateNumber(prime->price));
  cJSON_AddItemToObject(root, "quantity", cJSON_CreateNumber(prime->quantity));
  cJSON_AddItemToObject(root, "customer", cJSON_CreateString(U8_CSTR(prime->customer)));
  cJSON_AddItemToObject(root, "gift", ComponentToJSON(prime->gift));
  return root;
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
bool FindTime_Sales(LinkedListNode *node) {
  return (((Sales *)node->data)->time <= timeToSearchearly
    && ((Sales *)node->data)->time >= timeToSearchlate);
}

Component* Gift() {
  int a[50], i, w;
  int t;
  for (i = 0; i < 50; i++)
    a[i] = i + 1;
  for (i = 0; i < 50; i++) {
    w = rand() % 50;
    t = a[i];
    a[i] = a[w];
    a[w] = t;
  }
  return prime;
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

bool WriteSalesJSON(string filename) {
  cJSON *result = cJSON_CreateArray();
  for (LinkedListNode *p = sales->top; p != NULL; p = p->next) {
    cJSON_AddItemReferenceToArray(result, SalesToJSON(p->data));
  }
  return WriteFile(filename, cJSON_Print(result));
}