
#include "mks_tft_com.h"



/* STM32оƬADCת�����DR�Ĵ�������ַ */
#define DR_ADDRESS      ((uint32_t)0x4001244C) 

/* ���ADCΪ12λģ��ת��������ı�����ֻ��ADCConvertedValue�ĵ�12λ��Ч */
__IO uint16_t ADCConvertedValue;     // 

/**-------------------------------------------------------
  * @������ ADC_GPIO_Configuration
  * @����   ADCģ��ת����GPIO���ó�ʼ������
  * @����   ��
  * @����ֵ ��
***------------------------------------------------------*/
void ADC_GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* ʹ��GPIOCʱ��      */
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /*PC0 ��Ϊģ��ͨ��11�������� */                       
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;       //�ܽ�0
		//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;       //�ܽ�8
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;   //����ģʽ
   // GPIO_Init(GPIOC, &GPIO_InitStructure);   
		GPIO_Init(GPIOA, &GPIO_InitStructure); 	
}

/**-------------------------------------------------------
  * @������ SZ_STM32_ADC_Configuration
  * @����   ADCģ��ת���Ĳ������ú���
  * @����   ��
  * @����ֵ ��
***------------------------------------------------------*/
void SZ_STM32_ADC_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;        //DMA��ʼ���ṹ������  
	ADC_InitTypeDef ADC_InitStructure;        //ADC��ʼ���ṹ������   

    /* ʹ��ADC1��DMA1ʱ��*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);		 //ʹ��DMAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	  //ʹ��ADCʱ��


    /*��DMA��������*/
    DMA_DeInit(DMA1_Channel1);		  //����DMA1�ĵ�һͨ��
    DMA_InitStructure.DMA_PeripheralBaseAddr = DR_ADDRESS;		  //DMA��Ӧ���������ַ
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCConvertedValue;   //�ڴ�洢����ַ
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	//DMA��ת��ģʽΪSRCģʽ����������Ƶ��ڴ�
    DMA_InitStructure.DMA_BufferSize = 1;		   //DMA�����С��1��
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	//����һ�����ݺ��豸��ַ��ֹ����
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;	//�رս���һ�����ݺ�Ŀ���ڴ��ַ����
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  //�����������ݿ��Ϊ16λ
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;  //DMA�������ݳߴ磬HalfWord����Ϊ16λ
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;   //ת��ģʽ��ѭ������ģʽ��
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;	//DMA���ȼ���
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;		  //M2Mģʽ����
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);          
    /* Enable DMA1 channel1 */
    DMA_Cmd(DMA1_Channel1, ENABLE);

    /* ��ADC��������*/
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;		//������ת��ģʽ
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;		  //�ر�ɨ��ģʽ
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;   //��������ת��ģʽ
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//��ʵ��ʹ�õ������������ʽ
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;   //���뷽ʽ,ADCΪ12λ�У��Ҷ��뷽ʽ
    ADC_InitStructure.ADC_NbrOfChannel = 1;	 //����ͨ������1��
    ADC_Init(ADC1, &ADC_InitStructure);

    RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M
    //ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_55Cycles5);  //ADCͨ���飬 ��1��ͨ�� ����˳��1��ת��ʱ�� 
     ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_55Cycles5);  //ADCͨ���飬 ��1��ͨ�� ����˳��1��ת��ʱ��                     
    ADC_DMACmd(ADC1, ENABLE); //ʹ��ADC1 DMA���� 
    ADC_Cmd(ADC1, ENABLE);   //ʹ��ADC1

    ADC_ResetCalibration(ADC1);	   //����ADCУ׼�Ĵ���  	  
    while(ADC_GetResetCalibrationStatus(ADC1));  //�ȴ��������
		 
    ADC_StartCalibration(ADC1);	    //��ʼУ׼ 
    while(ADC_GetCalibrationStatus(ADC1));	// �ȴ�У׼���
		   
    /*����ת����ʼ��ADCͨ��DMA��ʽ���ϵĸ���RAM��*/ 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

/**-------------------------------------------------------
  * @������ GetADCConvertedValue
  * @����   ��ȡADCģ��ת���Ľ��
  * @����   ��
  * @����ֵ ADCת������ı�����ֻ�еĵ�12λ��Ч
***------------------------------------------------------*/
uint16_t GetADCConvertedValue(void)
{
    return ADCConvertedValue;
}




