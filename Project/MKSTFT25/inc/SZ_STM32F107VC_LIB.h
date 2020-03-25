/********************   (C) COPYRIGHT 2013 www.armjishu.com   ********************
 * �ļ���  ��SZ_STM32F107VC_LIB.h
 * ����    ���ṩSTM32F107VC����IV�ſ�����Ŀ⺯��
 * ʵ��ƽ̨��STM32���ۿ�����
 * ����    ��www.armjishu.com 
**********************************************************************************/
/* Includes ------------------------------------------------------------------*/

#ifndef _SZ_STM32F107VC_LIB_H_
#define _SZ_STM32F107VC_LIB_H_

#include "stm32f10x.h"
#include <stdio.h>

#ifdef __cplusplus
 extern "C" {
#endif




/* �������궨�� bitband macro ------------------------------------------------*/
/* ʹ��bitband����������bit�����ĳ����Ч�ʣ�����GPIO�ܽŵĿ���Ч����Ϊ���� */
/* ��������� ��32MB����������ķ���ӳ��Ϊ��1MB ����bit-band���ķ���(ʵ�ʴ�С����оƬ�й�) */
#define Periph_BASE         0x40000000  // �������ַ Peripheral 
#define Periph_BB_BASE      0x42000000  // �������������ַ Peripheral bitband

/* ע�⣺���볣������ʱ���ڱ���ʱ��������������������ַ�������ܴﵽ����Ч�ʵ�Ŀ��(�Ƽ�)
         ����������������ֻ��������ʱ��STM32�Լ������������ַ��Ч�ʻ����ۿ�(���Ƽ�) */
#define Periph_BB(PeriphAddr, BitNumber)    \
          *(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2))
	 
#define Periph_ResetBit_BB(PeriphAddr, BitNumber)    \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)) = 0)
   
#define Periph_SetBit_BB(PeriphAddr, BitNumber)       \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)) = 1)

#define Periph_GetBit_BB(PeriphAddr, BitNumber)       \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)))

/* ����GPIO����������������壬nΪbitλ�÷�ΧΪ0��15    */
/* ���Ƕ�GPIOA.15����������Ҫ��ʼ��GPIO��Ȼ��ʹ�÷����� */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 0;           */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 1;           */
/* ��ȡGPIOA.15����ĵ�ƽ�� data = PAInBit(15);         */
#define PAOutBit(n)     Periph_BB((uint32_t)&GPIOA->IDR,n)  //��� 
#define PASetBit(n)     (PAOutBit(n) = 1)                   //��� ��
#define PAResetBit(n)   (PAOutBit(n) = 0)                   //��� ��
#define PAInBit(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //���� 

#define PBOutBit(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //��� 
#define PBSetBit(n)     (PBOutBit(n) = 1)                   //��� ��
#define PBResetBit(n)   (PBOutBit(n) = 0)                   //��� ��
#define PBInBit(n)      Periph_BB((uint32_t)&GPIOB->IDR,n)  //���� 

#define PCOutBit(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //��� 
#define PCSetBit(n)     (PCOutBit(n) = 1)                   //��� ��
#define PCResetBit(n)   (PCOutBit(n) = 0)                   //��� ��
#define PCInBit(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //���� 

#define PDOutBit(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //��� 
#define PDSetBit(n)     (PDOutBit(n) = 1)                   //��� ��
#define PDResetBit(n)   (PDOutBit(n) = 0)                   //��� ��
#define PDInBit(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //���� 

#define PEOutBit(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //��� 
#define PESetBit(n)     (PEOutBit(n) = 1)                   //��� ��
#define PEResetBit(n)   (PEOutBit(n) = 0)                   //��� ��
#define PEInBit(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //����

#define PFOutBit(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //��� 
#define PFSetBit(n)     (PFOutBit(n) = 1)                   //��� ��
#define PFResetBit(n)   (PFOutBit(n) = 0)                   //��� ��
#define PFInBit(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //����

#define PGOutBit(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //��� 
#define PGSetBit(n)     (PGOutBit(n) = 1)                   //��� ��
#define PGResetBit(n)   (PGOutBit(n) = 0)                   //��� ��
#define PGInBit(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //����


