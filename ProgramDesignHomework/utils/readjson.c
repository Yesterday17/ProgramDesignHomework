#include<stdio.h>
#include"purchase.h"
#include"cJSON.h"
#incldue"component.h"
Purchase cJSON_to_struct(char *json_string, Purchase *purchase)
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
				purchase->prime = read_jsoncomponent(item);
			}
			item = cJSON_GetObjectItem(object, "time");
			if (item != NULL)
			{
				purchase->time = item->valueint;
			}

			item = cJSON_GetObjectItem(object, "price");
			if (item != NULL)
			{
				purchase->price=item->valueint;
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


