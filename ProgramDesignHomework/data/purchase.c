#include "purchase.h"
#include"time.h"
Purchase ReadPurchase()
{
	Purchase prime;
	Readtime();
	scanf("%d" ,&prime.price);//输入进货单价
	scanf("%d", &prime.quantity);//输入进货数量
	prime.total = prime.price*prime.quantity;//  输入商品总价
	scanf("%s", &prime.retailer);//输入进货供应商
	return prime;
}