#include "ui.h"

void UI_Welcome() {}

void UI_MainMenu() {}

void UI_SubMenu(Menu menu)
{
	char ch;
	if (menu == MENU_) {
		printf("1.��ȡ\n");
		printf("2.���\n");
		printf("3.ɾ��\n");
		ch = getch();
		switch (ch)
		{
			case '1':
				
				system("cls");
				break;
			case '2':
				
				system("cls"); 
				break;
			case '3':
				
				system("cls"); 
				break;
			case '4':
				
				system("cls"); 
				break;
		}
	}
	if (menu == MENU_) {
		switch (ch)
		{
		case '1':break;
		case '2':break;
		case '3':break;
		case '4':break;
		}
	}
	if (menu == MENU_) {
		switch (ch)
		{
		case '1':break;
		case '2':break;
		case '3':break;
		case '4':break;
		}
	}
	if (menu == MENU_) {
		switch (ch)
		{
		case '1':break;
		case '2':break;
		case '3':break;
		case '4':break;
		}
	}

}

void UI_Exit() {}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }