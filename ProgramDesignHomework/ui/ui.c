#include "ui.h"

void UI_Welcome() { 
  printf("Welcome to use 3021 APP\n\n");
}

void UI_MainMenu() { 
  int i, j;
  char oper[6][20] = {"( )1: InputPurchase",
                      "( )2: InputSales", 
                      "( )3: OutputPurchase", 
                      "( )4: OutputSales", 
                      "( )5"};
  printf("Operation List:\n");
  
  printf("Please select the operation you want to perform:");
}

void UI_SubMenu(Menu menu) {}

void UI_Exit() {}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }