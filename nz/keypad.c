#include"keypad.h"

uchar  hour,min,sec;		  //显示时间
uchar  hour1=0,min1=0,sec1=0;	  //设定闹钟时间
uchar  hour2=0,min2=0,sec2=0;	  //中间比较时间
uchar  shi,fen,miao;
uchar nian,yue,ri;
uchar year,month,day;
uchar n,j;
uchar c = 1;  //清零一次
uchar key = 0;
uchar n=0;//S1按键功能选择常数
uchar data_7seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //时钟数码管显示定义0~9


void set_rtc()
{
if(P3_1 == 0)
{
   delayms(30);
	    if(P3_1==0)
	     {
			while(!P3_1);
		    key = 1;	   //根据按次数控制模式
	     }
}
  	if(P3_5==0)	 //按下是0
   	{
		delayms(30);
	    if(P3_5==0)
	     {
			while(!P3_5);
		    n++;	   //根据按次数控制模式
	     }
		if(n>=3)
		n=0;
    }
  if(P3_6==0)	 
    {
 	 delayms(100);
     if(P3_6==0)
    	  {
			while(!P3_6);
	   		 j++;	        //根据按键次数控制模式
	   	  }
	if(j>=3)
	j=0;
     }
  if(n==0)	  //显示时间
   {   
    if(j==0) //时
	{
	    shi=P3_7;
       if(shi==0)
	   {
	   delayms(300);
	    if(shi==0)
		{ 
		    hour=(hour>>4)*10+(hour&0x0f);
			hour++;
			if(hour==24) hour=0;
			hour=((hour/10)<<4)+(hour%10);
			write_ds1302(0x84,hour);
		 }
	     }
		}
	  if(j==1)		//分
	   {
	     fen=P3_7;
	    if(fen==0)
		{ delayms(300);
			if(fen==0)
			{
		    min=(min>>4)*10+(min&0x0f);
			min++;
			if(min==60) min=0;
			min=((min/10)<<4)+(min%10);
			write_ds1302(0x82,min);
		   }
	    }
	  }
	  if(j==2)		  //秒
	  {
	    miao=P3_7;
	     if(miao==0)
	     {
	     delayms(300);
	      if(miao==0)
		   { 
		    sec=(sec>>4)*10+(sec&0x0f);
			sec++;
			if(sec==60) sec=0;
			sec=((sec/10)<<4)+(sec%10);
			write_ds1302(0x80,sec);
		   }
	     }
	  }
   }

  if(n==1)	   //显示日历
   {  	
   if(j==3)j=0;
     { 
    	if(j==0)
	   {	 
	    nian=P3_7;
	     if(nian==0)
	     {	   
	     delayms(300);
	      if(nian==0)
		   { 
		    year=(year>>4)*10+(year&0x0f);
			year++;
			if(year==100) year=0;
			year=((year/10)<<4)+(year%10);
			write_ds1302(0x8c,year);
		   }
	     }
	  }
		if(j==1)
	  {
	    yue=P3_7;
	     if(yue==0)
	     {
	     delayms(300);
	      if(yue==0)
		   { 
		    month=(month>>4)*10+(month&0x0f);
			month++;		  
			if(month==13) month=0;
			month=((month/10)<<4)+(month%10);
			write_ds1302(0x88,month);
		   }
	     }
	  }
	  
	 if(j==2)
	 {ri=P3_7;
	  if(ri==0)
	  {
	  delayms(300);
	    if(ri==0)
		{ 
		    day=(day>>4)*10+(day&0x0f);
			day++;
			if(day==31) day=0;
			day=((day/10)<<4)+(day%10);
			write_ds1302(0x86,day);
		 }
	  } 
	    
    } 
  }
 }
 if(n==2)		 //设定闹钟时间
 {	 while(c)
	 {
     P2=0x01;
	 P0=data_7seg[0/16];
	 delayms(4);
	 P2=0x02;
	 P0=data_7seg[0%16];
	 delayms(4);
	 P2=0x04;
	 P0=~0x40;
	 delayms(4);
	 P2=0x08;
	 P0=data_7seg[0/16];
	 delayms(4);
	 P2=0x10;
	 P0=data_7seg[0%16];
	 delayms(4);
	 P2=0x20;
	 P0=~0x40;
	 delayms(4);
	 P2=0x40;
	 P0=data_7seg[0/16];
	 delayms(4);
	 P2=0x80;
	 P0=data_7seg[0%16];
	 delayms(4);	  //清显示
	 c=c-1;
	 }
	if(j==0) //时
	{
	    shi=P3_7;
       if(shi==0)
	   {
	   delayms(300);
	    if(shi==0)
		{
	        //hour=(hour>>4)*10+(hour&0x0f);
			hour1++;
			if(hour1==24) hour1=0;
			//hour1=((hour1/10)<<4)+(hour1%10);
			//write_ds1302(0x84,hour);
			//hour1 = hour;
		 }
	     }
		}
	  if(j==1)		//分
	   {
	     fen=P3_7;
	    if(fen==0)
		{ delayms(300);
			if(fen==0)
			{
		    //min=(min>>4)*10+(min&0x0f);
			min1++;
			if(min1==60) min1=0;
			//min1=((min1/10)<<4)+(min1%10);
			//write_ds1302(0x82,min);
			//min1 = min;
		   }
	    }
	  }
	  if(j==2)		  //秒
	  {
	    miao=P3_7;
	     if(miao==0)
	     {
	     delayms(300);
	      if(miao==0)
		   { 
		    //sec=(sec>>4)*10+(sec&0x0f);
			sec1++;
			if(sec1==60) sec1=0;
			//sec1=((sec1/10)<<4)+(sec%10);
			//write_ds1302(0x80,sec);
			 // sec1 = sec;
		   }
	     }
	  }
  }
 }