#include <STDINT.h>
#include "Err_Type.h"
#include "STM32F446xx.h"

#include "../Inc/SYSCFG/SYSCFG_interface.h"
#include "../Inc/SYSCFG/SYSCFG_prv.h"




uint8_t SYSCFG_u8SetExtiPort(SYSCFG_Line_t copy_u8Line, SYSCFG_Port_t copy_u8Port)
{
	uint8_t Local_u8ErrorState=OK;
	if(((copy_u8Line>=SYSCFG_EXTI0_)&&(copy_u8Line<=SYSCFG_EXTI15_))&&((copy_u8Port>=SYSCFG_PORTA)&&(copy_u8Port<=SYSCFG_PORTH)))
		{
			/*clearing required line bits */
			SYSCFG->EXTICR[copy_u8Line/SYSCFG_SHIFT] &= ~(SYSCFG_MASK<<((copy_u8Line%SYSCFG_SHIFT)*SYSCFG_SHIFT));
			/*Assigning required line bits */
			SYSCFG->EXTICR[copy_u8Line/SYSCFG_SHIFT] |= copy_u8Port<<((copy_u8Line%SYSCFG_SHIFT)*SYSCFG_SHIFT);
		}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
