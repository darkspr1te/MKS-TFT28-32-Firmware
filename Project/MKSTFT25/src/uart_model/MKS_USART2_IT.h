/********************   (C) COPYRIGHT 2014 www.makerbase.com.cn   ********************
 * �ļ���  ��MKS_USART2_IT.c
 * ����    ��Marlinͨ�Ŵ���ģ��
						 1. printerStaus = idle ,��PUSH��gcodeCmdTxFIFO�������usart2����,����usart2�յ���Ӧ��Push��gcodeCmdRxFIFO��
						 2. printerStaus = working��
						 		a) ʵʱ����gcodeTxFIFO�Ĵ�ӡ���ݣ�
						 		b) �������ݺ󣬳���5sδ�յ�Ӧ���ظ����͸����ݣ�ֱ���յ�Ӧ��
						 		c) �յ� Error:Line Number is not Last Line Number+1, Last Line: n������Nn+1���ݣ�
						 		d) �յ� Error:checksum mismatch, Last Line: n������Nn+1���ݡ�
						 		e) ��gcodeCmdTxFIFO������ʱ�����ȷ���gcodeCmdTxFIFO������,����Ӧ��Push��gcodeCmdRxFIFO��
						 3. �κ�ʱ��������󣬳���5sδ�յ�Ӧ���ظ����͸����ֱ���յ�Ӧ��
						 4. printerStaus״̬ת��ͼ����״̬ת��ͼ_pr��
 * ����    ��skyblue
**********************************************************************************/

#ifndef MKS_USART2_IT_H
#define MKS_USART2_IT_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include "mks_tft_fifo.h"
//#include "main.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define USART2_SR		*(__IO uint16_t *)0x40004400
#define USART2_DR		*(__IO uint16_t *)0x40004404
#define USART2_CR1	*(__IO uint16_t *)0x4000440C
	 
#define USART2BUFSIZE	FIFO_SIZE
//20150912
#define FIFO_NODE_CNT	10

#define usart2PreTxStart()	do{\
													usart2Data.txP = &usart2Data.usart2Txbak[0];\
													usart2Data.timerCnt=1;\
													usart2Data.timer = timer_running;\
													USART2_DR = *(usart2Data.txP++);\
													}while(0)

													
/*	 
#define usart2TxStart()	do{\
													if(usart2Data.uart2Staus == uart2_idle){\
													usart2Data.txP = &usart2Data.usart2Txbuf[0];\
													usart2Data.txBase = &usart2Data.usart2Txbuf[0];\
													usart2Data.uart2Staus = uart2_busy;\
													usart2Data.timerCnt=1;\
													usart2Data.timer = timer_running;\
													USART2_DR = *(usart2Data.txP++);}\
													}while(0)
*/	
/*
#define usart2CmdTxStart()	do{\
													usart2Data.txP = &usart2Data.usart2CmdTxbuf[0];\
													usart2Data.txBase = &usart2Data.usart2CmdTxbuf[0];\
													usart2Data.timerCnt=1;\
													usart2Data.timer = timer_running;\
													USART2_DR = *(usart2Data.txP++);\
													}while(0)
*/	 

#define pushGcode() do{\
										switch(udiskFileStaus){\
												case udisk_file_ok:\
												case udisk_file_end:\
													for(i=0;i<FIFO_NODE_CNT;i++)\
															pushTxGcode();break;\
												default :break;}\
											}while(0)
/*		
#define printerInit() do{\
								usart2Data.usart2Txbuf[0]='N';usart2Data.usart2Txbuf[1]='-';usart2Data.usart2Txbuf[2]='1';usart2Data.usart2Txbuf[3]=' ';\
								usart2Data.usart2Txbuf[4]='M';usart2Data.usart2Txbuf[5]='1';usart2Data.usart2Txbuf[6]='1';usart2Data.usart2Txbuf[7]='0';\
								usart2Data.usart2Txbuf[8]='*';usart2Data.usart2Txbuf[9]='1';usart2Data.usart2Txbuf[10]='5';usart2Data.usart2Txbuf[11]='\n';\
								usart2TxStart();\
								}while(0)
*/											
typedef enum
{
	timer_stop = 0,		// 	usart2 ��ʱ��ֹͣ
	timer_running,		//	usart2 ��ʱ������
} UART2_TIMER_STATUS;

typedef enum
{
	uart2_idle = 0,		// 	usart2 ����
	uart2_busy,				//	usart2 ���ڷ�������
} UART2_STATUS;
	 
typedef enum
{
	ok_waiting = 0,		// 	
	ok_received,
} OK_STATUS;



typedef enum
{
	pr_wait_idle = 0,		// 	
	pr_wait_cmd,
	pr_wait_data,
} PR_WAIT_STATUS;


typedef enum
{
	printer_idle = 0,				// 	 ��ӡ������
	printer_working,					//	 ��ӡ��������
	printer_waiting,				//	  ��ӡ�У����Ͷ��пգ��ȴ�
} PRINTER_STATUS;

typedef enum
{
	receive_ok = 0,				// 	 ������������
	receive_Resend,				//	 ���յ�Resend
	receive_ErrLin,				//	   Error:Line Number is not Last Line Number+1, Last Line: 1
	receive_ErrChk,					//		 Error:checksum mismatch, Last Line: 3
	receive_Unknown,
	receive_PreTx,
} RECEIVE_STATUS;

typedef enum
{
	resend_idle = 0,
	resend_ready,
	resend_end,
}RESEND_STATUS;

typedef enum
{
	marlin = 0,
	smoothie,
	repetier,
}FIREWARE_TYPE;



typedef struct 
{
	unsigned char usart2Rxbuf[USART2BUFSIZE];		//���ڽ��ջ�����
	unsigned char *rxP;				//���ڽ���ָ��
	unsigned char usart2Txbuf[USART2BUFSIZE];		//���ڷ������ݻ�����
	unsigned char *txP;				//���ڷ���ָ��
	unsigned char *txBase;
	unsigned char usart2Txbak[USART2BUFSIZE];		//���洮�ڷ��͵���һ֡����
	UART2_TIMER_STATUS timer;	
	unsigned int	timerCnt;
	unsigned char resendLine;
	unsigned char curLine;
	unsigned char resendCnt;
	PRINTER_STATUS printer;		// ��ӡ������״̬
	RESEND_STATUS resendFlag;
	PR_WAIT_STATUS prWaitStatus;
	
}USART2DATATYPE;

extern void mksUsart2RepeatTx(void);
extern void mksUsart2Polling(void);
extern void mksUsart2Init(void);
extern void mksUsart2IrqHandlerUser(void);	 

extern USART2DATATYPE usart2Data;
extern __IO u16 tftDelayCnt;
extern __IO u16 fileEndCnt;
extern TFT_FIFO gcodeTxFIFO;			//gcode ���ݷ��Ͷ���
//extern TFT_FIFO gcodeRxFIFO;			//gcode	���ݽ��ն���

extern TFT_FIFO gcodeCmdTxFIFO;		//gcode ָ��Ͷ���
extern TFT_FIFO gcodeCmdRxFIFO;		//gcode	ָ����ն���

extern FIREWARE_TYPE firmwareType;

#ifdef __cplusplus
}
#endif


#endif
