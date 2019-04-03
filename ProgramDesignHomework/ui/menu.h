#pragma once
#include <stdint.h>

typedef struct {
  char* name;
}UI_Menu_Item;

typedef struct {
  uint8_t now;
  uint8_t total;
  UI_Menu_Item* items;
}UI_Menu;

#ifndef UNIT_TEST

UI_Menu* NewMenu(uint8_t total, UI_Menu_Item** items);
UI_Menu_Item** NewMenuItems(char** names);

uint8_t ListenMenu(UI_Menu* menu);

#endif