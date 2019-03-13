#include "component.h"
#include <stdio.h>

Component ReadComponent() {
  Component comp;
  printf("Input component name: ");
  scanf("%s", &comp.name);

  comp.type = ReadComponentType();

  printf("Input manufacturer: ");
  scanf("%s", &comp.manufacturer);
  return comp;
}

ComponentType ReadComponentType() {
  ComponentType type;
  printf("Input component type name: ");
  scanf("%s", &type.name);
  return type;
}