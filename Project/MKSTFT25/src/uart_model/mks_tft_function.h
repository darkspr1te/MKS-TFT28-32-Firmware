#ifndef MKS_TFT_FUNCTION_H
#define MKS_TFT_FUNCTION_H

#include "mks_tft_reprint.h"

typedef enum
{
	work2pause = 0,		// 	
	pause2work,		//	
} PR_CHANGE_STATUS;

extern unsigned char heatFlag;
extern volatile unsigned char mksBpAlrmEn;
extern unsigned char x_pauseBak[COORDINATELENGTH];
extern unsigned char y_pauseBak[COORDINATELENGTH];
extern unsigned char z_pauseBak[COORDINATELENGTH];
extern unsigned char e_pauseBak[COORDINATELENGTH];

extern unsigned char breakpoint_homeXY();
extern unsigned char homeXY();
extern void relocalZ(void);
extern void tftDelay(__IO u16 n);
extern void printerStop();
extern void relacalSave(void);
extern void mksBeeperAlarm(void);

#endif
