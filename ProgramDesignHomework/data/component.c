#include "component.h"

#ifndef UNIT_TEST
#include "../global.h"
#include "../utils/io.h"
#else
#include "../global.c"
#include "../utils/io.c"
#endif

ComponentType ReadComponentType() {
  ComponentType type;
  type.name = InputString("Input component type name:", "3021type");
  return type;
}

Component ReadComponent() {
  Component comp;
  comp.name = InputString("Input component name:", "Computer");
  comp.type = ReadComponentType();
  comp.manufacturer = InputString("manufacturer", "3021");
  return comp;
}

bool FindName_Component(LinkedListNode *node) {
  return strcmp(((Component *)node->data)->name, nameToSearch) == 0;
}
