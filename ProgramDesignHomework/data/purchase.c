#include "purchase.h"
#include <cstdio>
#include "io.h"
#include "time.h"
#include <readjson.h>
#include"component.h"
Purchase ReadPurchase() {
  Purchase prime;
  prime.time = ReadTime();
  prime.price = InputString("请输入进货单价","1");//输入进货单价
  prime.quantity=InputString("请输入进货数量","1");              //输入进货数量
  prime.total = prime.price * prime.quantity;  //输入商品总价
  prime.retailer =
      InputString("please input retailer", "3021");  //输入进货供应商
  return prime;
}
Purchase readjson_purchase(char *json_string, Purchase *purchase)
{
	cJSON *item;
	cJSON *root = cJSON_Parse(json_string);
	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON *object = cJSON_GetObjectItem(root, "purchase");
		if (object == NULL)
		{
			printf("Error before: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}

		if (object != NULL)
		{
			item = cJSON_GetObjectItem(object, "prime");
			if (item != NULL)
			{
				purchase->prime = readjson_component(cJSON *json_string, Compoment *item);
			}
			item = cJSON_GetObjectItem(object, "time");
			if (item != NULL)
			{
				purchase->time = item->valueint;
			}

			item = cJSON_GetObjectItem(object, "price");
			if (item != NULL)
			{
				purchase->price = item->valueint;
			}

			item = cJSON_GetObjectItem(object, "quantity");
			if (item != NULL)
			{
				purchase->quantity = item->valueint;
			}
			item = cJSON_GetObjectItem(object, "total");
			if (item != NULL)
			{
				purchase->total = item->valueint;
			}
			else
			{
				printf("cJSON_GetObjectItem: total failed\n");
			}

			item = cJSON_GetObjectItem(object, "retailer");
			if (item != NULL)
			{
				memcpy(purchase->retailer, item->valuestring, strlen(item->valuestring));
			}
		}

		cJSON_Delete(root);
		return purchase;
	}
	return 0;
}

