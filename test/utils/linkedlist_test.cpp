#define UNIT_TEST
#include "gtest/gtest.h"
#include <stdlib.h>

extern "C" {
#include "../../ProgramDesignHomework/utils/linkedlist.h"
//#include "../../ProgramDesignHomework/data/purchase.h"
}

typedef struct {
  int a;
  double b;
  char* c;
}TestStruct;

TEST(TestLinkedList, CreateLinkedList) {
  LinkedList *list = CreateLinkedList();
  EXPECT_TRUE(list->top == NULL);
  EXPECT_TRUE(list->rear == NULL);
  free(list);
}

TEST(TestLinkedList, InputOneStruct) {
  LinkedList *list = CreateLinkedList();

  TestStruct *test = (TestStruct*)malloc(sizeof(TestStruct));
  InsertLinkedList(list, (void*)test);
  EXPECT_TRUE(list->top->data == (void*)test);
  EXPECT_TRUE(list->rear->data == (void*)test);
  free(test);
  free(list);
}

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