/* �ڲ�SRAM������ ��32MB SRAM�������ķ���ӳ��Ϊ��1MB SRAMbit-band���ķ���(ʵ�ʴ�С����оƬ�й�) */
#define RAM_BASE            0x20000000  // �ڲ�SRAM����ַ  
#define RAM_BB_BASE         0x22000000  // �ڲ�SRAM����������ַ

#define SRAM_ResetBit_BB(VarAddr, BitNumber)    \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 0)
   
#define SRAM_SetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 1)

#define SRAM_GetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)))


/* ��Դ���� ------------------------------------------------------------------*/

/** ����Ϊö�����ͣ�������ָʾ��ʱ��չ **/
/** ָʾ�ƶ��� **/
typedef enum 
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3
} Led_TypeDef;

/** �������� **/
typedef enum 
{  
  KEY1 = 0,
  KEY2 = 1,
  KEY3 = 2,  //Tamper
  KEY4 = 3   //Wakeup
} Button_TypeDef;

/** ����ģʽ���壬��ѯģʽ���ж�ģʽ **/
typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

typedef enum 
{
  COM1 = 0,   
  COM2 = 1,
  COM3 = 2
  
} COM_TypeDef;   

#define UART_RX_BUFFER_SIZE    1024//2048		//tan 20170112
#define UART_FIFO_BUFFER_SIZE		1500//2500 //tan 20170112
typedef struct 
{
  USART_TypeDef* uart;   
  uint32_t uart_rx_length;
  uint32_t uart_rx_done;
  uint32_t uart_rx_write_length;
  uint32_t uart_rx_read_point;
  uint32_t uart_rx_write_point;
//  uint8_t uartRxBuffer[UART_RX_BUFFER_SIZE];
} SZ_USART_DATA_TypeDef;

typedef struct 
{  
  uint32_t uart_read_point;
  uint32_t uart_write_point;
  uint8_t uartTxBuffer[UART_FIFO_BUFFER_SIZE];
} SZ_USART_FIFO;

/** ָʾ�ƹܽ���Դ��������  **/

#define LEDn                             4

/** LEDָʾ�ƹܽ���Դ����  ����͵�ƽ����ָʾ�� **/
#define LED1_PIN_NUM                     2 /* bitband������ʹ�ú궨��  */
#define LED1_PIN                         GPIO_Pin_2
#define LED1_GPIO_PORT                   GPIOD
#define LED1_GPIO_CLK                    RCC_APB2Periph_GPIOD  
#define LED1OBB                          Periph_BB((uint32_t)&LED1_GPIO_PORT->ODR, LED1_PIN_NUM)//�ȼ���Periph_BB((uint32_t)&GPIOD->ODR, 2)

#define LED2_PIN_NUM                     3 
#define LED2_PIN                         GPIO_Pin_3
#define LED2_GPIO_PORT                   GPIOD
#define LED2_GPIO_CLK                    RCC_APB2Periph_GPIOD  
#define LED2OBB                          Periph_BB((uint32_t)&LED2_GPIO_PORT->ODR, LED2_PIN_NUM)

#define LED3_PIN_NUM                     4 
#define LED3_PIN                         GPIO_Pin_4  
#define LED3_GPIO_PORT                   GPIOD
#define LED3_GPIO_CLK                    RCC_APB2Periph_GPIOD  
#define LED3OBB                          Periph_BB((uint32_t)&LED3_GPIO_PORT->ODR, LED3_PIN_NUM)

#define LED4_PIN_NUM                     7
#define LED4_PIN                         GPIO_Pin_7  
#define LED4_GPIO_PORT                   GPIOD
#define LED4_GPIO_CLK                    RCC_APB2Periph_GPIOD  
#define LED4OBB                          Periph_BB((uint32_t)&LED4_GPIO_PORT->ODR, LED4_PIN_NUM)

/** �������ܽ���Դ����     ����͵�ƽ���������� **/
#define BEEP_PIN_NUM                     3 
#define BEEP_PIN                         GPIO_Pin_3    
#define BEEP_GPIO_PORT                   GPIOA    
#define BEEP_GPIO_CLK                    RCC_APB2Periph_GPIOA
#define BEEPOBB                          Periph_BB((uint32_t)&BEEP_GPIO_PORT->ODR, BEEP_PIN_NUM)

/** �����ܽ���Դ��������  **/
#define BUTTONn                          4

