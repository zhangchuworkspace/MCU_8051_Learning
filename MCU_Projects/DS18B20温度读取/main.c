#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "DS18B20.H"
#include "OneWire.H"

float T;

void main()
{
	LCD_Init();
	//LCD_ShowString(1,1,"Temperatue:");
	OneWire_Init();
	while(1)
	{
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if(T<0){
			LCD_ShowChar(2,1,'-');
			T=-T;
		}else {LCD_ShowChar(2,1,'+');}
		LCD_ShowNum(2,2,T,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
		
	}
}
