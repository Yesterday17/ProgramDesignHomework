#pragma once
void* CreateLinkedList();
// void* FindInLinkedList(function);
typedef struct str {
  struct node* next;
  void* data;
} ComponentList;
