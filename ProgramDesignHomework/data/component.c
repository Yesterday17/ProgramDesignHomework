#include "component.h"

#include "../global.h"
#include "../utils/io.h"

Component* ReadComponent() {
  Component *comp = (Component*)malloc(sizeof(Component));
  comp->name = InputString(LITERAL("Input component name:"), LITERAL("Computer"));
  comp->type = InputString(LITERAL("Input component type:"), LITERAL("3021"));
  comp->manufacturer = InputString(LITERAL("manufacturer"), LITERAL("3021"));
  return comp;
}

bool FindName_Component(LinkedListNode *node) {
  return compareString(((Component*)(node->data))->name, nameToSearch) == STRING_EQUAL;
}

bool FindType_Component(LinkedListNode *node) {
  return compareString(((Component *)node->data)->type, typeToSearch) == STRING_EQUAL;
}

bool FindMan_Component(LinkedListNode *node) {
  return compareString(((Component *)node->data)->manufacturer, manufacturerToSearch) == STRING_EQUAL;
}

Component* readjson_component(cJSON *root, Component *comp)
{
  cJSON *item;
  if (!root)
  {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    cJSON_Delete(root);
    return NULL;
  }

  else
  {
    cJSON *object = cJSON_GetObjectItem(root, "comp");
    if (object == NULL)
    {
      printf("Error before: [%s]\n", cJSON_GetErrorPtr());
      cJSON_Delete(root);
      return NULL;
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
        memcpy(comp->name, item->valuestring, comp->name->bufSize);
      }
      item = cJSON_GetObjectItem(object, "type");
      if (item != NULL)
      {
        memcpy(comp->type, item->valuestring, comp->type->bufSize);
      }
      item = cJSON_GetObjectItem(object, "manufacturer");
      if (item != NULL)
      {
        memcpy(comp->manufacturer, item->valuestring, comp->manufacturer->bufSize);
      }
    }
  }
  return comp;
}
