#include <REGX52.H>

/*SPI协议 引脚重定义*/
sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

/*XPT2046转换后为16位*/

/*返回的值是12位,定义int函数*/
unsigned int XPT2046_ReadAD(unsigned char Command)
{
	unsigned char i;
	unsigned int ADValue=0;
	/*写时序*/
	XPT2046_DCLK=0;	//DCLK先于CS置0
	XPT2046_CS=0;	//先将CS置0
	for(i=0;i<8;i++)	//依次将bit放入DIN中
	{
		XPT2046_DIN=Command&(0x80>>i);	//将控制字的最高位放入DIN
		XPT2046_DCLK=1;	//上升沿发送
		XPT2046_DCLK=0;		
	}
	/*读取*/
	for(i=0;i<16;i++)
	{
		XPT2046_DCLK=1;
		XPT2046_DCLK=0;	//下降沿读取
		if(XPT2046_DOUT){ADValue|=(0x8000>>i);}
	}
	XPT2046_CS=1;	//CS置高，时序结束
	if(Command&0x08){return ADValue>>8;}
	else{return ADValue>>4;}
}
