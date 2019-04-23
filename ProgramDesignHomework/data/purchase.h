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

#ifndef _DATA_PURCHASE_H_
#define _DATA_PURCHASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cstring_jslike/cstring_jslike.h"
#include "component.h"
#include "time.h"

typedef struct Purchase {
  int component;
  uint64_t time;
  int price;       // 进货单价
  int quantity;    // 进货数量
  int total;       //商品总价
  string retailer;  //商品销售商
} Purchase;

Purchase *NewPurchase();
void FreePurchase(Purchase *purchase);
Purchase *ReadPurchase();
Purchase *JSONToPurchase(cJSON *root);
LinkedList* ReadPurchaseJSON(string filename);
cJSON *PurchaseToJSON(Purchase *prime);
bool WritePurchaseJSON(string filename);

string PrintPurchaseTitle();/*带上\n*/
string PrintPurchase(void *node, uint8_t id);/*带上\n*/
bool FindRetailer_Purchase(LinkedListNode *node);
bool FindTime_Purchase(LinkedListNode *node);
bool FindComponentName_Purchase(LinkedListNode *node);
bool FindComponentType_Purchase(LinkedListNode *node);
#endif