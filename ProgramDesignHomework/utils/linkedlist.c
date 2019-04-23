/*
 * MIT License
 *
 * Copyright (c) 2019 Yesterday17 and ProgramDesignHomework contributors
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#include "linkedlist.h"
#include <stdlib.h>

//创建空链表函数
LinkedList *CreateLinkedList() {  
  LinkedList *data = (LinkedList *)malloc(sizeof(LinkedList));
  data->rear = NULL;
  data->top = NULL;
  return data;
}

//释放链表内存函数
void FreeLinkedList(LinkedList *list) {
  for (LinkedListNode *node = list->top; node != NULL; node = list->top) {
    DeleteLinkedList(list, 1);
  }
  free(list);
}

 //插入链表（目标，存储数据（指针））
void InsertLinkedList(LinkedList *list, void *data) { 
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

//删除链表：目标结点 判断函数（值真为删除目标）
void DeleteLinkedList(LinkedList *list, int key) {
  LinkedListNode *p, *p0;
  p0 = NULL;
  int count = 1;

  for (p = list->top; p != NULL; p0 = p, p = p->next) {
    if (count == key) {
      if (p0 != NULL) {
        if (p != list->rear) {//1.p在链表中间
          p0->next = p->next;  //删除p0所指项
          p = p0->next;  //指向删除项的下一项
        }
        else {//2.p在链表尾部
          list->rear = p0;
          p = NULL;
        }
        break;
      }
      else {
        if (p != list->rear) {//3.p在链表首部
          list->top = p->next;
          p->next = NULL;
        }
        else {//4.链表只有一个节点时
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

//查找链表节点函数
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

//指定链表结点位置函数
LinkedListNode* AtLinkedList(LinkedList * list, int pos)
{
  LinkedListNode * node = list->top;
  for (int i = 0; i < pos; i++, node = node->next) {
    if (node == NULL) return NULL;
  }
  return node;
}

//求链表长度函数
int LengthLinkedList(LinkedList *list) {
  size_t len = 0;
  LinkedListNode *node = list->top;
  while (node != NULL) {
    node = node->next;
    len++;
  }
  return len;
}

//基于一个链表实现另一个链表函数
LinkedList* MapLinkedList(LinkedList *list, void** callback(LinkedListNode*)) {
  LinkedList *ans = CreateLinkedList();
  for (LinkedListNode *node = list->top; node != NULL; node = node->next) {
    InsertLinkedList(ans, callback(node));
  }
  return ans;
}

//解压链表内容函数
void* UnpackLinkedListResult(LinkedListNode* node) {
  return ((LinkedListResult*)node->data)->res0->data;
}

//生成长度相同内容为0的链表函数
int* EmptySizeLinkedListCallback(LinkedListNode *node) {
  int *count = (int*)malloc(sizeof(int));
  count[0] = 0;
  return count;
}