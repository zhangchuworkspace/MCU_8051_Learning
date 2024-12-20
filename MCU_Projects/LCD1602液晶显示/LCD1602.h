#ifndef __LCD1602_H__
#define __LCD1602_H__
//初始化
void LCD_Init();
//写入指令
void LCD_WriteCommand(unsigned char Command);
//写入数据
void LCD_WriteData(unsigned char Data);
//显示字符：行，列，字符
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char);
//显示字符串
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String);
//显示无符号数字
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
//显示有符号数字
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
//显示十六进制数字
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
//显示二进制数字
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);

#endif