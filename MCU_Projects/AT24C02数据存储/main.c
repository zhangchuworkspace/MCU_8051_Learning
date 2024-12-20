#include <REGX52.H>
#include "KEY.H"
#include "LCD1602.H"
#include "DELAY.H"
#include "AT24C02.H"

unsigned char Data,KeyNum;
unsigned int Num;
void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,Num,5);
//	LCD_ShowString(1,1,"Hello World!");
//	AT24C02_WriteByte(0,245);
//	Delay(5);
//	Data=AT24C02_ReadByte(0);
//	LCD_ShowNum(2,1,Data,5);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1){
			Num++;
			LCD_ShowNum(1,1,Num,5);
		}
		if(KeyNum==2){
			Num--;
			LCD_ShowNum(1,1,Num,5);
		}
		if(KeyNum==3){
			AT24C02_WriteByte(0,Num%256);
			Delay(5);
			AT24C02_WriteByte(1,Num/256);
			Delay(5);
			LCD_ShowString(2,1,"Write Done");
			Delay(1000);
			LCD_ShowString(2,1,"          ");
		}
		if(KeyNum==4){
			Num=AT24C02_ReadByte(0);
			Num|=AT24C02_ReadByte(1);
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Read Done");
			Delay(1000);
			LCD_ShowString(2,1,"          ");			
		}
	}
}
