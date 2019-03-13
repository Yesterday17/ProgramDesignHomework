#include "linkedlist.h"
#include <malloc.h>
#include <stdio.h>

LinkedList CreateLinkedList(void) {  //定义空链表
  LinkedListNode *top, *rear;
  top = NULL;
  rear = NULL;
  LinkedList data;
  data.rear = rear;
  data.top = top;
  return data;
}

void InsertLinkedList(LinkedList list, void *data) {  //目标链表  存储数据
  LinkedListNode *p;
  p = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  p->data = data;
  if (list.rear == NULL) {  // 首结点
    list.top = p;
    list.rear = p;
  } else {  //下一节点
    list.rear->next = p;
    list.rear = p;
  }
}

LinkedListNode* DeleteLinkedList(LinkedList list, bool *callback(LinkedListNode *)) {//删除链表：目标结点 判断函数（值真为删除目标）
  LinkedListNode *p,*p0;
  p0 = NULL;
  for (p = list.top; p != NULL; p0 = p,p = p->next) {
    if (callback(p)) {
      p0->next = p->next;  //删除p0所指项
      free(p->next);  //释放空间
      p = p0;  //指向删除项的下一项
      break;  
    }
  }
  return p;
}