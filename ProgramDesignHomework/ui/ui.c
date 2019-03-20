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
		printf("1.读取\n");
		printf("2.添加\n");
		printf("3.删除\n");
    printf("4.查找\n");
		ch = getch();
		switch (ch)
		{
			case '1':
				system("cls");
				//进货记录
        
				break;
			case '2':
				system("cls"); 
				//添加进货
				break;
			case '3':
				system("cls"); 
				//删除进货
				break;
			case '4':
				//查找进货
				system("cls"); 
				break;
		}
	}
	if (menu == MENU_) {
     printf("1.读取\n");
     printf("2.添加\n");
     printf("3.删除\n");
     printf("4.查找\n");
     ch = getch();
		switch (ch)
		{
		case '1':
      //读取销售
      break;
		case '2':
      //添加销售
      break;
		case '3':
      //删除销售
      break;
		case '4':
      //查找销售
      break;
		}
	}
	
}

void UI_Exit() {}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }