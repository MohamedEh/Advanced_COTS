#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

typedef enum
{
	ON=0,
	OFF
}RCC_Status_t;

typedef enum
{
	HSI=0,
	HSE,
	PLL_P,
	PLL_R
}RCC_Clock_t;

typedef enum
{
	GPIOAEN=0,
	GPIOBEN,
	GPIOCEN,
	GPIODEN,
	GPIOEEN,
	GPIOFEN,
	GPIOGEN,
	GPIOHEN,
	CRCEN=12,
	BKPSRAMEN=18,
	DMA1EN=21,
	DMA2EN,
	OTGHSEN=29,
	OTGHSULPIEN

}RCC_AHB1PeripheralEnable_t;

typedef enum
{
	DCMIEN=0,
	OTGFSEN=7,


}RCC_AHB2PeripheralEnable_t;

typedef enum
{
	FMCEN=0,
	QSPIEN,


}RCC_AHB3PeripheralEnable_t;

typedef enum
{
	TIM2EN=0,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN=11,
	SPI2EN=14,
	SPI3EN,
	SPDIFRXEN,
	USART2EN,
	USART3EN,
	USART4EN,
	USART5EN,
	I2C1EN,
	I2C2EN,
	I2C3EN,
	FMPI2C1EN,
	CAN1EN,
	CAN2EN,
	CECEN,
	PWREN,
	DACEN
}RCC_APB1PeripheralEnable_t;

typedef enum
{
	TIM1EN=0,
	TIM8EN,
	USART1EN=4,
	USART6EN,
	ADC1EN=8,
	ADC2EN,
	ADC3EN,
	SDIOEN,
	SPI1EN,
	SPI4EN,
	SYSCFGEN,
	TIM9EN=16,
	TIM10EN,
	TIM11EN,
	SAI1EN=22,
	SAI2EN

}RCC_APB2PeripheralEnable_t;

typedef enum
{
	PLLR_2=2,
	PLLR_3,
	PLLR_4,
	PLLR_5,
	PLLR_6,
	PLLR_7
}RCC_PllR_Div_t;

typedef enum
{
	PLLQ_2=2,
	PLLQ_3,
	PLLQ_4,
	PLLQ_5,
	PLLQ_6,
	PLLQ_7,
	PLLQ_8,
	PLLQ_9,
	PLLQ_10,
	PLLQ_11,
	PLLQ_12,
	PLLQ_13,
	PLLQ_14,
	PLLQ_15
}RCC_PllQ_Div_t;


typedef enum
{
	HSI_SRC=0,
	HSE_SRC
}RCC_PllSrc_t;

typedef enum
{
	PLLP_2=2,
	PLLP_4=4,
	PLLP_6=6,
	PLLP_8=8


}RCC_PllP_Div_t;

typedef enum {
    PLLN_50 = 50,
    PLLN_51,
    PLLN_52,
    PLLN_53,
    PLLN_54,
    PLLN_55,
    PLLN_56,
    PLLN_57,
    PLLN_58,
    PLLN_59,
    PLLN_60,
    PLLN_61,
    PLLN_62,
    PLLN_63,
    PLLN_64,
    PLLN_65,
    PLLN_66,
    PLLN_67,
    PLLN_68,
    PLLN_69,
    PLLN_70,
    PLLN_71,
    PLLN_72,
    PLLN_73,
    PLLN_74,
    PLLN_75,
    PLLN_76,
    PLLN_77,
    PLLN_78,
    PLLN_79,
    PLLN_80,
    PLLN_81,
    PLLN_82,
    PLLN_83,
    PLLN_84,
    PLLN_85,
    PLLN_86,
    PLLN_87,
    PLLN_88,
    PLLN_89,
    PLLN_90,
    PLLN_91,
    PLLN_92,
    PLLN_93,
    PLLN_94,
    PLLN_95,
    PLLN_96,
    PLLN_97,
    PLLN_98,
    PLLN_99,
    PLLN_100
}RCC_PllN_Mull_t;

typedef enum {
    PLLM_2 = 2,
    PLLM_3,
    PLLM_4,
    PLLM_5,
    PLLM_6,
    PLLM_7,
    PLLM_8,
    PLLM_9,
    PLLM_10,
    PLLM_11,
    PLLM_12,
    PLLM_13,
    PLLM_14,
    PLLM_15,
    PLLM_16,
    PLLM_17,
    PLLM_18,
    PLLM_19,
    PLLM_20,
    PLLM_21,
    PLLM_22,
    PLLM_23,
    PLLM_24,
    PLLM_25,
    PLLM_26,
    PLLM_27,
    PLLM_28,
    PLLM_29,
    PLLM_30,
    PLLM_31,
    PLLM_32,
    PLLM_33,
    PLLM_34,
    PLLM_35,
    PLLM_36,
    PLLM_37,
    PLLM_38,
    PLLM_39,
    PLLM_40,
    PLLM_41,
    PLLM_42,
    PLLM_43,
    PLLM_44,
    PLLM_45,
    PLLM_46,
    PLLM_47,
    PLLM_48,
    PLLM_49,
    PLLM_50,
    PLLM_51,
    PLLM_52,
    PLLM_53,
    PLLM_54,
    PLLM_55,
    PLLM_56,
    PLLM_57,
    PLLM_58,
    PLLM_59,
    PLLM_60,
    PLLM_61,
    PLLM_62,
    PLLM_63
}RCC_PllM_Div_t;

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

typedef enum
{
	HSE_NOT_BYPASSED=0,
	HSE_BYPASSED,
}RCC_Hse_Bypass_t;

typedef struct
{
	RCC_PllR_Div_t Pll_R;
	RCC_PllQ_Div_t Pll_Q;
	RCC_PllSrc_t Pll_SRC;
	RCC_PllP_Div_t Pll_P;
	RCC_PllN_Mull_t Pll_N;
	RCC_PllM_Div_t Pll_M;
}RCC_Pll_Config_t;

uint8_t RCC_u8SetClkStsSynch(uint8_t copy_u8ClkType,uint8_t copy_u8Status);
uint8_t RCC_vSetSysClk(uint8_t copy_u8ClkType);
uint8_t RCC_vHseConfig(uint8_t copy_u8BypassSts);
uint8_t RCC_vPllConfig(RCC_Pll_Config_t* copy_pConfig);
uint8_t RCC_vAhb1EnableClk(RCC_AHB1PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vAhb1DisableClk(RCC_AHB1PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vAhb2EnableClk(RCC_AHB2PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vAhb2DisableClk(RCC_AHB2PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vAhb3EnableClk(RCC_AHB3PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vAhb3DisableClk(RCC_AHB3PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vApb1EnableClk(RCC_APB1PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vApb1DisableClk(RCC_APB1PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vApb2EnableClk(RCC_APB2PeripheralEnable_t copy_u8Peripheral);
uint8_t RCC_vApb2DisableClk(RCC_APB2PeripheralEnable_t copy_u8Peripheral);

#endif
