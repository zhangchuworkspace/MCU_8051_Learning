#include <REGX52.H>
#include "LCD1602.H"
#include "DELAY.H"

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'d');
	LCD_ShowString(1,3,"Hello World");
	LCD_ShowHexNum(1,13,0xAb,4);
	LCD_ShowBinNum(2,1,0xA5,4);
	LCD_ShowChar(2,6,0xe8);
	LCD_ShowString(2,7,"Zhang Chu");
	while(1)
	{
		
	}
}
