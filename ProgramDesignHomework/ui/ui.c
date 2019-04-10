#include "ui.h"
#include "../data/purchase.h"
#include"../data/sales.h"

#define hangshu 10//记录每页最大行数
Menu menuNow = MENU_Welcome;

void UI_Welcome() {
  printf("\n\nWelcome to use 3021 APP\n\n");
  Sleep(1000);
  cls();
}

Menu UI_MainMenu() {
  int i, floor = 1;
  char ch1, ch2;
  char oper[6][20] =
  { "1: 进货记录",
    "2: 销售记录",
    "3: 库存",
    "4: 金额" };
  printf("Operation List:\n");
  for (i = 0; i < 4; i++)  printf("[ ]%s\n", oper[i]);
  printf("Please select the operation you want to perform:");
  gotoxy(2, 1);
  printf("\b*]%s", oper[0]);
  while ((ch1 = _getch()) != 13) {
    ch2 = _getch();
    if (ch2 == 80) {
      if (floor < 4) {
        gotoxy(2, floor);
        printf("\b ]%s", oper[floor - 1]);
        floor++;
        gotoxy(2, floor);
        printf("\b*]%s", oper[floor - 1]);
      }
    }
    if (ch2 == 72) {
      if (floor > 1) {
        gotoxy(2, floor);
        printf("\b ]%s", oper[floor - 1]);
        floor--;
        gotoxy(2, floor);
        printf("\b*]%s", oper[floor - 1]);
      }
    }
  }
  cls();
  if (floor == 1) return MENU_Purchase;
  else if (floor == 2) return MENU_Sales;

}

Menu UI_SubMenu(Menu menu)//二级目录及执行
{
  int record;//选中记录
  if (menu == MENU_Purchase)
  {
    printf("[ ]读取目前记录\n");
    printf("[ ]添加记录\n");
    printf("[ ]查找指定记录\n");
    printf("[ ]返回上一级\n");
    int y = OptionBar(1, 4);
    cls();
    switch (y) {
    case 0:
      if (purchase->rear != NULL) {
        record = RecordPage(purchase, PrintPurchaseTitle(), PrintPurchase);
        gotoxy(1, 1 + hangshu);
        printf("修改记录Enter   删除记录Delete\n");
        while (1) {
          char key1 = _getch();
          char key2 = 0;
          if (key1 == 13) {//enter
            //DeleteLinkedList(purchase, );
            cls();
            InsertLinkedList(purchase, ReadPurchase());
            break;
          }
          if (key1 < 0) {
            key2 = _getch();
            if (key2 == 83) {//delete
              //DeleteLinkedList(purchase, );
              break;
            }
          }
        }
      }
      else {
        printf("该记录为空，按回车返回上一级");
        while (1) {
          char ch = _getch();
          if (ch == 13)break;
        }
        cls();
      }
      break;
    case 1:
      InsertLinkedList(purchase, ReadPurchase());
      cls();
      break;
    case 2:
      printf("[ ]1.按配件种类检索\n");
      printf("[ ]2.按供货商检索\n");
      printf("[ ]3.按时间范围检索\n");
      OptionBar(1, 3);
      cls();
      break;
    case 3:
      return MENU_Main;
    }
    return MENU_Purchase;
  }
  if (menu == MENU_Sales)
  {
    printf("[ ]读取目前记录\n");
    printf("[ ]添加记录\n");
    printf("[ ]查找指定记录\n");
    printf("[ ]统计赠品\n");
    printf("[ ]返回上一级\n");
    int y = OptionBar(1, 5);
    cls();
    switch (y) {
    case 0:
      if (sales->rear != NULL) {
        record = RecordPage(sales, PrintSalesTitle(), PrintSales);
        gotoxy(1, 1 + hangshu);
        printf("修改记录Enter   删除记录Delete\n");
        
        while (1) {
          char key1 = _getch();
          char key2 = 0;
          if (key1 == 13) {//enter
            //DeleteLinkedList(sales, );
            cls();
            InsertLinkedList(sales, ReadSales());
            break;
          }
          if (key1 < 0) {
            key2 = _getch();
            if (key2 == 83) {//delete
              cls();
              //DeleteLinkedList(sales, );
              break;
            }
          }
          
        }
      }
      else {
        printf("该记录为空，按回车返回上一级");
        while (1) {
          char ch = _getch();
          if (ch == 13)break;
        }
        cls();
      }
      break;
    case 1:
      InsertLinkedList(sales, ReadSales());
      cls();
      break;
    case 2:
      printf("[ ]1.按配件种类检索\n");
      printf("[ ]2.按客户检索\n");
      printf("[ ]3.按时间范围检索\n");
      int y = OptionBar(1, 3);
      cls();
      break;
    case 3:
      //
      break;
    case 4:
      return MENU_Main;
    }
    return MENU_Sales;
  }
}

