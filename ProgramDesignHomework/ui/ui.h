#pragma once
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

typedef enum {
  MENU_Exit = -1,
  MENU_Welcome = 0,
  MENU_Main = 1,
  MENU_Purchase = 2,
  MENU_Sales = 3,
} Menu;

#ifndef UNIT_TEST

void UI_Welcome();

void UI_MainMenu();

void UI_SubMenu(Menu menu);

void UI_Exit();

void UI_Clear();

void UI_WaitForNext(void* nextDo());

#endif

void gotoxy(int x, int y) {
  HANDLE a;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cos = {x,y};
  SetConsoleCursorPosition(a, cos);
}//光标定位函数
