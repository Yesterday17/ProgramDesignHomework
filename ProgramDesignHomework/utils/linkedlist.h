#ifndef _UTILS_LINKEDLIST_H_
#define _UTILS_LINKEDLIST_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct LinkedListNode {  //链表结点
  void *data;
  struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {  // 链表指针
  LinkedListNode *top;
  LinkedListNode *rear;
} LinkedList;


typedef struct LinkedlistResult {
  LinkedListNode* res0;
  int count;
}LinkedListResult;

LinkedList *CreateLinkedList();
void FreeLinkedList(LinkedList *list);

void InsertLinkedList(LinkedList *list, void *data);
void DeleteLinkedList(LinkedList *list, int key);
LinkedList* FindLinkedList(LinkedList *list, bool *callback(LinkedListNode *));
LinkedListNode *AtLinkedList(LinkedList *list, int pos);
int LengthLinkedList(LinkedList *list);
LinkedList* MapLinkedList(LinkedList *list, void** callback(LinkedListNode*));

void* UnpackLinkedListResult(LinkedListNode *node);
int* EmptySizeLinkedListCallback(LinkedListNode *node);
#endif