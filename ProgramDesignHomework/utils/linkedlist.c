#include "linkedlist.h"
#include <malloc.h>
#include <stdio.h>
LinkedList CreateLinkedList(void) {  //���������
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

void DeleteLinkedList(LinkedList list, bool *callback(LinkedListNode *)) {
  LinkedListNode *p,*p0;
  p0 = NULL;
  for (p = list.top; p != NULL; p0 = p,p = p->next) {
    if (callback(p)) {
      p0->next = p->next;  //ɾ��p0��ָ��
      free(p->next);  //�ͷſռ�
      p = p0;              //ָ��ɾ�������һ��
    }
  }
}
void InsertLinkList(LinkedListNode *p, LinkedListNode *r,
                    LinkedListNode *p0) {  // pΪǰһ��,rΪ�����p0Ϊ��һ��
  r->next = p0;
  p->next = r;
  p = r;
}