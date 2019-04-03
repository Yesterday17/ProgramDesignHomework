#include "ui.h"

Menu menuNow = MENU_Welcome;

void gotoxy(int x, int y) {
  HANDLE a;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cos = { x,y };
  SetConsoleCursorPosition(a, cos);
}//��궨λ����

void UI_Welcome() { 
  printf("\n\nWelcome to use 3021 APP\n\n");
  Sleep(1000);
  system("cls");
}

Menu UI_MainMenu() { 
  int i, floor=1;
  char ch1, ch2;
  char oper[6][20] =
  { "1: ������¼",
    "2: ���ۼ�¼",
    "3: ���",
    "4: ���"};
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

Menu UI_SubMenu(Menu menu)
{
  printf("[ ]1.��ȡĿǰ��¼\n");
  printf("[ ]2.��Ӽ�¼\n");
  printf("[ ]3.�޸ļ�¼\n");
  printf("[ ]4.ɾ����¼\n");
  printf("[ ]5.����ָ����¼\n");
  printf("[ ]6.������һ��\n");
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
        if (y < 5) {
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
  if (menu == MENU_Purchase)
  {
    switch (y) {
    case 0:

      break;
    case 1:
      system("cls");
      break;
    case 2:

      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
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
      break;
    case 4:
      break;
    case 5:
      return MENU_Main;
    }
    return MENU_Sales;
  }
}

void UI_Exit() {
// 
}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }