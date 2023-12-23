#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
	EXTI_RISING=0,
	EXTI_FALLING,
	EXTI_BOTH
}EXTI_Trigger_t;

typedef enum
{
	EXTI_INT_DISABLE=0,
	EXTI_INT_ENABLE,

}EXTI_IntState_t;

typedef enum
{
	EXTI0_=0,
	EXTI1_,
	EXTI2_,
	EXTI3_,
	EXTI4_,
	EXTI5_,
	EXTI6_,
	EXTI7_,
	EXTI8_,
	EXTI9_,
	EXTI10_,
	EXTI11_,
	EXTI12_,
	EXTI13_,
	EXTI14_,
	EXTI15_,
}EXTI_Line_t;
typedef struct
{
	EXTI_Line_t ExtiLine;
	EXTI_Trigger_t TriggerSource;
	EXTI_IntState_t IntState;
	void (*CallBackFunc)(void);
}EXTI_Config_t;

uint8_t EXTI_u8Init(EXTI_Config_t *copy_pConfig);
uint8_t EXTI_u8SetTrigSrc(EXTI_Line_t copy_u8ExtiLine,EXTI_Trigger_t copy_u8TrigSrc);
uint8_t EXTI_u8EnableInt(EXTI_Line_t copy_u8ExtiLine);
uint8_t EXTI_u8DisableInt(EXTI_Line_t copy_u8ExtiLine);
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t copy_u8ExtiLine);
uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_t copy_u8ExtiLine, uint8_t *copy_pu8copy_Val);

#endif
