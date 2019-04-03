#include "sales.h"

Sales ReadSales() {
  Sales prime;
  prime.time = ReadTime();
  printf("批发/零售价格：");  //批发零售价格
  scanf("%d", &prime.price);
  printf("批发/零售数量：");//批发/零售数量：
  scanf("%d", &prime.quantity);
  prime.total = prime.price * prime.quantity;
  prime.customer = InputString("please input customer：", "3021 bosses");
  ReadComponent();
  return prime;
}
Sales * readjson_sales(char *json_string, Sales *prime)
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
		item = cJSON_GetObjectItem(root, "prime");
		if (item != NULL)
		{
			comp->index = item->valueint;
		}
		item = cJSON_GetObjectItem(object, "name");
		if (item != NULL)
		{
			memcpy(comp->name, item->name, strlen(comp->name));
		}
		item = cJSON_GetObjectItem(object, "type");
		if (item != NULL)
		{
			memcpy(comp->type, item->type, strlen(comp->type));
		}
		item = cJSON_GetObjectItem(object, "manufacturer");
		if (item != NULL)
		{
			memcpy(comp->manufacturer, item->manufacturer, strlen(comp->manufacturer));
		}
	}
	return comp;
}