int OptionBar(int start, int end) {//start为起始行，end为终止行
  int x = 1, y = start - 1;
  gotoxy(x, y);
  printf("*");
  char ch;
  while (1)
  {
    char c = _getch();
    if (c == 13) break;//回车退出
    if (c < 0)
    {
      ch = _getch();
      switch (ch) {
      case 72:
        if (y > start - 1) {
          gotoxy(x, y);
          printf(" ");
          y--;
          gotoxy(x, y);
          printf("*");
        }
        break;
      case 80:
        if (y < end - 1) {
          gotoxy(x, y);
          printf(" ");
          y++;
          gotoxy(x, y);
          printf("*");
        }
      }
    }
  }
  return y;
}

void gotoxy(int x, int y) {
  HANDLE a;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cos = { x,y };
  SetConsoleCursorPosition(a, cos);
}//光标定位函数

int RecordPage(LinkedList* data, char* title, char* record(void*, uint8_t)) { //记录翻页函数
  LinkedListNode *p, *re[100];//目标节点，分页数组
  int num = 0, count = 1, j = 0, y = 0;//序号，计数器，页码，选中行
  char a, b;//读取按键ascii码
  int end;//最终记录条数+1
  p = data->top;
  re[0] = data->top;
  printf(title);
  while (1)
  {

    if ((count - 1) % hangshu == 0 && count != 1 || p == data->rear->next) {

      end = count;
      if (p == data->rear->next && (count - 1) % hangshu != 0) {
        count = (count + hangshu - 1) / hangshu * hangshu + 1;//进位取整+1：如39->41
      }
      a = _getch();
      if (a < 0) {
        b = _getch();
        if (b == 75 && count > 1 + hangshu) {//左翻页
          cls();
          printf(title);
          count -= hangshu;
          if (j > 0)
            j--;
          p = re[j];
        }
        else if (b == 77 && p != data->rear->next) {//右翻页
          j++;
          re[j] = p;
          cls();
          printf(title);
        }
        else//锁定其他按键
          continue;
      }
      if (a == 13)break;//回车退出
    }
    num++;
    printf("[ ]");
    printf(record(p->data, num));
    p = p->next;
    count++;
  }
  int count0 = end;//拷贝（真实记录行数+1）
  if ((count0 - 1) % hangshu == 0) {
    y = OptionBar(2, 2 + hangshu - 1);
  }
  else
  {
    if (count0 > hangshu) {
      count0 = count0 - (count0 / hangshu * hangshu) - 1;//记录末页行数：如记录38条，末页8行
    }
    y = OptionBar(2, 2 + count0 - 1);
  }
  return j * hangshu + y;
}

void cls()
{
  HANDLE hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coordScreen = { 0, 0 };    // home for the cursor 
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  // Get the number of character cells in the current buffer. 

  if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
  {
    return;
  }

  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  // Fill the entire screen with blanks.

  if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
    (TCHAR) ' ',     // Character to write to the buffer
    dwConSize,       // Number of cells to write 
    coordScreen,     // Coordinates of first cell 
    &cCharsWritten))// Receive number of characters written
  {
    return;
  }

  // Get the current text attribute.

  if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
  {
    return;
  }

  // Set the buffer's attributes accordingly.

  if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
    csbi.wAttributes, // Character attributes to use
    dwConSize,        // Number of cells to set attribute 
    coordScreen,      // Coordinates of first cell 
    &cCharsWritten)) // Receive number of characters written
  {
    return;
  }

  // Put the cursor at its home coordinates.

  SetConsoleCursorPosition(hConsole, coordScreen);
}

void UI_Exit() {
  // 
}

void UI_Clear() {}

void UI_WaitForNext(void* nextDo()) { nextDo(); }