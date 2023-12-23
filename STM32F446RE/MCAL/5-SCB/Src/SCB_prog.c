#include <stdint.h>
#include "Err_Type.h"

#include "STM32F446xx.h"
#include "SCB_prv.h"
#include "SCB_interface.h"

uint8_t SCB_u8SetPriorityGroup(SCB_PriGroup_t copy_u8PriGroup)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8PriGroup>=GROUP4_SUB0)&&(copy_u8PriGroup<=GROUP0_SUB4))
	{
		SCB->AIRCR = ((VECTKEY<<VECT_SHIFT) | (copy_u8PriGroup<<PRIGROUP_SHIFT));
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
