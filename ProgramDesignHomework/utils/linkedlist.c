#include "linkedlist.h"
#include <stdio.h>
void *CreateLinkedList(void *data) {
  ComponentList *head, *p, *q;
  p = head;
  p->next = NULL;
  p->data = data;
}
void DeleteLinkedList(ComponentList *p, ComponentList *p0) {
  p0 = p0->next;   //ɾ��p0��ָ��
  free(p->next);   //�ͷſռ�
  p->next = p0;    //ָ��ɾ�������һ��
}
void InsertLinkList(ComponentList *p,ComponentList *r,ComponentList *p0){//pΪǰһ��,rΪ�����p0Ϊ��һ��
     r->next=p0;
     p->next=r;
     p = r;

}