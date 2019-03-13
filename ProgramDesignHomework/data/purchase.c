#include "purchase.h"
#include"time.h"
Purchase ReadPurchase()
{
	Purchase prime;
	Readtime();
	scanf("%d" ,prime.price);
	scanf("%d", prime.quantity);
	prime.total = prime.price*prime.quantity;
	scanf("%s", prime.retailer);
	return prime;
}