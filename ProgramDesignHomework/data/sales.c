#include "sales.h"

Sales ReadSales()
{
	Sales prime;
	scanf("%d", prime.price);
	scanf("%d", prime.quantity);
	prime.total = prime.price*prime.quantity;
	scanf("%s", prime.customer);
	ReadComponent();
	return prime;
}