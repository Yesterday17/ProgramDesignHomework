/*
 * MIT License
 *
 * Copyright (c) 2019 Yesterday17 and ProgramDesignHomework contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <stdio.h>
#include "global.h"
#include "./utils/linkedlist.h"
#include "ui/ui.h"
#include "utils/io.h"

void FS_Init() {
  globalComponentLinkedList = ReadComponentJSON(COMPONENT_FILENAME);
  sales = ReadSalesJSON(SALES_FILENAME);
  purchase = ReadPurchaseJSON(PURCHASE_FILENAME);

  RefreshStorageFund();
}

void GLOBAL_Init() {
  nameToSearch = newString("");
  timeToSearchearly = 0;
  timeToSearchlate = 0;
  customerToSearch = newString("");
  retailerToSearch = newString("");
  typeToSearch = newString("");
  manufacturerToSearch = newString("");
  NO_Gift = NewComponent();
  freeAssign(&NO_Gift->name, newString("NOT_EXIST"));
  freeAssign(&NO_Gift->type, newString(""));
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