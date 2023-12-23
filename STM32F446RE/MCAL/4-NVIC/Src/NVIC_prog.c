#include <stdint.h>
#include "Err_Type.h"

#include "STM32F446xx.h"
#include "NVIC_prv.h"
#include "NVIC_interface.h"


uint8_t NVIC_u8Enable(NVIC_IRQ_t copy_u8IrqNum)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR))
	{
		NVIC->ISER[copy_u8IrqNum/NVIC_REGISTER_SHIFT]=1<<(copy_u8IrqNum%NVIC_REGISTER_SHIFT);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t NVIC_u8Disable(NVIC_IRQ_t copy_u8IrqNum)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR))
	{
		NVIC->ICER[copy_u8IrqNum/NVIC_REGISTER_SHIFT]=1<<(copy_u8IrqNum%NVIC_REGISTER_SHIFT);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t NVIC_u8SetPendingFlag(NVIC_IRQ_t copy_u8IrqNum)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR))
	{
		NVIC->ISPR[copy_u8IrqNum/NVIC_REGISTER_SHIFT]=1<<(copy_u8IrqNum%NVIC_REGISTER_SHIFT);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t NVIC_u8ClearPendingFlag(NVIC_IRQ_t copy_u8IrqNum)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR))
	{
		NVIC->ICPR[copy_u8IrqNum/NVIC_REGISTER_SHIFT]=1<<(copy_u8IrqNum%NVIC_REGISTER_SHIFT);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t NVIC_u8GetActiveFlag(NVIC_IRQ_t copy_u8IrqNum, uint8_t *copy_u8Val)
{
	uint8_t Local_u8ErrorState=OK;
	if(copy_u8Val!=NULL)
	{
		if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR))
		{
			*copy_u8Val= (((NVIC->IABR[copy_u8IrqNum/NVIC_REGISTER_SHIFT])>>(copy_u8IrqNum%NVIC_REGISTER_SHIFT)))&1;

		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}

uint8_t NVIC_u8SetIrqPriority(NVIC_IRQ_t copy_u8IrqNum,NVIC_Priority_t copy_u8Priority)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8IrqNum>=WWDG)&&(copy_u8IrqNum<=FMPI2C1_ERROR)&&(copy_u8Priority>=PRIORITY_0)&&(copy_u8Priority<=PRIORITY_15))
	{
		NVIC->IPR[copy_u8IrqNum]= (copy_u8Priority<<IPR_SHIFT);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
