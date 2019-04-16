#include "linkedlist.h"
#include <stdlib.h>

LinkedList *CreateLinkedList() {  //定义空链表
  LinkedList *data = (LinkedList *)malloc(sizeof(LinkedList));
  data->rear = NULL;
  data->top = NULL;
  return data;
}

void FreeLinkedList(LinkedList *list) {
  for (LinkedListNode *node = list->top; node != NULL; node = list->top) {
    DeleteLinkedList(list, 1);
  }
  free(list);
}

void InsertLinkedList(LinkedList *list, void *data) {  //目标链表  存储数据
  LinkedListNode *p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  p->data = data;
  if (list->rear == NULL) {  // 首结点
    list->top = p;
    list->rear = p;
  }
  else {  //下一节点
    list->rear->next = p;
    list->rear = p;
  }
  list->rear->next = NULL;
}

void DeleteLinkedList(LinkedList *list, int key) {//删除链表：目标结点 判断函数（值真为删除目标）
  LinkedListNode *p, *p0;
  p0 = NULL;
  int count = 1;

  for (p = list->top; p != NULL; p0 = p, p = p->next) {
    if (count == key) {
      if (p0 != NULL) {
        if (p != list->rear) {
          p0->next = p->next;  //删除p0所指项
          p = p0->next;  //指向删除项的下一项
        }
        else {
          list->rear = p0;
          p = NULL;
        }
        break;
      }
      else {
        if (p != list->rear) {
          list->top = p->next;
          p->next = NULL;
        }
        else {
          list->top = NULL;
          free(p);
          list->rear = NULL;
        }
        break;
      }
    }
    count++;
  }
}

LinkedList* FindLinkedList(LinkedList *list, bool *callback(LinkedListNode *)) {
  LinkedList*  result = CreateLinkedList();
  int count = 1;
  for (LinkedListNode *p = list->top; p != NULL; p = p->next) {
    if (callback(p)) {
      LinkedListResult* res = (LinkedListResult*)malloc(sizeof(LinkedListResult));
      res->count = count;
      res->res0 = p;
      InsertLinkedList(result, res);
    }
    count++;
  }
  return result;
}

LinkedListNode* AtLinkedList(LinkedList * list, int pos)
{
  LinkedListNode * node = list->top;
  for (int i = 0; i < pos; i++, node = node->next) {
    if (node == NULL) return NULL;
  }
  return node;
}


size_t LengthLinkedList(LinkedList *list) {
  size_t len = 0;
  LinkedListNode *node = list->top;
  while (node != NULL) {
    node = node->next;
    len++;
  }
  return len;
}

LinkedList* MapLinkedList(LinkedList *list, void** callback(LinkedListNode*)) {
  LinkedList *ans = CreateLinkedList();
  for (LinkedListNode *node = list->top; node != NULL; node = node->next) {
    InsertLinkedList(ans, callback(node));
  }
  return ans;
}

void* UnpackLinkedListResult(LinkedListNode* node) {
  return ((LinkedListResult*)node->data)->res0->data;
}