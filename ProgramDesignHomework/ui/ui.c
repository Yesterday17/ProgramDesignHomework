#include "ui.h"

void UI_We  lcome() { 
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