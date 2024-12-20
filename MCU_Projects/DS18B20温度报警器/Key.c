#include <REGX52.H>
#include "Delay.h"

unsigned char Key_KeyNumber;

unsigned char Key(void)
{
	unsigned char Temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return Temp;
}

unsigned char Key_GetState()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	
	return KeyNumber;	//返回按键值
}

void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState=NowState;	//现在状态赋为上一个状态
	NowState=Key_GetState();	//将按键状态赋为现在状态
	if(LastState==1	&&	NowState==0)	//上个状态为1,说明按键1按下，现在状态为0说明按键松手
		{
			Key_KeyNumber=1;
		}
	if(LastState==2	&&	NowState==0)
		{
			Key_KeyNumber=2;
		}
	if(LastState==3	&&	NowState==0)
		{
			Key_KeyNumber=3;
		}
	if(LastState==4	&&	NowState==0)
		{
			Key_KeyNumber=4;
		}
}