/** KEY�����ܽ���Դ����    ��������ʱ����͵�ƽ �����ͷ�ʱ����ߵ�ƽ **/

/** KEY1�����ܽ�  **/
#define KEY1_BUTTON_PIN_NUM              4 
#define KEY1_BUTTON_PIN                  GPIO_Pin_4
#define KEY1_BUTTON_GPIO_PORT            GPIOC
#define KEY1_BUTTON_GPIO_CLK             RCC_APB2Periph_GPIOC
#define KEY1_BUTTON_EXTI_LINE            EXTI_Line4
#define KEY1_BUTTON_EXTI_PORT_SOURCE     GPIO_PortSourceGPIOC
#define KEY1_BUTTON_EXTI_PIN_SOURCE      GPIO_PinSource4
#define KEY1_BUTTON_EXTI_IRQn            EXTI4_IRQn  
#define KEY1IBB                          Periph_BB((uint32_t)&KEY1_BUTTON_GPIO_PORT->IDR, KEY1_BUTTON_PIN_NUM) //�ȼ���Periph_BB((uint32_t)&GPIOC->IDR, 4)

/** KEY2�����ܽ�  **/
#define KEY2_BUTTON_PIN_NUM              10
#define KEY2_BUTTON_PIN                  GPIO_Pin_10
#define KEY2_BUTTON_GPIO_PORT            GPIOB
#define KEY2_BUTTON_GPIO_CLK             RCC_APB2Periph_GPIOB
#define KEY2_BUTTON_EXTI_LINE            EXTI_Line10
#define KEY2_BUTTON_EXTI_PORT_SOURCE     GPIO_PortSourceGPIOB
#define KEY2_BUTTON_EXTI_PIN_SOURCE      GPIO_PinSource10
#define KEY2_BUTTON_EXTI_IRQn            EXTI15_10_IRQn  
#define KEY2IBB                          Periph_BB((uint32_t)&KEY2_BUTTON_GPIO_PORT->IDR, KEY2_BUTTON_PIN_NUM)

/** KEY3����ͬʱҲ��Tamper�ܽ�  **/
#define KEY3_BUTTON_PIN_NUM              13
#define KEY3_BUTTON_PIN                  GPIO_Pin_13
#define KEY3_BUTTON_GPIO_PORT            GPIOC
#define KEY3_BUTTON_GPIO_CLK             RCC_APB2Periph_GPIOC
#define KEY3_BUTTON_EXTI_LINE            EXTI_Line13
#define KEY3_BUTTON_EXTI_PORT_SOURCE     GPIO_PortSourceGPIOC
#define KEY3_BUTTON_EXTI_PIN_SOURCE      GPIO_PinSource13
#define KEY3_BUTTON_EXTI_IRQn            EXTI15_10_IRQn 
#define KEY3IBB                          Periph_BB((uint32_t)&KEY3_BUTTON_GPIO_PORT->IDR, KEY3_BUTTON_PIN_NUM)

/** KEY4����ͬʱҲ��Wakeup�ܽ�  **/
#define KEY4_BUTTON_PIN_NUM              0
#define KEY4_BUTTON_PIN                  GPIO_Pin_0
#define KEY4_BUTTON_GPIO_PORT            GPIOA
#define KEY4_BUTTON_GPIO_CLK             RCC_APB2Periph_GPIOA
#define KEY4_BUTTON_EXTI_LINE            EXTI_Line0
#define KEY4_BUTTON_EXTI_PORT_SOURCE     GPIO_PortSourceGPIOA
#define KEY4_BUTTON_EXTI_PIN_SOURCE      GPIO_PinSource0
#define KEY4_BUTTON_EXTI_IRQn            EXTI0_IRQn 
#define KEY4IBB                          Periph_BB((uint32_t)&KEY4_BUTTON_GPIO_PORT->IDR, KEY4_BUTTON_PIN_NUM)

/** ���ڹܽ���Դ��������  **/
#define COMn                             3

