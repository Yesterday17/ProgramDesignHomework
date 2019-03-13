#include "linkedlist.h"
#include <stdio.h>
void *CreateLinkedList(void *data) {
  ComponentList *head, *p, *q;
  p = head;
  p->next = NULL;
  p->data = data;
}
void DeleteLinkedList(ComponentList *p, ComponentList *p0) {
  p0 = p0->next;   //删除p0所指项
  free(p->next);   //释放空间
  p->next = p0;    //指向删除项的下一项
}
void InsertLinkList(ComponentList *p,ComponentList *r,ComponentList *p0){//p为前一项,r为插入项，p0为后一项
     r->next=p0;
     p->next=r;
     p = r;

}