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
void InsertLinkedList(LinkedList list, void *data) {  //Ŀ������  �洢����
  LinkedListNode *top, *rear, *p;
  p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  p->data = data;
  if (rear == NULL) {  // �׽��
    top = p;
    rear = p;
  } else {  //��һ�ڵ�
    rear->next = p;
    rear = p;
  }
  list.top = top;
  list.rear = rear;
  return;
}

void DeleteLinkedList(LinkedListNode *p, LinkedListNode *p0) {
  p0 = p0->next;  //ɾ��p0��ָ��
  free(p->next);  //�ͷſռ�
  p->next = p0;   //ָ��ɾ�������һ��
}
void InsertLinkList(LinkedListNode *p, LinkedListNode *r,
                    LinkedListNode *p0) {  // pΪǰһ��,rΪ�����p0Ϊ��һ��
  r->next = p0;
  p->next = r;
  p = r;
}