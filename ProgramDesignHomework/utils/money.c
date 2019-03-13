#include "money.h"
Money Readmoney()
{
	Money prime;
	printf("元：");
	scanf("%d", &prime.yuan);//输入金额元
	printf("角");
	scanf("%d", &prime.jiao);//输入金额角
	printf("分");
	scanf("%d", &prime.fen);//输入金额分
	return prime;
}