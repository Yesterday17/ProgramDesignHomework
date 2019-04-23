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

#ifndef _UTILS_LINKEDLIST_H_
#define _UTILS_LINKEDLIST_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct LinkedListNode {  //链表结点
  void *data;
  struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {  // 链表指针
  LinkedListNode *top;
  LinkedListNode *rear;
} LinkedList;


typedef struct LinkedlistResult {//（销售，进货）链表查找结果
  LinkedListNode* res0;
  int count;
}LinkedListResult;

LinkedList *CreateLinkedList();
void FreeLinkedList(LinkedList *list);

void InsertLinkedList(LinkedList *list, void *data);
void DeleteLinkedList(LinkedList *list, int key);
LinkedList* FindLinkedList(LinkedList *list, bool *callback(LinkedListNode *));
LinkedListNode *AtLinkedList(LinkedList *list, int pos);
int LengthLinkedList(LinkedList *list);
LinkedList* MapLinkedList(LinkedList *list, void** callback(LinkedListNode*));

void* UnpackLinkedListResult(LinkedListNode *node);
int* EmptySizeLinkedListCallback(LinkedListNode *node);
#endif