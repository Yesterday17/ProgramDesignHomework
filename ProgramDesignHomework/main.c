#include <stdio.h>
#include "global.h"
#include "./utils/linkedlist.h"
#include "ui/ui.h"
#include "utils/io.h"
#include "utils/utils.h"

void FS_Init() {
  component = CreateLinkedList();
  sales = ReadSalesJSON(LITERAL("D:\\sales.json"));
  purchase = ReadPurchaseJSON(LITERAL("purchase.json"));
}

int main() {
  // 初始化
  UI_Init();
  FS_Init();

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