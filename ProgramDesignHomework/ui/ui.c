#include "ui.h"
#include "../data/purchase.h"

#define hangshu 10//��¼�������
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

Menu UI_SubMenu(Menu menu)//����Ŀ¼��ִ��
{
  printf("[ ]��ȡĿǰ��¼\n");
  printf("[ ]��Ӽ�¼\n");
  printf("[ ]����ָ����¼\n");
  printf("[ ]������һ��\n");
  int y=OptionBar(1,4);
  if (menu == MENU_Purchase)
  {
    switch (y) {
    case 0:
      RecordPage(purchase, PrintPurchaseTitle, PrintPurchase);
      y = OptionBar(2, 2 + hangshu-1);
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

int OptionBar(int start,int end) {//startΪ��ʼ�У�endΪ��ֹ��
  int x = 1, y = start-1;
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
        if (y > start-1) {
          gotoxy(x, y);
          printf(" ");
          y--;
          gotoxy(x, y);
          printf("*");
        }
        break;
      case 80:
        if (y < end-1) {
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

void RecordPage(LinkedList data,char* title,char* record) {
  LinkedListNode *p, *re[100];
  int count = 1, j = 0;
  char a, b;
  p = data.top;
  re[0] = data.top;
  printf(title);
  while (1)
  {

    if ((count - 1) % hangshu == 0 && count != 1 || p == data.rear->next) {


      if (p == data.rear->next && (count - 1) % hangshu != 0) {
        count = (count + hangshu-1) / hangshu * hangshu + 1;
      }
      a = _getch();
      if (a < 0) {
        b = _getch();
        if (b == 75 && count > 1+hangshu) {
          system("cls");
          printf(title);
          count -= hangshu;
          if (j > 0)
            j--;
          p = re[j];
        }
        else if (b == 77 && p != data.rear->next) {
          j++;
          re[j] = p;
          system("cls");
          printf(title);
        }
        else
          continue;
      }
    }
    printf("[ ]");
    printf(record);
    p = p->next;
    count++;
  }
  system("pause>nul");
}

void UI_Exit() {
// 
}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }