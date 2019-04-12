#include "purchase.h"

#include "../global.h"
#include "../utils/io.h"

/**
 * 从控制台读取数据
 * @return Purchase*
 */
Purchase *ReadPurchase() {
  Purchase *prime = (Purchase *) malloc(sizeof(Purchase));
  prime->time = 0; // FIXME
  prime->price = 0;
  prime->quantity = 0;
  prime->total = prime->price * prime->quantity;
  prime->retailer =
      InputString(LITERAL("please input retailer"), LITERAL("3021"));
  return prime;
}

/**
 * 从 Json 读取数据
 * @param root
 * @param purchase
 * @return
 */
Purchase *readjson_purchase(char *json_string, Purchase *purchase) {
  cJSON *item;
  cJSON *root = cJSON_Parse(json_string);
  if (!root) {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    return NULL;
  } else {
    cJSON *object = cJSON_GetObjectItem(root, "purchase");
    if (object == NULL) {
      printf("Error before: [%s]\n", cJSON_GetErrorPtr());
      cJSON_Delete(root);
      return NULL;
    }

    if (object != NULL) {
      item = cJSON_GetObjectItem(object, "prime");
      if (item != NULL) {
        purchase->prime = readjson_component(item, (Component *) malloc(sizeof(Component)));
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
      item = cJSON_GetObjectItem(object, "total");
      if (item != NULL) {
        purchase->total = item->valueint;
      } else {
        PrintLITERAL("cJSON_GetObjectItem: total failed\n");
      }

      item = cJSON_GetObjectItem(object, "retailer");
      if (item != NULL) {
        memcpy(purchase->retailer, item->valuestring, strlen(item->valuestring));
      }
    }

    cJSON_Delete(root);
    return purchase;
  }
}
cJSON*purchase_struct(Purchase prime)
{
	cJSON * root = cJSON_CreateObject();
	cJSON * item = cJSON_CreateObject();
	cJSON * next = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "rc", cJSON_CreateNumber(0));//根节点下添加
	cJSON_AddItemToObject(root, "operation", cJSON_CreateString("CALL"));
	cJSON_AddItemToObject(root, "service", cJSON_CreateString("telephone"));
	cJSON_AddItemToObject(root, "text", cJSON_CreateString("打电话给张三"));
	cJSON_AddItemToObject(root, "semantic", item);//root节点下添加semantic节点
	cJSON_AddItemToObject(item, "slots", next);//semantic节点下添加item节点
	cJSON_AddItemToObject(next, "name", cJSON_CreateString("张三"));//添加name节点

	printf("%s\n", cJSON_Print(root));

	return 0;


string PrintPurchaseTitle() {
  return STR_BUF("");
}

string PrintPurchase(void *node, uint8_t id) {
  return STR_BUF("");
}

bool FindTime_Purchase(LinkedListNode *node) {
  if (((Purchase *) node->data)->time == timeToSearch)
    return true;
  else
    return false;
}

bool Findretailer_Purchase(LinkedListNode *node) {
  return compareString(((Purchase *) node->data)->retailer, retailerToSearch) == STRING_EQUAL;
}

