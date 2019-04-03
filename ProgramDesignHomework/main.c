#include <stdio.h>
#include "./utils/linkedlist.h"
#include "global.h"
#include "ui/ui.h"
#include "utils/io.h"

int main() {
  UI_Welcome();
  
  menuNow = MENU_Welcome;
  while (menuNow != MENU_Exit)
  {
    //menuNow = UI_MainMenu();
    menuNow = MENU_Purchase;
    while (menuNow != MENU_Main) {

      menuNow = UI_SubMenu(menuNow);
    }
  }
  UI_Exit();
  return 0;
}