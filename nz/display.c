#include"display.h"


uchar  hour,min,sec;		  //显示时间
uchar  hour1=0,min1=0,sec1=0;	  //设定闹钟时间
uchar  hour2=0,min2=0,sec2=0;	  //中间比较时间
uchar  shi,fen,miao;
uchar nian,yue,ri;
uchar year,month,day;
uchar n,j;
uchar c = 1;  //清零一次
uchar key = 0;
uchar noiscum = 0;
uchar data_7seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //时钟数码管显示定义0~9
uchar n=0;//S1按键功能选择常数


/*读取时间；*/
void read_rtc()
{
    hour=read_ds1302(0x85);	
//	hour2=((hour/10)<<4)+(hour%10);
	min=read_ds1302(0x83);
//	min2=((min/10)<<4)+(min%10);
	sec=read_ds1302(0x81);
//	sec2=((sec/10)<<4)+(sec%10);
	year=read_ds1302(0x8d);
	month=read_ds1302(0x89);
	day=read_ds1302(0x87);
}
/*显示时间；*/
void display()
{
	 
	 P2=0x01;
	 P0=data_7seg[hour/16];
	 delayms(4);
	 P2=0x02;
	 P0=data_7seg[hour%16];
	 delayms(4);
	 P2=0x04;
	 P0=~0x40;
	 delayms(4);
	 P2=0x08;
	 P0=data_7seg[min/16];
	 delayms(4);
	 P2=0x10;
	 P0=data_7seg[min%16];
	 delayms(4);
	 P2=0x20;
	 P0=~0x40;
	 delayms(4);
	 P2=0x40;
	 P0=data_7seg[sec/16];
	 delayms(4);
	 P2=0x80;
	 P0=data_7seg[sec%16];
	 delayms(4);
}
/*显示日历*/
void display1()
{
     P2=0x01;
	 P0=data_7seg[2];
	 delayms(4);
	 P2=0x02;
	 P0=data_7seg[0];
	 delayms(4);
	 P2=0x04;
	 P0=data_7seg[year/16];
	 delayms(4);
	 P2=0x08;
	 P0=data_7seg[year%16]&0x7f;
	 delayms(4);
	 P2=0x10;
	 P0=data_7seg[month/16];
	 delayms(4);
	 P2=0x20;
	 P0=data_7seg[month%16]&0x7f;
	 delayms(4);
	 P2=0x40;
	 P0=data_7seg[day/16];
	 delayms(4);
	 P2=0x80;
	 P0=data_7seg[day%16];
	 delayms(4);
}

void display2()		   //显示闹钟
{
     P2=0x01;
	 P0=data_7seg[hour1/10];
	 delayms(4);
	 P2=0x02;
	 P0=data_7seg[hour1%10];
	 delayms(4);
	 P2=0x04;
	 P0=~0x40;
	 delayms(4);
	 P2=0x08;
	 P0=data_7seg[min1/10];
	 delayms(4);
	 P2=0x10;
	 P0=data_7seg[min1%10];
	 delayms(4);
	 P2=0x20;
	 P0=~0x40;
	 delayms(4);
	 P2=0x40;
	 P0=data_7seg[sec1/10];
	 delayms(4);
	 P2=0x80;
	 P0=data_7seg[sec1%10];
	 delayms(4);
}