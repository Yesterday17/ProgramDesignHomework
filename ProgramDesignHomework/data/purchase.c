#include "purchase.h"
#include"../utils/fs.h"
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

cJSON*purchase_cjson(Purchase *prime)
{
	cJSON * root = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "time", cJSON_CreateNumber(prime->time));//根节点下添加
	cJSON_AddItemToObject(root, "component", component_cjson(prime->prime));
	cJSON_AddItemToObject(root, "price", cJSON_CreateNumber(prime->price));
	cJSON_AddItemToObject(root, "quantity", cJSON_CreateNumber(prime->quantity));
	cJSON_AddItemToObject(root, "total", cJSON_CreateNumber(prime->total));
	cJSON_AddItemToObject(root, "quantity", cJSON_CreateString(prime->retailer));

	if (root)
		return root;
	else
		printf("error!!!");
}

string PrintPurchaseTitle() {
  return STR_BUF("");
}

string PrintPurchase(void *node, uint8_t id) {
  return STR_BUF("");
}

bool FindTime_Purchase(LinkedListNode *node) {
  if (((Purchase *) node->data)->time <= timeToSearchearly && ((Purchase *)node->data)->time>= timeToSearchearly)
	return true;
  
  else
    return false;

}

bool Findretailer_Purchase(LinkedListNode *node) {
  return compareString(((Purchase *) node->data)->retailer, retailerToSearch) == STRING_EQUAL;
}

bool FindComponentName_Purchase(LinkedListNode *node) {
  return compareString(((Purchase*)(node->data))->prime->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Purchase(LinkedListNode *node) {
  return compareString(((Purchase*)(node->data))->prime->type, nameToSearch) == STRING_EQUAL;
}



Purchase *purchasejson_struct(string filename)
{
	if (FileExist(filename))
	{
		return readjson_purchase(ReadFile(filename), purchase);
	}
}