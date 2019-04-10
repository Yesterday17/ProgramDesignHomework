#include <stdio.h>
#include "./utils/linkedlist.h"
#include "global.h"
#include "ui/ui.h"
#include "utils/io.h"
int main() {
  srand((unsigned)(time(NULL)));

  component = CreateLinkedList();
  purchase = CreateLinkedList();
  sales = CreateLinkedList();

  UI_Welcome();
  
  menuNow = MENU_Welcome;
  while (menuNow != MENU_Exit)
  {
    menuNow = UI_MainMenu();
    menuNow = MENU_Sales;
    while (menuNow != MENU_Main) {

      menuNow = UI_SubMenu(menuNow);
    }
  }
  UI_Exit();
  return 0;
}