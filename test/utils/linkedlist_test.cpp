#define UNIT_TEST
#include "gtest/gtest.h"

extern "C" {
#include "../../ProgramDesignHomework/utils/linkedlist.c"
}

TEST(Create, TestLinkedList) {
  LinkedList list = CreateLinkedList();
  EXPECT_TRUE(list.top == NULL);
  EXPECT_TRUE(list.rear == NULL);
}

TEST(Insert, TestLinkedList) {
  LinkedList list = CreateLinkedList();
  // InsertLinkedList(list, );
}