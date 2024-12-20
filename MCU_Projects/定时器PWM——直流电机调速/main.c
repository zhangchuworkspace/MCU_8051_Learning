#include <REGX52.H>
#include "NIXIE.H"
#include "TIMER0.H"
#include "DELAY.H"
#include "KEY.H"
#include "LCD1602.H"

sbit LED=P2^0;
unsigned char Counter,Compare,KeyNum,Mode,Speed;

void main()
{
	LCD_Init();
	Timer0Init();
	Compare=5;
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Mode++;
			Mode%=5;
			if(Mode==0){Compare=0;}
			if(Mode==1){Compare=25;}
			if(Mode==2){Compare=50;}
			if(Mode==3){Compare=75;}
			if(Mode==4){Compare=100;}
		}
//		Nixie(1,Mode);
		LCD_ShowString(1,1,"Mode:");
		LCD_ShowNum(1,6,Mode,1);
		LCD_ShowString(2,1,"duty ratio:");
		LCD_ShowNum(2,12,Compare,3);
	}
}

//100us加1
void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;	//设置定时初值
	TH0 = 0xFF;	//设置定时初值
	Counter++;
	Counter%=100;	//取模运算，100%100=0，给Counter置0
	if(Counter<Compare)	//低于设定值的部分
	{
		LED=0;
	}
	else
	{
		LED=1;
	}
}



