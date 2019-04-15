#include <stdio.h>
#include "global.h"
#include "./utils/linkedlist.h"
#include "ui/ui.h"
#include "utils/io.h"
#include "utils/utils.h"

/**
 * 主函数
 */
int main() {
  Initial();

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