#include "purchase.h"
#include"../utils/fs.h"
#include "../global.h"
#include "../utils/io.h"


/**
 * 从控制台读取数据
 * @return Purchase*
 */
Purchase *ReadPurchase()
{

	Purchase *prime = (Purchase *)malloc(sizeof(Purchase));
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
Purchase *readjson_purchase(cJSON *root) {
	cJSON *object = cJSON_GetObjectItem(root, "purchase"), *item;
	Purchase *purchase = (Purchase*)malloc(sizeof(Purchase));
	if (object == NULL) {
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		cJSON_Delete(root);
		return NULL;
	}

	if (object != NULL) {
		item = cJSON_GetObjectItem(object, "prime");
		if (item != NULL) {
			purchase->prime = readjson_component(item, (Component *)malloc(sizeof(Component)));
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
		}
		else {
			PrintLITERAL("cJSON_GetObjectItem: total failed\n");
		}

		item = cJSON_GetObjectItem(object, "retailer");
		if (item != NULL) {
			memcpy(purchase->retailer, item->valuestring, strlen(item->valuestring));
		}
		return purchase;

	}
}
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
	if (((Purchase *)node->data)->time <= timeToSearchearly && ((Purchase *)node->data)->time >= timeToSearchearly)
		return true;

	else
		return false;

}

bool FindRetailer_Purchase(LinkedListNode *node) {
	return compareString(((Purchase *)node->data)->retailer, retailerToSearch) == STRING_EQUAL;
}

bool FindComponentName_Purchase(LinkedListNode *node) {
	return compareString(((Purchase*)(node->data))->prime->name, nameToSearch) == STRING_EQUAL;
}

bool FindComponentType_Purchase(LinkedListNode *node) {
	return compareString(((Purchase*)(node->data))->prime->type, nameToSearch) == STRING_EQUAL;
}



LinkedList* purchasejson_struct(string filename)
{
	LinkedList *list = CreateLinkedList();
	if (FileExist(filename))
	{
		string prime;
		int i;
		prime = ReadFile(filename);
		cJSON * root = cJSON_Parse(prime);
		int count = cJSON_GetArraySize(root);
		for (int i = 0; i < count; i++) {
			InsertLinkedList(list, readjson_purchase(cJSON_GetArrayItem(root, i)));
		}
	}
	return list;
}