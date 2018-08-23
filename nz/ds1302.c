#include "ds1302.h"


sbit sck=P1^1;//定义控制DS1302的时钟线
sbit io=P1^0;//定义控制DS1302的串行数据
sbit rst=P1^2;// 复位线


void write_ds1302_byte(uchar dat)
{
     uchar i;
	 for(i=0;i<8;i++)
	 {
	    sck=0;       
		io=dat&0x01;      //每次从低字节开始传输
		dat=dat>>1;
		sck=1;
	}
}

/*DS1302 多字节写入；*/
void write_ds1302(uchar add,uchar dat)
{
     rst=0;_nop_();              //res引脚为低，数据传输中止
	 sck=0;	_nop_();              //清零时钟总线
	 rst=1;_nop_();             //res引脚为高，逻辑控制有效
	 write_ds1302_byte(add);    
	 write_ds1302_byte(dat);    
	 rst=0;_nop_();
	 io=1;
	 sck=1;
}

/*DS1302读取；*/
uchar read_ds1302(uchar add)
{
    uchar i,value;
	rst=0;_nop_();
	sck=0;_nop_();
	rst=1;_nop_();
	write_ds1302_byte(add);  //发送地址
	for(i=0;i<8;i++)
	{
	    value=value>>1;
		sck=0;
		if(io)value=value|0x80;   //从低到高
		sck=1;
	}
	 rst=0;_nop_();
	 sck=0;_nop_();
	 sck=1;
	 io=1;
	 return value;
}


