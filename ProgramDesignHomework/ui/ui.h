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

#ifndef _UI_H_
#define _UI_H_

#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "../utils/io.h"
#include "../data/purchase.h"
#include"../data/sales.h"
#include "../global.h"

/**
 * 记录菜单状态的枚举
 */
typedef enum Menu {
  MENU_Exit = -1,
  MENU_Welcome = 0,
  MENU_Main = 1,
  MENU_Purchase = 2,
  MENU_Sales = 3,
  MENU_Stock = 4,
  MENU_Amount = 5,
} Menu;

void UI_Init();

void UI_Welcome();

Menu UI_MainMenu();

Menu UI_SubMenu(Menu menu);

void UI_Exit();

void UI_WaitForNext(void *nextDo());

void gotoxy(int x, int y);

int OptionBar(int start, int end);

int RecordPage(LinkedList *data, string title, string record(void *, uint8_t));

void UI_Clear();
void UI_Color();

void RefreshStorageFund();

extern Menu menuNow;

#endif