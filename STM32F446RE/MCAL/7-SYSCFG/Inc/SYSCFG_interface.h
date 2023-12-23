#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

typedef enum
{
	SYSCFG_EXTI0_=0,
	SYSCFG_EXTI1_,
	SYSCFG_EXTI2_,
	SYSCFG_EXTI3_,
	SYSCFG_EXTI4_,
	SYSCFG_EXTI5_,
	SYSCFG_EXTI6_,
	SYSCFG_EXTI7_,
	SYSCFG_EXTI8_,
	SYSCFG_EXTI9_,
	SYSCFG_EXTI10_,
	SYSCFG_EXTI11_,
	SYSCFG_EXTI12_,
	SYSCFG_EXTI13_,
	SYSCFG_EXTI14_,
	SYSCFG_EXTI15_,
}SYSCFG_Line_t;

typedef enum
{
	SYSCFG_PORTA=0,
	SYSCFG_PORTB,
	SYSCFG_PORTC,
	SYSCFG_PORTD,
	SYSCFG_PORTE,
	SYSCFG_PORTF,
	SYSCFG_PORTG,
	SYSCFG_PORTH
}SYSCFG_Port_t;

uint8_t SYSCFG_u8SetExtiPort(SYSCFG_Line_t copy_u8Line, SYSCFG_Port_t copy_u8Port);
#endif
