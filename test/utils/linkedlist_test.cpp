#include "gtest/gtest.h"
#include <stdlib.h>

extern "C" {
#include "../../ProgramDesignHomework/utils/linkedlist.h"
#include "../../ProgramDesignHomework/data/purchase.h"
}

typedef struct {
  int a;
  double b;
  char* c;
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