/** ����1�ܽ���Դ����  **/
#define SZ_STM32_COM1_STR                "USART1"
#define SZ_STM32_COM1                    USART1
#define SZ_STM32_COM1_CLK                RCC_APB2Periph_USART1
#define SZ_STM32_COM1_TX_PIN             GPIO_Pin_9
#define SZ_STM32_COM1_TX_GPIO_PORT       GPIOA
#define SZ_STM32_COM1_TX_GPIO_CLK        RCC_APB2Periph_GPIOA
#define SZ_STM32_COM1_RX_PIN             GPIO_Pin_10
#define SZ_STM32_COM1_RX_GPIO_PORT       GPIOA
#define SZ_STM32_COM1_RX_GPIO_CLK        RCC_APB2Periph_GPIOA
#define SZ_STM32_COM1_IRQn               USART1_IRQn

/** ����2�ܽ���Դ���� (USART2 pins remapped on GPIOD) **/
#define SZ_STM32_COM2_STR                "USART2"
#define SZ_STM32_COM2                    USART2
#define SZ_STM32_COM2_CLK                RCC_APB1Periph_USART2
#define SZ_STM32_COM2_TX_PIN             GPIO_Pin_5
#define SZ_STM32_COM2_TX_GPIO_PORT       GPIOD
#define SZ_STM32_COM2_TX_GPIO_CLK        RCC_APB2Periph_GPIOD
#define SZ_STM32_COM2_RX_PIN             GPIO_Pin_6
#define SZ_STM32_COM2_RX_GPIO_PORT       GPIOD
#define SZ_STM32_COM2_RX_GPIO_CLK        RCC_APB2Periph_GPIOD
#define SZ_STM32_COM2_IRQn               USART2_IRQn

/** ����3�ܽ���Դ���� (USART3 pins remapped on GPIOD) **/
#define SZ_STM32_COM3_STR                "USART3"
#define SZ_STM32_COM3                    USART3
#define SZ_STM32_COM3_CLK                RCC_APB1Periph_USART3
#define SZ_STM32_COM3_TX_PIN             GPIO_Pin_8
#define SZ_STM32_COM3_TX_GPIO_PORT       GPIOD
#define SZ_STM32_COM3_TX_GPIO_CLK        RCC_APB2Periph_GPIOD
#define SZ_STM32_COM3_RX_PIN             GPIO_Pin_9
#define SZ_STM32_COM3_RX_GPIO_PORT       GPIOD
#define SZ_STM32_COM3_RX_GPIO_CLK        RCC_APB2Periph_GPIOD
#define SZ_STM32_COM3_IRQn               USART3_IRQn

#define SD_SPI                           SPI1
#define SD_SPI_CLK                       RCC_APB2Periph_SPI1
#define SD_SPI_SCK_PIN                   GPIO_Pin_5                  /* PA.05 */
#define SD_SPI_SCK_GPIO_PORT             GPIOA                       /* GPIOA */
#define SD_SPI_SCK_GPIO_CLK              RCC_APB2Periph_GPIOA
#define SD_SPI_MISO_PIN                  GPIO_Pin_6                  /* PA.06 */
#define SD_SPI_MISO_GPIO_PORT            GPIOA                       /* GPIOA */
#define SD_SPI_MISO_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_SPI_MOSI_PIN                  GPIO_Pin_7                  /* PA.07 */
#define SD_SPI_MOSI_GPIO_PORT            GPIOA                       /* GPIOA */
#define SD_SPI_MOSI_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_CS_PIN                        GPIO_Pin_11                 /* PD.11 */
#define SD_CS_GPIO_PORT                  GPIOD                       /* GPIOD */
#define SD_CS_GPIO_CLK                   RCC_APB2Periph_GPIOD
#define SD_DETECT_PIN                    GPIO_Pin_14                 /* PE.14 */
#define SD_DETECT_GPIO_PORT              GPIOB                       /* GPIOB */
#define SD_DETECT_GPIO_CLK               RCC_APB2Periph_GPIOB
#if 0
#define SD_SPI                           SPI3
#define SD_SPI_CLK                       RCC_APB1Periph_SPI3
#define SD_SPI_SCK_PIN                   GPIO_Pin_10                 /* PC.10 */
#define SD_SPI_SCK_GPIO_PORT             GPIOC                       /* GPIOC */
#define SD_SPI_SCK_GPIO_CLK              RCC_APB2Periph_GPIOC
#define SD_SPI_MISO_PIN                  GPIO_Pin_11                 /* PC.11 */
#define SD_SPI_MISO_GPIO_PORT            GPIOC                       /* GPIOC */
#define SD_SPI_MISO_GPIO_CLK             RCC_APB2Periph_GPIOC
#define SD_SPI_MOSI_PIN                  GPIO_Pin_12                 /* PC.12 */
#define SD_SPI_MOSI_GPIO_PORT            GPIOC                       /* GPIOC */
#define SD_SPI_MOSI_GPIO_CLK             RCC_APB2Periph_GPIOC
#define SD_CS_PIN                        GPIO_Pin_4                  /* PA.04 */
#define SD_CS_GPIO_PORT                  GPIOA                       /* GPIOA */
#define SD_CS_GPIO_CLK                   RCC_APB2Periph_GPIOA
#define SD_DETECT_PIN                    GPIO_Pin_0                  /* PE.00 */
#define SD_DETECT_GPIO_PORT              GPIOE                       /* GPIOE */
#define SD_DETECT_GPIO_CLK               RCC_APB2Periph_GPIOE
#endif


