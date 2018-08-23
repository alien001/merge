#include<reg52.h>


bit sck=P1^1;//定义控制DS1302的时钟线
sbit io=P1^0;//定义控制DS1302的串行数据
sbit rst=P1^2;// 复位线
sbit P3_5=P3^5;    //按键S1
sbit P3_6=P3^6;     //按键S2
sbit P3_7=P3^7;     //按键S3
sbit P3_1=P3^1;     //按键S3
sbit led=P1^7;
sbit nois = P1^6;



void main()
{
//     show();	 
	 write_ds1302(0x84,0x12);	  //小时
	 write_ds1302(0x82,0x00);	 //分
	 write_ds1302(0x80,0x00);	//秒
	 write_ds1302(0x8c,0x18);		  //年
	 write_ds1302(0x88,0x06);		 //月
	 write_ds1302(0x86,0x11);		//天
	 nois = 0;
	 while(1)
	 {	 
	    set_rtc();
        read_rtc();	 //读取时间
		hour2 = ((hour1/10)<<4)+(hour1%10);		//二进制的BCD码转化为十进制数
		min2 = ((min1/10)<<4)+(min1%10);
		sec2 = ((sec1/10)<<4)+(sec1%10);
		if(hour2 == hour&&min2 == min&& sec2 == sec)//读取回时间和设定时间对比
		{	
			nois = 1;	
		}
//		if(key == 0)			//key外部停止闹钟报警key == 1停止
//				{
//					nois = 1;//做报警
//				}
		if(key == 1)
			{ 
				nois = 0;//清除报警
				noiscum++;
				if(noiscum == 5)
				{
					  noiscum =0;
					  key = 0;
				}

			}
		if(n==0)	   //时间
		{
			display();
		}		
		if(n==1)		 //日期
		{		
			display1();
		}
		if(n==2)		 //闹钟设定时间
		{		
			display2();
		}
		if(min==0&sec<5)   //五秒闪烁
		{
			ss();
		}		    
	   	else 
		{
		led=0x01;
		}
      }
}