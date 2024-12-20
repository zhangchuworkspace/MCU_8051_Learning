#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP_8bit 		0x9C
#define XPT2046_YP_8bit 		0xDC
#define XPT2046_VBAT_8bit 	0xAC
#define XPT2046_AUX_8bit 		0xEC

#define XPT2046_XP_12bit 		0x94
#define XPT2046_YP_12bit 		0xD4
#define XPT2046_VBAT_12bit 	0xA4
#define XPT2046_AUX_12bit 	0xE4

unsigned int XPT2046_ReadAD(unsigned char Command);

#endif