extern const uint8_t STM32F10x_STR[];
extern __IO uint32_t TimingDelay;
extern uint32_t STM32DeviceSerialID[3]; /* ȫ�ֱ���IntDeviceSerial��Ŷ������豸ID */
extern SZ_USART_DATA_TypeDef SZ_USART1_DATA, SZ_USART2_DATA;

extern USART_TypeDef* COM_USART[COMn] ;
extern volatile SZ_USART_FIFO UartRxFifo;

/** @defgroup STM32_EVAL_SPI_SD_Exported_Types
  * @{
  */ 

typedef enum
{
/**
  * @brief  SD reponses and error flags
  */
  SD_RESPONSE_NO_ERROR      = (0x00),
  SD_IN_IDLE_STATE          = (0x01),
  SD_ERASE_RESET            = (0x02),
  SD_ILLEGAL_COMMAND        = (0x04),
  SD_COM_CRC_ERROR          = (0x08),
  SD_ERASE_SEQUENCE_ERROR   = (0x10),
  SD_ADDRESS_ERROR          = (0x20),
  SD_PARAMETER_ERROR        = (0x40),
  SD_RESPONSE_FAILURE       = (0xFF),

/**
  * @brief  Data response error
  */
  SD_DATA_OK                = (0x05),
  SD_DATA_CRC_ERROR         = (0x0B),
  SD_DATA_WRITE_ERROR       = (0x0D),
  SD_DATA_OTHER_ERROR       = (0xFF)
} SD_Error;

/** 
  * @brief  Card Specific Data: CSD Register   
  */ 
typedef struct
{
  __IO uint8_t  CSDStruct;            /*!< CSD structure */
  __IO uint8_t  SysSpecVersion;       /*!< System specification version */
  __IO uint8_t  Reserved1;            /*!< Reserved */
  __IO uint8_t  TAAC;                 /*!< Data read access-time 1 */
  __IO uint8_t  NSAC;                 /*!< Data read access-time 2 in CLK cycles */
  __IO uint8_t  MaxBusClkFrec;        /*!< Max. bus clock frequency */
  __IO uint16_t CardComdClasses;      /*!< Card command classes */
  __IO uint8_t  RdBlockLen;           /*!< Max. read data block length */
  __IO uint8_t  PartBlockRead;        /*!< Partial blocks for read allowed */
  __IO uint8_t  WrBlockMisalign;      /*!< Write block misalignment */
  __IO uint8_t  RdBlockMisalign;      /*!< Read block misalignment */
  __IO uint8_t  DSRImpl;              /*!< DSR implemented */
  __IO uint8_t  Reserved2;            /*!< Reserved */
  __IO uint32_t DeviceSize;           /*!< Device Size */
  __IO uint8_t  MaxRdCurrentVDDMin;   /*!< Max. read current @ VDD min */
  __IO uint8_t  MaxRdCurrentVDDMax;   /*!< Max. read current @ VDD max */
  __IO uint8_t  MaxWrCurrentVDDMin;   /*!< Max. write current @ VDD min */
  __IO uint8_t  MaxWrCurrentVDDMax;   /*!< Max. write current @ VDD max */
  __IO uint8_t  DeviceSizeMul;        /*!< Device size multiplier */
  __IO uint8_t  EraseGrSize;          /*!< Erase group size */
  __IO uint8_t  EraseGrMul;           /*!< Erase group size multiplier */
  __IO uint8_t  WrProtectGrSize;      /*!< Write protect group size */
  __IO uint8_t  WrProtectGrEnable;    /*!< Write protect group enable */
  __IO uint8_t  ManDeflECC;           /*!< Manufacturer default ECC */
  __IO uint8_t  WrSpeedFact;          /*!< Write speed factor */
  __IO uint8_t  MaxWrBlockLen;        /*!< Max. write data block length */
  __IO uint8_t  WriteBlockPaPartial;  /*!< Partial blocks for write allowed */
  __IO uint8_t  Reserved3;            /*!< Reserded */
  __IO uint8_t  ContentProtectAppli;  /*!< Content protection application */
  __IO uint8_t  FileFormatGrouop;     /*!< File format group */
  __IO uint8_t  CopyFlag;             /*!< Copy flag (OTP) */
  __IO uint8_t  PermWrProtect;        /*!< Permanent write protection */
  __IO uint8_t  TempWrProtect;        /*!< Temporary write protection */
  __IO uint8_t  FileFormat;           /*!< File Format */
  __IO uint8_t  ECC;                  /*!< ECC code */
  __IO uint8_t  CSD_CRC;              /*!< CSD CRC */
  __IO uint8_t  Reserved4;            /*!< always 1*/
} SD_CSD;

