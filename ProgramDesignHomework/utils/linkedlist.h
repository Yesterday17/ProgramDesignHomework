#ifndef _UTILS_LINKEDLIST_H_
#define _UTILS_LINKEDLIST_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct LinkedListNode {  //链表结点
  void *data;
  struct LinkedListNode *next;
} LinkedListNode;

typedef struct {  // 链表指针
  LinkedListNode *top;
  LinkedListNode *rear;
} LinkedList;

typedef struct {
  size_t count;
  LinkedListNode **result;
} LinkedListFindResult;

LinkedList *CreateLinkedList();

void InsertLinkedList(LinkedList *list, void *data);

LinkedListNode *DeleteLinkedList(LinkedList *list,
                                 bool *callback(LinkedListNode *));

LinkedListFindResult FindLinkedList(LinkedList *list, bool *callback(LinkedListNode *));

#endif