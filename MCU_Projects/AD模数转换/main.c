#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "XPT2046.H"

unsigned int ADValue;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ   NTC  RG");
	while(1)
	{
		ADValue=XPT2046_ReadAD(XPT2046_XP_8bit);
		LCD_ShowNum(2,1,ADValue,4);
		ADValue=XPT2046_ReadAD(XPT2046_YP_8bit);
		LCD_ShowNum(2,6,ADValue,4);
		ADValue=XPT2046_ReadAD(XPT2046_VBAT_8bit);
		LCD_ShowNum(2,11,ADValue,4);
		Delay(10);
	}
}


