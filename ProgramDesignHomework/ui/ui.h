#pragma once

typedef enum {
  MENU_Exit = -1,
  MENU_Welcome = 0,
  MENU_Main = 1,
} Menu;

#ifndef UNIT_TEST

void UI_Welcome();

void UI_MainMenu();

void UI_SubMenu(Menu menu);

void UI_Exit();

void UI_Clear();

void UI_WaitForNext(void* nextDo());

#endif