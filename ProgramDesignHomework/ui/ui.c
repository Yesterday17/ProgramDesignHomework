#include "ui.h"

void UI_Welcome() { 
  printf("Welcome to use 3021 APP\n\n");
}

void UI_MainMenu() { 
  int i, floor=1;
  char ch1, ch2;
  char oper[6][20] =
  { "1: 进货记录",
    "2: 销售记录",
    "3: 库存",
    "4: 金额"};
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