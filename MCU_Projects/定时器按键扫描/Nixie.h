#ifndef __Nixie_H__
#define __Nixie_H__

void Nixie_SetBuf(unsigned char Location,Number);	//数码管显示
void Nixie_Scan(unsigned char Location,Number);
void Nixie_Loop(void);
#endif