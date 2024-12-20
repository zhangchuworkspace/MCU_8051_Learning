#include <REGX52.H>

sbit I2C_SCL=P2^1;	//重定义P21口
sbit I2C_SDA=P2^0;	//重定义P20口

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start(void)
{
	I2C_SDA=1;	//数据线和时钟线都为高即两个总线处于空闲状态
	I2C_SCL=1;	//SCL高电平期间，SDA下降沿为起始条件
	I2C_SDA=0;	//将SDA置0，产生下降沿
	I2C_SCL=0;	//SCL置0低电平，预备放入bit
}

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void I2C_Stop(void)
{
	I2C_SDA=0;	//先把数据总线置0
	I2C_SCL=1;	//SCL置高电平
	I2C_SDA=1;	//SDA置1，产生上升沿
}

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的字节
  * @retval 无
  */
/*SCL低电平期间，主机将bit位高位在前依次放入SDA；
每放入一个bit完成后，SCL依次拉高电平，从机在SCL高电平期间依次读取bit
	SCL高电平期间SDA不可以有数据变化，
	因为SCL高电平期间，SDA的变化将被认为是起始或停止条件
*/
void I2C_SendByte(unsigned char Byte)	//主机发送，从机接收
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);	//从高位到低位，循环8次，读取一个Byte
		I2C_SCL=1;	//SCL拉高电平，从机读取一个bit
		I2C_SCL=0;	//SCL拉低电平，准备从机下一个bit读取
	}
}

/**
  * @brief  I2C接收一个字节
  * @param  无
  * @retval 接收到的一个字节数据
  */
unsigned char I2C_ReceiveByte(void)	//从机发送，主机接收
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;	//释放数据总线
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}	//判断I2C_SDA是否为1,是，则将byte按位置置1
		I2C_SCL=0;
	}
	return Byte;
}

/**
  * @brief  I2C发送应答
  * @param  AckBit 应答位，0为应答，1为非应答
  * @retval 无
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}

/**
  * @brief  I2C接收应答位
  * @param  无
  * @retval 接收到的应答位，0为应答，1为非应答
  */
unsigned char I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA=1;	//释放SDA
	I2C_SCL=1;	//拉高SCL读取应答bit
	AckBit=I2C_SDA;
	I2C_SCL=0;	//拉低SCL读取应答bit完成
	return AckBit;
}
