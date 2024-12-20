#include <REGX52.H>
#include "Timer0.H"
#include "INT0.H"

unsigned int IR_Time;
unsigned char IR_State;


void IR_Init()
{
	Timer0_Init();
	Int0_Init();
}
 
void Int0_Routine(void)	interrupt 0
{
	
}