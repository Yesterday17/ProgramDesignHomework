#include "sales.h"
#include "../utils/io.h"
#include <malloc.h>

Sales* ReadSales() {
  Sales *prime = malloc(sizeof(Sales));
  // prime->time = ReadTime();
  printf("����/���ۼ۸�");  //�������ۼ۸�
  scanf("%d", &prime->price);
  printf("����/����������");//����/����������
  scanf("%d", &prime->quantity);
  prime->total = prime->price * prime->quantity;
  prime->customer = InputString("please input customer��", "3021 bosses");
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
			item = cJSON_GetObjectItem(object, "gift");//�ṹ���еĽṹ��ֱ�Ӹ�ֵ����
			if (item != NULL)
			{
				sales->gift = readjson_component(json_string, sales->gift);
			}

		}
	}
	return sales;
}
void  PrintSalesTitle()
{
	printf("\t���\t\t\t����\t\t\t�ͺ�\t\t\tʱ��\t\t\t������\t\t\tģʽ\t\t\t����\t\t\t����\t\t\t�ܼ�\t\t\t��Ʒ ");
	printf("\n");
	return;
}
char* PrintSales(void* node, uint8_t id)
{

}
