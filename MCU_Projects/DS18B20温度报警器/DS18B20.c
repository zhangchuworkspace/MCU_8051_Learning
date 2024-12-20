#include <REGX52.H>
#include "ONEWIRE.H"
#include "LCD1602.H"
#define DS18B20_SKIP_ROM 0xcc	//跳过ROM
#define DS18B20_CONVERT_T 0x44	//开始温度变换
#define DS18B20_READ_SCRATCHPAD 0xbe	//读暂存器指令

//温度变换：初始化->跳过ROM->开始温度变换
void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);	//跳过ROM
	OneWire_SendByte(DS18B20_CONVERT_T);	//读暂存器
}

//温度读取：初始化->跳过ROM->读暂存器->连续的读操作
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;	//16bit中间变量
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
	Temp=(TMSB<<8)|TLSB;
	/*Temp=0000 0000 0000 0000
	TMSB左移8位，则占用高八位，假设为1111 1111 0000 0000
	1111 1111 0000 0000与TLSB或，则剩下的低8位被占用
	*/
	T=Temp/16.0;
	return T;
}
