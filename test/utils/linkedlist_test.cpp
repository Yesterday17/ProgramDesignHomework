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
#include "../../ProgramDesignHomework/utils/linkedlist.h"
#include "../../ProgramDesignHomework/data/purchase.h"
}

typedef struct {
  int a;
  double b;
}TestStruct;

/**
 * 测试创建链表
 */
TEST(TestLinkedList, CreateLinkedList) {
  LinkedList *list = CreateLinkedList();
  EXPECT_TRUE(list->top == NULL);
  EXPECT_TRUE(list->rear == NULL);
  free(list);
}

/**
 * 测试向链表中加入一个元素
 */
TEST(TestLinkedList, InputOneStruct) {
  LinkedList *list = CreateLinkedList();

  TestStruct *test = (TestStruct*)malloc(sizeof(TestStruct));
  InsertLinkedList(list, (void*)test);
  EXPECT_TRUE(list->top->data == (void*)test);
  EXPECT_TRUE(list->rear->data == (void*)test);
  free(test);
  free(list);
}

/**
 * 测试向链表中加入两个元素
 */
TEST(TestLinkedList, InputTwoStruct) {
  LinkedList *list = CreateLinkedList();

  TestStruct *test1 = (TestStruct*)malloc(sizeof(TestStruct));
  TestStruct *test2 = (TestStruct*)malloc(sizeof(TestStruct));
  InsertLinkedList(list, (void*)test1);
  InsertLinkedList(list, (void*)test2);

  EXPECT_TRUE(list->top->data == (void*)test1);
  EXPECT_TRUE(list->rear->data == (void*)test2);

  free(test1);
  free(test2);
  free(list);
}

/**
 * 测试向链表中加入多个元素
 */
TEST(TestLinkedList, InputMultipleStruct) {
  LinkedList *list = CreateLinkedList();

  TestStruct *test1 = (TestStruct*)malloc(sizeof(TestStruct));
  TestStruct *test2 = (TestStruct*)malloc(sizeof(TestStruct));
  TestStruct *test3 = (TestStruct*)malloc(sizeof(TestStruct));
  InsertLinkedList(list, (void*)test1);
  InsertLinkedList(list, (void*)test2);
  InsertLinkedList(list, (void*)test3);

  EXPECT_TRUE(list->top->data == (void*)test1);
  EXPECT_TRUE(list->rear->data == (void*)test3);

  free(test1);
  free(test2);
  free(test3);
  free(list);
}

TEST(TestLinkedList, FinalNULL) {
  LinkedList *list = CreateLinkedList();
  int a = 0;

  EXPECT_TRUE(list->top == NULL);
  EXPECT_TRUE(list->rear == NULL);

  InsertLinkedList(list, &a);
  EXPECT_TRUE(list->top != NULL);
  EXPECT_TRUE(list->rear != NULL);
  EXPECT_TRUE(list->top->next == NULL);
  EXPECT_TRUE(list->rear->next == NULL);

  InsertLinkedList(list, &a);
  EXPECT_TRUE(list->top != NULL);
  EXPECT_TRUE(list->rear != NULL);
  EXPECT_TRUE(list->top->next != NULL);
  EXPECT_TRUE(list->rear->next == NULL);
  
  InsertLinkedList(list, &a);
  EXPECT_TRUE(list->top != NULL);
  EXPECT_TRUE(list->rear != NULL);
  EXPECT_TRUE(list->top->next != NULL);
  EXPECT_TRUE(list->rear->next == NULL);
  free(list);
}