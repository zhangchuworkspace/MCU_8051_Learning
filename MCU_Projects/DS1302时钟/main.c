#include <REGX52.H>
#include <LCD1602.h>
#include <DS1302.H>

void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_SetTime();
	while(1)
	{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_Time[0],4);
		LCD_ShowNum(1,5,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,3,DS1302_Time[4],2);
		LCD_ShowNum(2,5,DS1302_Time[5],2);
		LCD_ShowNum(2,8,DS1302_Time[6],2);

	}
}
