#pragma once

typedef struct {
  int month;   //�·�
  int day;     //����
  int hour;    //Сʱ
  int minute;  //����
} Time;


#ifndef UNIT_TEST

Time ReadTime();

#endif