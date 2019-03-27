#include "component.h"
#include"cJSON.h"
#ifndef UNIT_TEST
#include "../global.h"
#include "../utils/io.h"
#else
#include "../global.c"
#include "../utils/io.c"
#endif



Component* ReadComponent() {
  Component *comp;
  comp->name = InputString("Input component name:", "Computer");
  comp->type = InputString("Input component type:", "3021");
  comp->manufacturer = InputString("manufacturer", "3021");
  return comp;
}

bool FindName_Component(LinkedListNode *node) {
  return strcmp(((Component *)node->data)->name, nameToSearch) == 0;
}
Component* read_structcomponent(cJSON *item);
{
	Component* comp;
	cJSON *item;
	cJSON *object = cJSON_GetObjectItem(root, "prime");
	if (object == NULL)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		cJSON_Delete(root);
		return -1;
	}

	if (object != NULL)
	{
		item = cJSON_GetObjectItem(object, "index");
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
