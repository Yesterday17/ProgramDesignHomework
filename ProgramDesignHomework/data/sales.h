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

#ifndef _DATA_SALES_H_
#define _DATA_SALES_H_

#include <malloc.h>

#include "../cstring_jslike/cstring_jslike.h"
#include "component.h"
#include "time.h"

typedef struct Sales {
  uint64_t time;
  int component;
  int sales_mode; // 销售模式（1表示批发，0表示零售）
  int price;       // 销售单价
  int quantity;    // 销售数量
  int total;       // 商品总价
  string customer;  //客户信息
  int gift;  //赠品
} Sales;

Sales *NewSales();
void FreeSales(Sales *sales);
Sales *ReadSales();
Sales *JSONToSales(cJSON *root);
cJSON *SalesToJSON(Sales *prime);

bool FindCustomer_Sales(LinkedListNode *node);
bool FindTime_Sales(LinkedListNode *node);
bool FindComponentName_Sales(LinkedListNode *node);
bool FindComponentType_Sales(LinkedListNode *node);

LinkedList* ReadSalesJSON(string filename);
bool WriteSalesJSON(string filename);
string PrintSalesTitle();
string PrintSales(void* node, uint8_t id);

int Gift();

#endif