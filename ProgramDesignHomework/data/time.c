#include "time.h"

Time ReadTime() {
	Time t0;
	printf("Month: ");
	scanf("%s", t0.month);
	printf("\nDay: ");
	scanf("%s", t0.day);
	printf("/nHour: ");
	scanf("%s", t0.hour);
	printf("/nMinute: ");
	scanf("%s", t0.minute);
	return t0;
}