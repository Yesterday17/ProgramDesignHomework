
#include <malloc.h>
#include "sales.h"

#ifndef UNIT_TEST
#include "../utils/io.h"
#include "../global.h"
#include "../cstring_jslike/cstring_jslike.h"
#else
#include "../utils/io.c"
#include "../global.c"
#include "../cstring_jslike/cstring_jslike.c"
#endif
Sales* ReadSales() {
  Sales *prime = malloc(sizeof(Sales));
  // prime->time = ReadTime();
  prime->price = InputInt("批发/零售价格", 0);
  prime->quantity = InputInt("批发/零售数量", 0);
  prime->total = prime->price * prime->quantity;
  prime->customer = InputString("please input customer：", "3021 bosses");
  // ReadComponent();
  return prime;
}
Sales* readjson_sales(char *json_string, Sales *sales)
{
  cJSON *item;
  cJSON *root = cJSON_Parse(json_string);
  if (!root)
  {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    cJSON_Delete(root);
    return -1;
  }
  else
  {
    cJSON *object = cJSON_GetObjectItem(root, "sales");
    if (object == NULL)
    {
      printf("Error before: [%s]\n", cJSON_GetErrorPtr());
      cJSON_Delete(root);
      return -1;
    }
    else
    {
      item = cJSON_GetObjectItem(root, "time");
      if (item != NULL)
      {
        sales->time = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "component");
      if (item != NULL)
      {
        sales->component = readjson_component(json_string, &sales->component);
      }
      item = cJSON_GetObjectItem(object, "sales_mode");
      if (item != NULL)
      {
        sales->sales_mode = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "price");
      if (item != NULL)
      {
        sales->price = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "quantity");
      if (item != NULL)
      {
        sales->quantity = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "total");
      if (item != NULL)
      {
        sales->total = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "customer");
      if (item != NULL)
      {
        memcpy(sales->customer, item->valuestring, strlen(item->valuestring));
      }
      item = cJSON_GetObjectItem(object, "gift");//结构体中的结构体直接赋值？？
      if (item != NULL)
      {
        sales->gift = readjson_component(json_string, sales->gift);
      }

    }
  }
  return sales;
}

char* PrintSalesTitle()
{
  return " 名称  型号  制造商 销售模式  数量  单价  总价  赠品\n";
}

char* PrintSales(void* node, uint8_t id)
{
  return ((Sales*)node)->customer;
}

bool Findcustomer_Component(LinkedListNode *node) {
  return strcmp(((Sales *)node->data)->customer, customerToSearch) == 0;
}