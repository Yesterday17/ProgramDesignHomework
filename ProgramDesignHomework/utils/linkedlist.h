#pragma once
typedef struct LinkedListNode {//������
  void* data;
  struct LinkedListNode* next;
} LinkedListNode;


typedef struct {// ����ָ��
  LinkedListNode* top;
  LinkedListNode* rear;
}LinkedList;