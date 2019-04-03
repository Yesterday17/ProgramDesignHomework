#include "component.h"
#include "../utils/cJSON/cJSON.h"
#ifndef UNIT_TEST
#include "../global.h"
#include "../utils/io.h"
#else
#include "../global.c"
#include "../utils/io.c"
#endif



Component* ReadComponent() {
  Component *comp = malloc(sizeof(Component));
  comp->name = InputString("Input component name:", "Computer");
  comp->type = InputString("Input component type:", "3021");
  comp->manufacturer = InputString("manufacturer", "3021");
  return comp;
}

bool FindName_Component(LinkedListNode *node) {
  return strcmp(((Component *)node->data)->name, nameToSearch) == 0;
}


Component* readjson_component(cJSON *json_string,Component *comp)
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
		cJSON *object = cJSON_GetObjectItem(root, "comp");
		if (object == NULL)
		{
			printf("Error before: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		else
		{
			item = cJSON_GetObjectItem(object, "index");
			if (item != NULL)
			{
				comp->index = item->valueint;
			}
			item = cJSON_GetObjectItem(object, "name");
			if (item != NULL)
			{
				memcpy(comp->name, item->valuestring, strlen(comp->name));
			}
			item = cJSON_GetObjectItem(object, "type");
			if (item != NULL)
			{
				memcpy(comp->type, item->type, strlen(comp->type));
			}
			item = cJSON_GetObjectItem(object, "manufacturer");
			if (item != NULL)
			{
				memcpy(comp->manufacturer, item->valuestring, strlen(comp->manufacturer));
			}
		}
	}
	return comp;
}
