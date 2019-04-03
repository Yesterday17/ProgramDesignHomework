#include "linkedlist.h"

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
  }
  else {  //��һ�ڵ�
    list.rear->next = p;
    list.rear = p;
  }
}

LinkedListNode* DeleteLinkedList(LinkedList list, bool *callback(LinkedListNode *)) {//ɾ������Ŀ���� �жϺ�����ֵ��Ϊɾ��Ŀ�꣩
  LinkedListNode *p, *p0;
  p0 = NULL;
  for (p = list.top; p != NULL; p0 = p, p = p->next) {
    if (callback(p)) {
      p0->next = p->next;  //ɾ��p0��ָ��
      free(p->next);  //�ͷſռ�
      p = p0;  //ָ��ɾ�������һ��
      break;
    }
  }
  return p;
}

LinkedListFindResult FindLinkedList(LinkedList list, bool* callback(LinkedListNode*)) {
	LinkedListNode *p;
	LinkedListFindResult res;
	res.count = 0;
	int a = 100;
	res.result = (LinkedListNode **)malloc(sizeof(LinkedListNode*)*a);
	for (p = list.top; p != NULL;p = p->next) {
		if (callback(p)) {
			res.result[res.count] = p;
			res.count++;
		}
		if (res.count + 1 == 100) {
			a *= 2;
			res.result = realloc(res.result, sizeof(LinkedListNode*)*a);
		}
	}
	return res;
}