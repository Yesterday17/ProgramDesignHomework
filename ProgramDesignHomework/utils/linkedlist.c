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
  LinkedListNode *p;
  p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  p->data = data;
  if (list.rear == NULL) {  // �׽��
    list.top = p;
    list.rear = p;
  } else {  //��һ�ڵ�
    list.rear->next = p;
    list.rear = p;
  }
}

LinkedListNode* DeleteLinkedList(LinkedList list, bool *callback(LinkedListNode *)) {//ɾ������Ŀ���� �жϺ�����ֵ��Ϊɾ��Ŀ�꣩
  LinkedListNode *p,*p0;
  p0 = NULL;
  for (p = list.top; p != NULL; p0 = p,p = p->next) {
    if (callback(p)) {
      p0->next = p->next;  //ɾ��p0��ָ��
      free(p->next);  //�ͷſռ�
      p = p0;  //ָ��ɾ�������һ��
      break;  
    }
  }
  return p;
}