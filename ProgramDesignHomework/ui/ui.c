#include "ui.h"
#include "../data/purchase.h"

Menu menuNow = MENU_Welcome;

void gotoxy(int x, int y) {
  HANDLE a;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cos = { x,y };
  SetConsoleCursorPosition(a, cos);
}//光标定位函数

void UI_Welcome() { 
  printf("\n\nWelcome to use 3021 APP\n\n");
  Sleep(1000);
  system("cls");
}

Menu UI_MainMenu() { 
  int i, floor=1;
  char ch1, ch2;
  char oper[6][20] =
  { "1: 进货记录",
    "2: 销售记录",
    "3: 库存",
    "4: 金额"};
  printf("Operation List:\n");
  for (i = 0; i < 4; i++)  printf("[ ]%s\n", oper[i]);
  gotoxy(2, 1);
  printf("\b*]%s",oper[0]);
  while ((ch1 = _getch()) != '1') {
    ch2 = _getch();
    if (ch2 == 80) {
      if (floor < 4) {
        gotoxy(2, floor);
        printf("\b ]%s", oper[floor - 1]);
        floor++;
        gotoxy(2, floor);
        printf("\b*]%s", oper[floor - 1]);
      }
    }
    if (ch2 == 72) {
      if (floor > 1) {
        gotoxy(2, floor);
        printf("\b ]%s", oper[floor - 1]);
        floor--;
        gotoxy(2, floor);
        printf("\b*]%s", oper[floor - 1]);
      }
    }
  }
  printf("Please select the operation you want to perform:");
}

Menu UI_SubMenu(Menu menu)//二级目录及执行
{
  printf("[ ]读取目前记录\n");
  printf("[ ]添加记录\n");
  printf("[ ]查找指定记录\n");
  printf("[ ]返回上一级\n");
  int y=OptionBar(4);
  LinkedListNode* p;
  if (menu == MENU_Purchase)
  {
    switch (y) {
    case 0:
      for (p = purchase.top; p != NULL; p = p->next)
      {
        printf(Print);
        printf(PrintPurchase(p, 1));
      }
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      return MENU_Main;
    }
    return MENU_Purchase;
  }
  if (menu == MENU_Sales)
  {
    switch (y) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      return MENU_Main;
    }
    return MENU_Sales;
  }
}

int OptionBar(int length) {
  int x = 1, y = 0;
  gotoxy(x, y);
  printf("*");
  char ch;
  while (1)
  {
    char c = _getch();
    if (c == 13) break;
    if (c < 0)
    {
      ch = _getch();
      switch (ch) {
      case 72:
        if (y > 0) {
          gotoxy(x, y);
          printf(" ");
          y--;
          gotoxy(x, y);
          printf("*");
        }
        break;
      case 80:
        if (y < length-1) {
          gotoxy(x, y);
          printf(" ");
          y++;
          gotoxy(x, y);
          printf("*");
        }
      }
    }
  }
  system("cls");
  return y;
}

void UI_Exit() {
// 
}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }