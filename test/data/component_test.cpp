#include "gtest/gtest.h"
#include <stdlib.h>

extern "C" {
#include "../../ProgramDesignHomework/data/component.h"
}

/**
 * 测试结构体创建
 */
TEST(TestComponent, CreateStruct) {
  Component* comp = (Component*)malloc(sizeof(Component));
  comp->index = 0;
  comp->manufacturer = LITERAL("Yesterday17");
  comp->name = LITERAL("SEN-PAI");
  comp->type = LITERAL("114-514");

  EXPECT_EQ(comp->index, 0);
  EXPECT_EQ(compareString(comp->manufacturer, LITERAL("Yesterday17")), STRING_EQUAL);
  EXPECT_EQ(compareString(comp->name, LITERAL("SEN-PAI")), STRING_EQUAL);
  EXPECT_EQ(compareString(comp->type, LITERAL("114-514")), STRING_EQUAL);
  free(comp);
}