#ifndef _UI_H_
#define _UI_H_

#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "../utils/io.h"
#include "../data/purchase.h"
#include"../data/sales.h"
#include "../global.h"

/**
 * 记录菜单状态的枚举
 */
typedef enum Menu {
  MENU_Exit = -1,
  MENU_Welcome = 0,
  MENU_Main = 1,
  MENU_Purchase = 2,
  MENU_Sales = 3,
  MENU_Stock = 4,
  MENU_Amount = 5,
} Menu;

void Initial();

void UI_Welcome();

Menu UI_MainMenu();

Menu UI_SubMenu(Menu menu);

void UI_Exit();

void UI_Clear();

void UI_WaitForNext(void *nextDo());

void gotoxy(int x, int y);

int OptionBar(int start, int end);

int RecordPage(LinkedList *data, string title, string record(void *, uint8_t));

void cls();

void color();

extern Menu menuNow;

#endif