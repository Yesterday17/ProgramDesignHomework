#include <stdio.h>
#include "global.h"
#include "./utils/linkedlist.h"
#include "ui/ui.h"
#include "utils/io.h"

void FS_Init() {
  globalComponentLinkedList = ReadComponentJSON(COMPONENT_FILENAME);
  sales = ReadSalesJSON(SALES_FILENAME);
  purchase = ReadPurchaseJSON(PURCHASE_FILENAME);
  globalStorage = MapLinkedList(globalComponentLinkedList, EmptySizeLinkedListCallback);

  // 初始化库存
  for (LinkedListNode *node = purchase->top; node != NULL; node = node->next) {
    Purchase *purchase = node->data;
    ((int*)(AtLinkedList(globalStorage, purchase->component)->data))[0] += purchase->quantity;
  }

  for (LinkedListNode *node = sales->top; node != NULL; node = node->next) {
    Sales *sales = node->data;
    ((int*)(AtLinkedList(globalStorage, sales->component)->data))[0] -= sales->quantity;

    if (sales->gift != -1)
      ((int*)(AtLinkedList(globalStorage, sales->gift)->data))[0]--;
  }

  // 初始化资金
  globalFunds = 500000000;
  for (LinkedListNode *node = purchase->top; node != NULL; node = node->next) {
    Purchase *purchase = node->data;
    globalFunds -= purchase->total;
    purchaseFunds += purchase->total;
  }

  for (LinkedListNode *node = sales->top; node != NULL; node = node->next) {
    Sales *sales = node->data;
    globalFunds += sales->total;
    salesFunds += sales->total;
  }
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