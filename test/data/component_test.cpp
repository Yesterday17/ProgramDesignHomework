/*
 * MIT License
 *
 * Copyright (c) 2019 Yesterday17 and ProgramDesignHomework contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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