#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*
*@Port_t
*/
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG
}Port_t;
/*
*@Pin_t
*/
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
	
}Pin_t;

typedef enum
{
	OPTION1=0,						//Input : Analog, Output : out Push Pull
	OPTION2,						//Input : Floating Input, Output : out Open Drain
	OPTION3,                        //Input : Input Pull up or down, Output : AF Push Pull
	OPTION4							//Input : Reserved, Output : AF Open Drain

}CNF_Mode_t;


typedef enum
{
	INPUT=0,
	OUTPUT_10MHZ,
	OUTPUT_2MHZ,
	OUTPUT_50MHZ
}Mode_t;



typedef enum
{
	FULL_SWJ=0,
	FULL_SWJ_WITHOUT_NJTRST,
	SW_DP_ENABLED,
	JTAG_DP_ENABLED=4
}SWJ_Cfg_t;

typedef enum
{
	AFIO_SPI1=0,
	AFIO_I2C1,
	AFIO_USART1,
	AFIO_USART2,
	AFIO_USART3=4,
	AFIO_TIM1=6,
	AFIO_TIM2=8,
	AFIO_TIM3=10,
	AFIO_TIM4=12,
	AFIO_CAN=13,
	AFIO_PD01=15,
	AFIO_TIM5_CH4,
	AFIO_ADC1_INJ,
	AFIO_ADC1_REG,
	AFIO_ADC2_INJ,
	AFIO_ADC2_REG,
	AFIO_SWJ_CFG=24,
	AFIO_TIM9=5,
	AFIO_TIM10,
	AFIO_TIM11,
	AFIO_TIM13,
	AFIO_TIM14,
	AFIO_FSMC

}AFIO_Peripherals_t;

typedef enum
{
	NO_REMAP=0,											/*ADC2_REG :mapped to EXTI11
														ADC2_INJ :mapped to EXTI15
														ADC1_REG :mapped to EXTI11
														ADC1_INJ :mapped to EXTI15
														TIM5CH4 :mapped to PA3
														PD01 :No Remap of PD0, PD1
														CAN :RX mapped to PA11, TX to PA12
														TIM4 : remaped (TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
														TIM3 : remaped (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
														TIM2 : remaped (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
														TIM1 : remaped  (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
														USART3 : remaped  (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
														USART2 : remaped   (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
														USART1 : remaped   (TX/PA9, RX/PA10)
														I2C1 : remaped    (SCL/PB6, SDA/PB7)
														SPI1 : remaped     (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)

	 	 	 	 	 	 	 	 	 	 	 	 	 	 */
	PARTIAL1,											/*ADC2_REG :mapped to TIM8_TRGO
														ADC2_INJ :mapped to TIM8_Channel4
														ADC1_REG :mapped to TIM8_TRGO
														ADC1_INJ :mapped to TIM8_Channel4
														TIM5CH4 :LSI internal clock is connected to TIM5_CH4 input for calibration purpose
														PD01 :PD0 remapped on OSC_IN, PD1 remapped on OSC_OUT
														CAN :Not used
														TIM4 :  Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
														TIM3 : Not used
														TIM2 :  Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
														TIM1 : partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)
														USART3 :  Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
														USART2 :  Remap (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
														USART1 : Remap (TX/PB6, RX/PB7)
														I2C1 :  Remap (SCL/PB8, SDA/PB9)
														SPI1 :  Remap (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
														*/
	PARTIAL2,											/*ADC2_REG :Not Used
														ADC2_INJ :Not Used
														ADC1_REG :Not Used
														ADC1_INJ :Not Used
														TIM5CH4 :Not Used
														PD01 :Not Used
														CAN : CAN_RX mapped to PB8, CAN_TX mapped to PB9
														TIM4 :  Not Used
														TIM3 : Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
														TIM2 :  Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
														TIM1 : Not Used
														USART3 :  Not Used
														USART2 :  Not Used
														USART1 :Not Used
														I2C1 :  Not Used
														SPI1 :  Not Used
														*/
	FULL_REMAP,											/*ADC2_REG :Not Used
														ADC2_INJ :Not Used
														ADC1_REG :Not Used
														ADC1_INJ :Not Used
														TIM5CH4 :Not Used
														PD01 :Not Used
														CAN : CAN_RX mapped to PD0, CAN_TX mapped to PD1
														TIM4 :  Not Used
														TIM3 : Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
														TIM2 :  Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
														TIM1 :  Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12)
														USART3 :   Full remap (TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12)
														USART2 :  Not Used
														USART1 :Not Used
														I2C1 :  Not Used
														SPI1 :  Not Used
														*/
}AFIO_Remap_t;
/*
*@PinVal_t
*/
typedef enum 
{
	PIN_LOW=0,
	PIN_HIGH
}PinVal_t;

typedef struct
{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	CNF_Mode_t CNFMode;
}GPIO_PinConfig_t;

typedef struct
{
	Port_t Port;			//Port A -> E only
	Pin_t PinNum;
	AFIO_Peripherals_t Peripheral;
	AFIO_Remap_t Remap;
	SWJ_Cfg_t SWJ;
}AFIO_PinConfig_t;


uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* copy_pPinConfig);

uint8_t GPIO_u8AFPinInit(const AFIO_PinConfig_t* copy_pPinConfig);

uint8_t GPIO_u8SetPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t copy_u8PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum);

uint8_t GPIO_u8ReadPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t* copy_pPinVal);


#endif
