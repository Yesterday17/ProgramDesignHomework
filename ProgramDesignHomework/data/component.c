#include "component.h"
#include "../utils/io.h"

Component ReadComponent() {
  Component comp;
  comp.name = InputString("Input component name:", "Computer");
  comp.type = ReadComponentType();
  comp.manufacturer = InputString("manufacturer", "3021");
  return comp;
}

ComponentType ReadComponentType() {
  ComponentType type;
  type.name = InputString("Input component type name:", "3021type");
  return type;
}