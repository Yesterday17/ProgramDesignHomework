#pragma once
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include "../global.h"

typedef enum {
  MENU_Exit = -1,
  MENU_Welcome = 0,
  MENU_Main = 1,
  MENU_Purchase = 2,
  MENU_Sales = 3,
} Menu;

#ifndef UNIT_TEST

void UI_Welcome();

Menu UI_MainMenu();

Menu UI_SubMenu(Menu menu);

void UI_Exit();

void UI_Clear();

void UI_WaitForNext(void* nextDo());

void gotoxy(int x, int y);

int OptionBar(int start,int end);

void RecordPage();

extern Menu menuNow;

#endif
