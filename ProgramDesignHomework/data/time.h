#pragma once

typedef struct {
	int month;   //月份
	int day;     //日期
	int hour;    //小时
	int minute;  //分钟
}Time;

Time ReadTime();