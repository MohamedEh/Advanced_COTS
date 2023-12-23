#ifndef STM32F446XX_H
#define STM32F446XX_H

//**************************Core Peripherals Base Addresses*************************
#define SYSTICK_BASE_ADDRESS		0xE000E010UL
#define NVIC_BASE_ADDRESS			0xE000E100UL
#define SCB_BASE_ADDRESS			0xE000E008UL

//**************************Various Memories Base Addresses*************************

#define FLASH_BASE_ADDRESS			0x08000000UL
#define SRAM_BASE_ADDRESS			0x20000000UL
#define ROM_BASE_ADDRESS			0x1FFF0000UL

//**************************AHB1 Peripherals Base Addresses*************************
#define GPIOA_BASE_ADDRESS			0x40020000UL
#define GPIOB_BASE_ADDRESS			0x40020400UL
#define GPIOC_BASE_ADDRESS			0x40020800UL
#define GPIOD_BASE_ADDRESS			0x40020C00UL
#define GPIOE_BASE_ADDRESS			0x40021000UL
#define GPIOF_BASE_ADDRESS			0x40021400UL
#define GPIOG_BASE_ADDRESS			0x40021800UL
#define GPIOH_BASE_ADDRESS			0x40021C00UL

#define RCC_BASE_ADDRESS			0x40023800UL

//*************************AHB2 Peripherals Base Addresses*************************
                                                          

														  
//*************************AHB3 Peripherals Base Addresses*************************


                                                             
//*************************APB1 Peripherals Base Addresses*************************


                                                             
//*************************APB2 Peripherals Base Addresses*****************************
#define SYSCFG_BASE_ADDRESS			0x40013800UL
#define EXTI_BASE_ADDRESS			0x40013C00UL

                                                             
//*************************GPIO Register Definition Structure*************************

typedef struct
{
	volatile uint32_t MODER;						//GPIO PORT Mode REGISTER
	volatile uint32_t OTYPER;						//GPIO PORT Output Type REGISTER
	volatile uint32_t OSPEEDR;						//GPIO PORT Output Speed REGISTER
	volatile uint32_t PUPDR;						//GPIO PORT Pull Up/Down REGISTER
	volatile uint32_t IDR;							//GPIO PORT Input Data REGISTER
	volatile uint32_t ODR;							//GPIO PORT Output Data REGISTER
	volatile uint32_t BSRR;							//GPIO PORT Bit Set/Reset REGISTER
	volatile uint32_t LCKR;							//GPIO PORT Lock REGISTER
	volatile uint32_t AFR[2];						//GPIO PORT Alternate Function REGISTER
}GPIO_RegDef_t;


//*************************RCC Register Definition Structure*************************

typedef struct 
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t Reserved0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t Reserved1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t Reserved2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t Reserved3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t Reserved4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t Reserved5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t Reserved6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t DCKCFGR2;
	
}RCC_RegDef_t;

//*************************SYSTICK Register Definition Structure*************************
typedef struct
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}SYSTICK_RegDef_t;

//*************************NVIC Register Definition Structure*************************


typedef struct
{
	volatile uint32_t ISER[8];
	volatile uint32_t Res1[24];
	volatile uint32_t ICER[8];
	volatile uint32_t Res2[24];
	volatile uint32_t ISPR[8];
	volatile uint32_t Res3[24];
	volatile uint32_t ICPR[8];
	volatile uint32_t Res4[24];
	volatile uint32_t IABR[8];
	volatile uint32_t Res5[56];
	volatile uint8_t IPR[240];
}NVIC_RegDef_t;

//*************************SCB Register Definition Structure*************************


typedef struct
{
	volatile uint32_t ACTLR;
	volatile uint32_t Res1[829];
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR;
	volatile uint32_t HFSR;
	volatile uint32_t Res2;
	volatile uint32_t MMAR;
	volatile uint32_t BFAR;
	volatile uint32_t AFSR;
}SCB_RegDef_t;

//*************************EXTI Register Definition Structure*************************


typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_RegDef_t;


//*************************SYSCFG Register Definition Structure*************************


typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
	volatile uint32_t CFGR;

}SYSCFG_RegDef_t;
//*************************GPIO Peripheral Definition*************************
#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF			((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG			((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH			((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

//*************************RCC Peripheral Definition*************************
#define RCC				((RCC_RegDef_t*)RCC_BASE_ADDRESS)

//*************************SYSTICK Peripheral Definition*************************

#define SYSTICK			((SYSTICK_RegDef_t*)SYSTICK_BASE_ADDRESS)

//*************************NVIC Peripheral Definition*************************


#define NVIC			((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

//*************************SCB Peripheral Definition*************************


#define SCB			((SCB_RegDef_t*)SCB_BASE_ADDRESS)


//*************************SYSCFG Peripheral Definition*************************


#define SYSCFG			((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)


//*************************EXTI Peripheral Definition*************************


#define EXTI			((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)



#endif
