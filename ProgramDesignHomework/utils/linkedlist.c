#include "linkedlist.h"
#include <stdlib.h>

LinkedList *CreateLinkedList() {  //定义空链表
  LinkedListNode *top, *rear;
  top = NULL;
  rear = NULL;
  LinkedList *data = (LinkedList *)malloc(sizeof(LinkedList));
  data->rear = rear;
  data->top = top;
  return data;
}

void InsertLinkedList(LinkedList *list, void *data) {  //目标链表  存储数据
  LinkedListNode *p;
  p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
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
  return NULL;
}

LinkedList* FindLinkedList(LinkedList *list, bool *callback(LinkedListNode *)) {
  LinkedListNode *p;
  LinkedList*  result = CreateLinkedList();
  LinkedListResult* res = (LinkedListResult*)malloc(sizeof(LinkedListResult));
  res->count = 0;
  int count = 1;
  for (p = list->top; p != NULL; p = p->next) {
    if (callback(p)) {
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
