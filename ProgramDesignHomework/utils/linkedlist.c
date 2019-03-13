#include "linkedlist.h"
#include <malloc.h>
#include <stdio.h>
LinkedList CreateLinkedList(void) {
  LinkedListNode *top, *rear;
  top = NULL;
  rear = NULL;
  LinkedList data;
  data.rear = rear;
  data.top = top;
  return data;
}
void InsertLinkedList(LinkedList list, void *data) {  //目标链表  存储数据
  LinkedListNode *top, *rear, *p;
  p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  p->data = data;
  if (rear == NULL) {  // 首结点
    top = p;
    rear = p;
  } else {  //下一节点
    rear->next = p;
    rear = p;
  }
  list.top = top;
  list.rear = rear;
  return;
}

void DeleteLinkedList(LinkedListNode *p, LinkedListNode *p0) {
  p0 = p0->next;  //删除p0所指项
  free(p->next);  //释放空间
  p->next = p0;   //指向删除项的下一项
}
void InsertLinkList(LinkedListNode *p, LinkedListNode *r,
                    LinkedListNode *p0) {  // p为前一项,r为插入项，p0为后一项
  r->next = p0;
  p->next = r;
  p = r;
}