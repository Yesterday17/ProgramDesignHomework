#pragma once
#include <stdbool.h>

typedef struct LinkedListNode {//������
  void* data;
  struct LinkedListNode* next;
} LinkedListNode;


typedef struct {// ����ָ��
  LinkedListNode* top;
  LinkedListNode* rear;
}LinkedList;


#ifndef UNIT_TEST

LinkedList CreateLinkedList(void);
void InsertLinkedList(LinkedList list, void* data);
void DeleteLinkedList(LinkedList list, bool* callback(LinkedListNode*));

#endif