/** 
  * @brief  Card Identification Data: CID Register   
  */
typedef struct
{
  __IO uint8_t  ManufacturerID;       /*!< ManufacturerID */
  __IO uint16_t OEM_AppliID;          /*!< OEM/Application ID */
  __IO uint32_t ProdName1;            /*!< Product Name part1 */
  __IO uint8_t  ProdName2;            /*!< Product Name part2*/
  __IO uint8_t  ProdRev;              /*!< Product Revision */
  __IO uint32_t ProdSN;               /*!< Product Serial Number */
  __IO uint8_t  Reserved1;            /*!< Reserved1 */
  __IO uint16_t ManufactDate;         /*!< Manufacturing Date */
  __IO uint8_t  CID_CRC;              /*!< CID CRC */
  __IO uint8_t  Reserved2;            /*!< always 1 */
} SD_CID;

/** 
  * @brief SD Card information 
  */
typedef struct
{
  SD_CSD SD_csd;
  SD_CID SD_cid;
  uint32_t CardCapacity;  /*!< Card Capacity */
  uint32_t CardBlockSize; /*!< Card Block Size */
} SD_CardInfo;


/** ͨ�ú�������  **/  
void delay(__IO uint32_t nCount);
void NVIC_GroupConfig(void);
void SZ_STM32_SysTickInit(uint32_t HzPreSecond);
void SysTickDelay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

void GetDeviceSerialID(void);

/** �ӿں�������  **/  
void SZ_STM32_LEDInit(Led_TypeDef Led);
void SZ_STM32_LEDOn(Led_TypeDef Led);
void SZ_STM32_LEDOff(Led_TypeDef Led);
void SZ_STM32_LEDToggle(Led_TypeDef Led);

void SZ_STM32_COM_Init(int rateId);

void SZ_STM32_BEEPInit(void);
void SZ_STM32_BEEPOn(void);
void SZ_STM32_BEEPOff(void);
void SZ_STM32_BEEPToggle(void);

void SZ_STM32_KEYInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t SZ_STM32_KEYGetState(Button_TypeDef Button);
uint32_t SZ_STM32_KEYScan(void);

void __SZ_STM32_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
void SZ_STM32_COMInit(COM_TypeDef COM, uint32_t BaudRate);
void NVIC_COMConfiguration(void);

uint32_t UsartReadData(SZ_USART_DATA_TypeDef* SZ_USART,  uint8_t* Buffer);

int usartFifoAvailable(SZ_USART_FIFO *fifo);
int readUsartFifo(SZ_USART_FIFO *fifo, int8_t *buf, int32_t len);
int writeUsartFifo(SZ_USART_FIFO *fifo, int8_t *buf, int32_t len);

void UART2_Printf(uint8_t *buf, uint32_t len);

extern volatile SZ_USART_FIFO WifiRxFifo;
    
#ifdef __cplusplus
}
#endif

#endif
/******************* (C) COPYRIGHT 2013 www.armjishu.com *****END OF FILE****/

