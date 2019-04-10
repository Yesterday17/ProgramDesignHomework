#include "ui.h"
#include "../data/purchase.h"
#include"../data/sales.h"

#define hangshu 10//��¼ÿҳ�������
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
  { "1: ������¼",
    "2: ���ۼ�¼",
    "3: ���",
    "4: ���" };
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

Menu UI_SubMenu(Menu menu)//����Ŀ¼��ִ��
{
  int record;//ѡ�м�¼
  if (menu == MENU_Purchase)
  {
    printf("[ ]��ȡĿǰ��¼\n");
    printf("[ ]��Ӽ�¼\n");
    printf("[ ]����ָ����¼\n");
    printf("[ ]������һ��\n");
    int y = OptionBar(1, 4);
    cls();
    switch (y) {
    case 0:
      if (purchase->rear != NULL) {
        record = RecordPage(purchase, PrintPurchaseTitle(), PrintPurchase);
        gotoxy(1, 1 + hangshu);
        printf("�޸ļ�¼Enter   ɾ����¼Delete\n");
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
        printf("�ü�¼Ϊ�գ����س�������һ��");
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
      printf("[ ]1.������������\n");
      printf("[ ]2.�������̼���\n");
      printf("[ ]3.��ʱ�䷶Χ����\n");
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
    printf("[ ]��ȡĿǰ��¼\n");
    printf("[ ]��Ӽ�¼\n");
    printf("[ ]����ָ����¼\n");
    printf("[ ]ͳ����Ʒ\n");
    printf("[ ]������һ��\n");
    int y = OptionBar(1, 5);
    cls();
    switch (y) {
    case 0:
      if (sales->rear != NULL) {
        record = RecordPage(sales, PrintSalesTitle(), PrintSales);
        gotoxy(1, 1 + hangshu);
        printf("�޸ļ�¼Enter   ɾ����¼Delete\n");
        
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
        printf("�ü�¼Ϊ�գ����س�������һ��");
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
      printf("[ ]1.������������\n");
      printf("[ ]2.���ͻ�����\n");
      printf("[ ]3.��ʱ�䷶Χ����\n");
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

int OptionBar(int start, int end) {//startΪ��ʼ�У�endΪ��ֹ��
  int x = 1, y = start - 1;
  gotoxy(x, y);
  printf("*");
  char ch;
  while (1)
  {
    char c = _getch();
    if (c == 13) break;//�س��˳�
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
}//��궨λ����

int RecordPage(LinkedList* data, char* title, char* record(void*, uint8_t)) { //��¼��ҳ����
  LinkedListNode *p, *re[100];//Ŀ��ڵ㣬��ҳ����
  int num = 0, count = 1, j = 0, y = 0;//��ţ���������ҳ�룬ѡ����
  char a, b;//��ȡ����ascii��
  int end;//���ռ�¼����+1
  p = data->top;
  re[0] = data->top;
  printf(title);
  while (1)
  {

    if ((count - 1) % hangshu == 0 && count != 1 || p == data->rear->next) {

      end = count;
      if (p == data->rear->next && (count - 1) % hangshu != 0) {
        count = (count + hangshu - 1) / hangshu * hangshu + 1;//��λȡ��+1����39->41
      }
      a = _getch();
      if (a < 0) {
        b = _getch();
        if (b == 75 && count > 1 + hangshu) {//��ҳ
          cls();
          printf(title);
          count -= hangshu;
          if (j > 0)
            j--;
          p = re[j];
        }
        else if (b == 77 && p != data->rear->next) {//�ҷ�ҳ
          j++;
          re[j] = p;
          cls();
          printf(title);
        }
        else//������������
          continue;
      }
      if (a == 13)break;//�س��˳�
    }
    num++;
    printf("[ ]");
    printf(record(p->data, num));
    p = p->next;
    count++;
  }
  int count0 = end;//��������ʵ��¼����+1��
  if ((count0 - 1) % hangshu == 0) {
    y = OptionBar(2, 2 + hangshu - 1);
  }
  else
  {
    if (count0 > hangshu) {
      count0 = count0 - (count0 / hangshu * hangshu) - 1;//��¼ĩҳ���������¼38����ĩҳ8��
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