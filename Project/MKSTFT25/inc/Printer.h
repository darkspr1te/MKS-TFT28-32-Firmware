#ifndef _PRINTER_H_
#define _PRINTER_H_
#include "stdint.h"

#define MIN_SPRAYER_TEMP			0
#define MAX_SPRAYER_TEMP			270//300
#define MIN_BED_TEMP				0
#define MAX_BED_TEMP				150
#define MIN_EXT_SPEED_PERCENT		10
#define MAX_EXT_SPEED_PERCENT		999



typedef enum
{
	PRINTER_NOT_CONNECT = 0,
	PRINTER_CONNECT_OK,	
	PRINTER_OPERATING,
	PRINTER_OPERATE_OK,
} PRINTER_STATE;

typedef enum
{
	TASK_RESET,
	TASK_GOING,
	TASK_COMPLETE,
	TASK_PAUSE,
	TASK_STOP
	
} PRINT_TASK_FLAG;


typedef struct
{
	float curPos[3];
	float curSprayerTemp[2];	// 2����ͷ�¶�
	float curSprayerTempBak[2];
	float curBedTemp;	//�ȴ��¶�
	float curBedTempBak;
	float desireSprayerTemp[2];// 2����ͷĿ���¶�
	float desireSprayerTempBak[2];
	float desireSprayerTempBak_1[2];
	float desireBedTemp;// �ȴ�Ŀ���¶�
	float desireBedTempBak;

	float preheat_desireSprayerTemp[2];// 2����ͷĿ���¶�
	float preheat_desireBedTemp;// �ȴ�Ŀ���¶�

	uint16_t preheat_max_desireSprayerTemp;//��ͷ���Ŀ���¶�
	uint16_t preheat_max_desireBedTemp;//�ȴ����Ŀ���¶�

	int8_t curSprayerChoose;	//��ǰѡ�����ͷ
	int8_t curTempType;		//��ͷ1����ͷ2���ȴ�
	int8_t stepHeat;	//?��????
	int8_t fanOnoff; //�������
	uint8_t fanSpeed;	//����ٶ�
	uint8_t pre_fanSpeed;//Ԥ�����ٶ�
	int8_t sprayerNum; //��ͷ��
	int8_t machineType; //����
	uint16_t printSpeed;		//��ӡ�ٶ�
	uint16_t printExtSpeed0;		//��ӡ�ڼ伷���ٶ�
	uint16_t printExtSpeed1;		//��ӡ�ڼ伷���ٶ�
	uint8_t stepPrintSpeed;	//��ӡ�ٶȵ�������
	int8_t extruStep;	//��������
	int8_t extruSpeed;	//�����ٶ�
	int16_t moveSpeed;	//�ƶ��ٶ�
	float move_dist;		//�ƶ�����
	int8_t language;	//����
	int8_t language_bak;	//����
	int8_t baud;		//������

	int8_t fileSysType; //�ļ�ϵͳ����
	uint8_t touch_adj_flag; //������У����־λ
	int32_t touch_adj_xMin;
	int32_t touch_adj_xMax;
	int32_t touch_adj_yMin;
	int32_t touch_adj_yMax;

	int8_t rePrintFlag;

	int8_t custom_pic_flag;	//����ͼƬ
	
	int32_t background_color; //������ɫ
	int32_t title_color; //������ɫ
	int32_t state_background_color; //״̬��ʾ������ɫ
	int32_t state_text_color; //״̬��ʾ������ɫ
	int32_t filename_color; //�ļ���������ɫ
	int32_t filename_background_color; //��ӡ����״̬��Ϣ������ɫ
	int32_t printingstate_word_background_color;//��ӡ����״̬��Ϣ������ɫ
	int32_t printingstate_word_color;
	uint8_t MoreItem_pic_cnt;//"����"ѡ���ͼƬ����

	uint8_t custom_bed_flag;//�ȴ�����

	uint8_t button_3d_effect_flag;//��ť3dЧ�����Ʊ�־

	uint8_t firmware_type;//����̼����͡�1:marlin;2:repetier;3:smoothie

	int16_t Pause_XPOS;
	int16_t Pause_YPOS;
	int16_t Pause_ZADD;

	uint8_t func_btn1_display_flag;//���ܰ�ť1��ʾ��־:0����ʾ��1��ʾ
	uint8_t func_btn2_display_flag;//���ܰ�ť2��ʾ��־:0����ʾ��1��ʾ
	uint8_t func_btn3_display_flag;//���ܰ�ť2��ʾ��־:0����ʾ��1��ʾ

	uint8_t pwrdn_mtrdn_level_flg;//�ϵ�����߼���ƽ��־��1:�˿�Ĭ��Ϊ�ߵ�ƽ��0:�˿�Ĭ��Ϊ�͵�ƽ

	uint8_t print_finish_close_machine_flg;//����ػ�

	uint8_t morefunc_cnt;

	uint16_t filament_load_speed;//�����ٶ�
	uint16_t filament_load_length;//���ϲ���
	//uint16_t filament_load_limit_temper;//���ϵ�����¶�ֵ
	uint16_t filament_loading_time;
	uint16_t filament_unload_speed;
	uint16_t  filament_unload_length;
	uint16_t filament_limit_temper;
	uint16_t filament_unloading_time;

	uint16_t unload_retract_length;  //����ʱ�Ƚ��ϵĳ���
	uint16_t unload_retract_speed;  //����ʱ�Ƚ��ϵ��ٶ�
	
	uint16_t leveling_z_speed;
	uint16_t leveling_xy_speed;
	//HC-chen
	int16_t leveling_z_high;

	uint8_t leveling_point_number;//��ƽ��ʽ
	int16_t leveling_point1_x;
	int16_t leveling_point1_y;
	int16_t leveling_point2_x;
	int16_t leveling_point2_y;
	int16_t leveling_point3_x;
	int16_t leveling_point3_y;
	int16_t leveling_point4_x;
	int16_t leveling_point4_y;
	int16_t leveling_point5_x;
	int16_t leveling_point5_y;
	
	uint8_t getzpos_flg;
	uint8_t getzpos_enable;
	float zpos;//z������ֵ
	unsigned char move_z_coordinate[20];

	uint8_t pwd_reprint_flg;
  float	z_current_position;
	float	find_z_current_position;
	uint8_t findpoint_start;
	float breakpoint_z_error;

	//tan 20170111
	unsigned char sd_save_flg;
	unsigned char sd_saving;
	unsigned char z_display_pos[21];
	unsigned char z_display_pos_bak[21];
	

	//tan 20170113
	unsigned char pwroff_save_mode;

	uint8_t leveling_mode;//��ƽ��ʽ��1:�Զ���ƽ��0:�ֶ���ƽ
	
	uint8_t have_ups;
	uint8_t insert_det_module;// 1:����220detģ�飬����ֵ:��PWC�ػ�ģ�顣PWC�������220detģ�顣

	uint8_t filament_det1_level_flg;// ���ϼ��1��1:�ߵ�ƽ������0�͵�ƽ������
	uint8_t filament_det2_level_flg;// ���ϼ��2��1:�ߵ�ƽ������0�͵�ƽ������

	//wifi
	//volatile uint8_t wifi_type;
	volatile char wifi_ap[32];	//wifi���������ַ���
	volatile char wifi_key[64]; //wifi�����ַ���
	volatile uint8_t wifi_mode_sel;
	uint8_t wifi_type; // HLK: 0x01 , ESP: 0X02

	volatile char cloud_enable;	
	volatile char cloud_hostUrl[96];	//�����ӵ�ַ
	volatile int cloud_port;		//�����Ӷ˿�

	volatile uint8_t multiple_language;//�������
	volatile uint8_t OVERTURN_180;   //��Ļ��ת180��
	
	volatile int code_page;

	volatile uint8_t disable_pwr_det;
	volatile uint8_t disable_mt_det;
	volatile uint8_t single_nozzle;
	volatile uint8_t wifi_state;

	volatile uint8_t add_checkSum;   //M110�Ƿ��У���־λ
	volatile uint8_t display_error;   //��ʾ������Ϣ��־λ 

	volatile uint8_t TestFalaFlag;//���Է������ݱ�־λ
	volatile uint8_t reprint_no_temp_flag;   //�ϵ�����û���¶��ֶ�����¶ȱ�־λ
	volatile uint8_t babystep;
	volatile uint8_t zoffset_disp_flag;
	volatile uint8_t disp_zoffset_buf[30];
} CFG_ITMES;

extern int32_t printer_state;

extern CFG_ITMES gCfgItems;

extern void printer_init();
extern void get_cur_temp();
//extern void code_page_sel();

#endif
