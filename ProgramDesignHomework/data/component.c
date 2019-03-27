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

}
