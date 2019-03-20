#include <stdio.h>
#include "./utils/linkedlist.h"
#include "global.h"
#include "ui/ui.h"
#include "utils/io.h"

int main() {
  UI_Welcome();
  UI_WaitForNext(UI_Clear);

  UI_MainMenu();

  while (menuNow != MENU_Exit) {
    UI_SubMenu(menuNow);
  }

  UI_Exit();
  return 0;
}