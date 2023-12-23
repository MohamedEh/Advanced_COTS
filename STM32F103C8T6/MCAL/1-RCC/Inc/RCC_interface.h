#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

typedef enum
{
	OFF=0,
	ON
}RCC_Status_t;

typedef enum
{
	HSI=0,
	HSE,
	PLL
}RCC_Clock_t;

typedef enum
{
	SDIO=10,
	FSMC=8,
	CRC=6,
	FLITF=4,
	SRAM=2,
	DMA2=1,
	DMA1=0,
	TIM11=21,
	TIM10=20,
	TIM9=19,
	ADC3=15,
	USART1=14,
	TIM8=13,
	SPI1=12,
	TIM1=11,
	ADC2=10,
	ADC1=9,
	IOPG=8,
	IOPF=7,
	IOPE=6,
	IOPD=5,
	IOPC=4,
	IOPB=3,
	IOPA=2,
	AFIO_=0,
	DAC=29,
	PWR=28,
	BKP=27,
	CAN=25,
	USB=23,
	I2C2=22,
	I2C1=21,
	UART5=20,
	UART4=19,
	USART3=18,
	USART2=17,
	SPI3=15,
	SPI2=14,
	WWDG=11,
	TIM14=8,
	TIM13=7,
	TIM12=6,
	TIM7=5,
	TIM6=4,
	TIM5=3,
	TIM4=2,
	TIM3=1,
	TIM2=0
}RCC_PeripheralEnable_t;

typedef enum
{
	MULT_2=0,
	MULT_3,
	MULT_4,
	MULT_5,
	MULT_6,
	MULT_7,
	MULT_8,
	MULT_9,
	MULT_10,
	MULT_11,
	MULT_12,
	MULT_13,
	MULT_14,
	MULT_15,
	MULT_16
}RCC_PllMul_t;

typedef enum
{
	HSE_CLK_NO_DIV=0,
	HSE_CLK_DIV_2

}RCC_PllXtpre_t;

typedef enum
{
	HSI_SRC=0,
	HSE_SRC
}RCC_PllSrc_t;

typedef enum 
{
	HCLK_NO_DIV=0,
	HCLK_DIV_2=4,
	HCLK_DIV_4,
	HCLK_DIV_8,
	HCLK_DIV_16
}RCC_ApbPrescaler_t;

typedef enum
{
	SYSCLK_NO_DIV=0,
	SYSCLK_DIV_2=8,
	SYSCLK_DIV_4,
	SYSCLK_DIV_8,
	SYSCLK_DIV_16,
	SYSCLK_DIV_64,
	SYSCLK_DIV_128,
	SYSCLK_DIV_256,
	SYSCLK_DIV_512,
}RCC_AhbPrescaler_t;



uint8_t RCC_u8SetClkStsSynch(uint8_t copy_u8ClkType,uint8_t copy_u8Status);
uint8_t RCC_vSetSysClk(uint8_t copy_u8ClkType);
uint8_t RCC_vHseConfig(uint8_t copy_u8DivSts);
uint8_t RCC_vPllConfig(uint8_t copy_u8PllMul,uint8_t copy_u8PllSrc);
uint8_t RCC_vAhbEnableClk(uint8_t copy_u8Peripheral);
uint8_t RCC_vAhbDisableClk(uint8_t copy_u8Peripheral);
uint8_t RCC_vApb1EnableClk(uint8_t copy_u8Peripheral);
uint8_t RCC_vApb1DisableClk(uint8_t copy_u8Peripheral);
uint8_t RCC_vApb2EnableClk(uint8_t copy_u8Peripheral);
uint8_t RCC_vApb2DisableClk(uint8_t copy_u8Peripheral);

#endif
