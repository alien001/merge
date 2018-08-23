#ifndef __CALCULATE_H_
#define __CALCULATE_H_

#include "main.h"


extern sbit sck=P1^1;//定义控制DS1302的时钟线
extern  sbit io=P1^0;//定义控制DS1302的串行数据
extern  sbit rst=P1^2;// 复位线


extern  void write_ds1302_byte(uchar dat);
extern  void write_ds1302(uchar add,uchar dat);
extern   uchar read_ds1302(uchar add);


#endif