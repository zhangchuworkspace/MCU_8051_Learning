#include <REGX52.H>
#include "DELAY.H"
#include "TIMER0.H"

sbit Buzzer=P2^5;

void main()
{
	Timer0Init();
	while(1)
	{
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值 定时器定时1ms
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		P2=0x01;
		T0Count=0;
	}
}
