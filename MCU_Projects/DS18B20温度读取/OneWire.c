#include <REGX52.H>
#include "DELAY.H"
//DS18B20单总线通信
sbit OneWire_DQ=P3^7;

/*	初始化：主机将总线拉低至少480us，然后释放总线，等待15-60us后，
从机拉低总线60-240us响应主机，然后从机释放总线
*/
unsigned char OneWire_Init(void)
{
	unsigned char i,AckBit;
	OneWire_DQ=1;	//首先释放总线
	OneWire_DQ=0;	//拉低总线
	i=227;while(--i);	//Delay500us,最少480us
	OneWire_DQ=1;	//释放总线
	i = 29;while(--i);	//Delay70us
	AckBit=OneWire_DQ;	//应答位
	i=227;while(--i);	//Delay500us,补完时序
	return AckBit;
}
/*	发送一位：主机将总线拉低60-120us，然后释放总线，
表示发送0；主机将总线拉低1-15us，然后释放总线，表示发送1
从机将在总线拉低30us后(典型值)读取电平，整个时间片大于60us
*/
//发送一个bit
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 4;while (--i);	//DQ拉低10us
	OneWire_DQ=Bit;	//将需要发送的bit放入DQ
	i = 22;while (--i);	//延时50us
	OneWire_DQ=1;
}

/*接收一位：主机将总线拉低1-15us，然后释放总线，
并在拉低后15us内读取总线电平（尽量贴近15us的末尾）
读取为低电平则接收0，高电平则接收1，整个时间片应大于60us
*/
//接收一个bit
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i,Bit;
	OneWire_DQ=0;	//拉低总线
	i = 2;while (--i);	//延时5us
	OneWire_DQ=1;	//拉高总线
	i=2;while(--i);	//延时5us
	Bit=OneWire_DQ;
	i = 22;while (--i);	//延时50us补完时许
	return Bit;
}
//发送一个字节
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}
//接收一个字节
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}
