#include <REGX52.H>

void Timer0_Init(void)
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0不计时
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)
{
	return (TH0<<8)|TL0;	//合并成16位数据
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;	//给1开始计时，0停止计时
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}
}
*/
