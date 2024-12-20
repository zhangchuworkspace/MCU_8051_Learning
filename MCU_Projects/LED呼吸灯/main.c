#include <REGX52.H>
#include "KEY.H"
#include "TIMER0.H"

sbit LED=P2^3;

void Delay(unsigned int xms)
{
	while(xms--);
}

void main(void)
{
	unsigned char Time,i;
	while(1)
	{
		for(Time=0;Time<100;Time++)
		{
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);				
			}
		}
		for(Time=100;Time>0;Time--)
		{
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);				
			}
		}
	}
}
