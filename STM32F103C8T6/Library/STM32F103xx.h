#ifndef STM32F103XX_H
#define STM32F103XX_H

//**************************Core Peripherals Base Addresses*************************
#define SYSTICK_BASE_ADDRESS		0xE000E010UL

//**************************Various Memories Base Addresses*************************

#define FLASH_BASE_ADDRESS			0x08000000UL
#define SRAM_BASE_ADDRESS			0x20000000UL
#define ROM_BASE_ADDRESS			0x1FFF0000UL

//**************************AHB Peripherals Base Addresses*************************


#define RCC_BASE_ADDRESS			0x40021000UL



                                                             
//*************************APB1 Peripherals Base Addresses*************************


                                                             
//*************************APB2 Peripherals Base Addresses*****************************
#define GPIOA_BASE_ADDRESS			0x40010800UL
#define GPIOB_BASE_ADDRESS			0x40010C00UL
#define GPIOC_BASE_ADDRESS			0x40011000UL
#define GPIOD_BASE_ADDRESS			0x40011400UL
#define GPIOE_BASE_ADDRESS			0x40011800UL
#define GPIOF_BASE_ADDRESS			0x40011C00UL
#define GPIOG_BASE_ADDRESS			0x40012000UL

#define AFIO_BASE_ADDRESS			0x40010000UL

//*************************AFIO Register Definition Structure*************************

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t MAPR2;
}AFIO_RegDef_t;
                                                             
//*************************GPIO Register Definition Structure*************************

typedef struct
{
	volatile uint32_t CRL;						//GPIO PORT Mode REGISTER
	volatile uint32_t CRH;						//GPIO PORT Output Type REGISTER
	volatile uint32_t IDR;						//GPIO PORT Output Speed REGISTER
	volatile uint32_t ODR;						//GPIO PORT Pull Up/Down REGISTER
	volatile uint32_t BSRR;							//GPIO PORT Input Data REGISTER
	volatile uint32_t BRR;							//GPIO PORT Output Data REGISTER
	volatile uint32_t LCKR;							//GPIO PORT Bit Set/Reset REGISTER
}GPIO_RegDef_t;


//*************************RCC Register Definition Structure*************************

typedef struct 
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_RegDef_t;

//*************************SYSTICK Register Definition Structure*************************
typedef struct
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}SYSTICK_RegDef_t;

//*************************GPIO Peripheral Definition*************************
#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF			((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG			((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

//*************************RCC Peripheral Definition*************************
#define RCC				((RCC_RegDef_t*)RCC_BASE_ADDRESS)

//*************************SYSTICK Peripheral Definition*************************

#define SYSTICK			((SYSTICK_RegDef_t*)SYSTICK_BASE_ADDRESS)

//*************************AFIO Peripheral Definition*************************

#define AFIO			((AFIO_RegDef_t*)AFIO_BASE_ADDRESS)

#endif
