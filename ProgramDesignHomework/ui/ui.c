#include "ui.h"

void UI_Welcome() { 
  printf("Welcome to use 3021 APP\n\n");
}

void UI_MainMenu() { 
  int i, floor=1;
  char ch1, ch2;
  char oper[6][20] =
  { "1: ������¼",
    "2: ���ۼ�¼",
    "3: ���",
    "4: ���"};
  printf("Operation List:\n");
  for (i = 0; i < 4; i++)  printf("[ ]%s", oper[i]);
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

void UI_SubMenu(Menu menu)
{
	char ch;
  if (menu == MENU_Main) UI_MainMenu();
	if (menu == MENU_) {
		printf("1.��ȡ\n");
		printf("2.���\n");
		printf("3.ɾ��\n");
    printf("4.����\n");
		ch = getch();
		switch (ch)
		{
			case '1':
				system("cls");
				//������¼
        
				break;
			case '2':
				system("cls"); 
				//��ӽ���
				break;
			case '3':
				system("cls"); 
				//ɾ������
				break;
			case '4':
				//���ҽ���
				system("cls"); 
				break;
		}
	}
	if (menu == MENU_) {
     printf("1.��ȡ\n");
     printf("2.���\n");
     printf("3.ɾ��\n");
     printf("4.����\n");
     ch = getch();
		switch (ch)
		{
		case '1':
      //��ȡ����
      break;
		case '2':
      //�������
      break;
		case '3':
      //ɾ������
      break;
		case '4':
      //��������
      break;
		}
	}
	
}

void UI_Exit() {}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }