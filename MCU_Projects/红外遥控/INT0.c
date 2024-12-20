#include <REGX52.H>

void Int0_Init(void)
{
	IT0=1;	//0为低电平触发
	IE0=0;	//中断标志清零
	EX0=1;	//单独中断
	EA=1;	//中断总控
	PX0=1;	//设置优先级	
}

/*中断函数模板*/
/*
void Int0_Routine(void)	interrupt 0
{
	Num++;
}

*/