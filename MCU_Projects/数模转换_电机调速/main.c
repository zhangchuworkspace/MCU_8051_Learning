#include <REGX52.H>
#include "TIMER0.H"
#include "DELAY.H"

sbit DA=P2^1;
unsigned char Counter,Compare;
unsigned char i;

void main()
{
	Timer0Init();
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			Delay(10);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;
			Delay(10);
		}
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
		DA=0;
	}
	else
	{
		DA=1;
	}
}
