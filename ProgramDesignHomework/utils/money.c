#include "money.h"
Money Readmoney()
{
	Money prime;
	printf("Ԫ��");
	scanf("%d", &prime.yuan);//������Ԫ
	printf("��");
	scanf("%d", &prime.jiao);//�������
	printf("��");
	scanf("%d", &prime.fen);//�������
	return prime;
}