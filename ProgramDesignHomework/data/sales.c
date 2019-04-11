#include "sales.h"

#include "../global.h"
#include "../utils/io.h"

Sales *ReadSales() {
  Sales *prime = malloc(sizeof(Sales));
  // prime->time = ReadTime();
  prime->price = InputInt(LITERAL("批发/零售价格: "));
  prime->quantity = InputInt(LITERAL("批发/零售数量: "));
  prime->total = prime->price * prime->quantity;
  prime->customer = InputString(LITERAL("please input customer: "), LITERAL("3021 bosses"));
  prime->component = ReadComponent();
  return prime;
}
Sales *readjson_sales(char *json_string, Sales *sales) {
  cJSON *item;
  cJSON *root = cJSON_Parse(json_string);
  if (!root) {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    cJSON_Delete(root);
    return NULL;
  } else {
    cJSON *object = cJSON_GetObjectItem(root, "sales");
    if (object == NULL) {
      printf("Error before: [%s]\n", cJSON_GetErrorPtr());
      cJSON_Delete(root);
      return NULL;
    } else {
      item = cJSON_GetObjectItem(root, "time");
      if (item != NULL) {
        sales->time = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "component");
      if (item != NULL) {
        sales->component = readjson_component(item, sales->component);
      }
      item = cJSON_GetObjectItem(object, "sales_mode");
      if (item != NULL) {
        sales->sales_mode = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "price");
      if (item != NULL) {
        sales->price = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "quantity");
      if (item != NULL) {
        sales->quantity = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "total");
      if (item != NULL) {
        sales->total = item->valueint;
      }
      item = cJSON_GetObjectItem(object, "customer");
      if (item != NULL) {
        memcpy(sales->customer, item->valuestring, strlen(item->valuestring));
      }
      item = cJSON_GetObjectItem(object, "gift");//结构体中的结构体直接赋值？？
      if (item != NULL) {
        sales->gift = readjson_component(item, sales->gift);
      }

    }
  }
  return sales;
}

string PrintSalesTitle() {
  return STR_BUF(" 名称  型号  制造商 销售模式  数量  单价  总价  赠品\n");
}

string PrintSales(void *node, uint8_t id) {
  return concat2(((Sales *) node)->customer, STRING("\n"));
}

bool Findcustomer_Component(LinkedListNode *node) {
  return compareString(((Sales *) node->data)->customer, customerToSearch) == STRING_EQUAL;
}