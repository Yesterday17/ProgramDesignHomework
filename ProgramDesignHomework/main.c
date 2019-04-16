﻿#include <stdio.h>
#include "global.h"
#include "./utils/linkedlist.h"
#include "ui/ui.h"
#include "utils/io.h"

void FS_Init() {
  component = ReadComponentJSON(COMPONENT_FILENAME);
  sales = ReadSalesJSON(SALES_FILENAME);
  purchase = ReadPurchaseJSON(PURCHASE_FILENAME);
}

void GLOBAL_Init() {
  nameToSearch = newString("");
  timeToSearchearly = 0;
  timeToSearchlate = 0;
  customerToSearch = newString("");
  retailerToSearch = newString("");
  typeToSearch = newString("");
  manufacturerToSearch = newString("");
}

int main() {
  // 初始化
  UI_Init();
  FS_Init();
  GLOBAL_Init();

  // 欢迎
  UI_Welcome();
  menuNow = MENU_Welcome;
  while (1) {
    menuNow = UI_MainMenu();
    if (menuNow == MENU_Exit)
      break;
    while (menuNow != MENU_Main) {

      menuNow = UI_SubMenu(menuNow);
    }
  }
  UI_Exit();
  return 0;
}