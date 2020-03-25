#ifndef __MYTEXT_H__
#define __MYTEXT_H__	 
#include "sys.h"
//#include "fontupd.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������ʾ ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/18
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

#define FONTINFOADDR	0x1B5000//2*1024
#define GBK_FLASH_ADDR	FONTINFOADDR+0X32//0X2D000//UNIGBK_FLASH_ADDR+0X2D000
#define UNIGBK_FLASH_ADDR		GBK_FLASH_ADDR+280*1024//FONTINFOADDR+0X32


//�ֿ���Ϣ�ṹ�嶨��
//���������ֿ������Ϣ����ַ����С��
__packed typedef struct 
{
	u8 fontok;				//�ֿ���ڱ�־��0XAA���ֿ��������������ֿⲻ����
	u32 ugbkaddr; 			//unigbk�ĵ�ַ
	u32 ugbksize;			//unigbk�Ĵ�С	 
	u32 f12addr;			//gbk12��ַ	
	u32 gbk12size;			//gbk12�Ĵ�С	 
	u32 f16addr;			//gbk16��ַ
	u32 gkb16size;			//gbk16�Ĵ�С	 
}_font_info;

extern _font_info ftinfo;	//�ֿ���Ϣ�ṹ��
					     
void Get_HzMat(unsigned char *code,unsigned char *mat,u8 size);//�õ����ֵĵ�����
void Show_Font(u16 x,u16 y,u8 *font,u8 size,u8 mode);//��ָ��λ����ʾһ������
void Show_Str(u16 x,u16 y,u16 width,u16 height,u8*str,u8 size,u8 mode);//��ָ��λ����ʾһ���ַ��� 
void Show_Str_Mid(u16 x,u16 y,u8*str,u8 size,u8 len);
void Show_Str2(u16 x,u16 y,u16 width,u16 height,u8*str,u8 size,u8 mode);
#endif
