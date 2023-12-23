#include <STDINT.h>
#include "Err_Type.h"
#include "STM32F446xx.h"

#include "../Inc/EXTI/EXTI_interface.h"
#include "../Inc/EXTI/EXTI_prv.h"
/*global array of pointer to function to hold callback function*/
static void (*func[EXTI_NUM])(void)={NULL};

uint8_t EXTI_u8Init(EXTI_Config_t *copy_pConfig)
{
	uint8_t Local_u8ErrorState=OK;
	if(copy_pConfig!=NULL)
	{
		if((copy_pConfig->ExtiLine>=EXTI0_)&&(copy_pConfig->ExtiLine<=EXTI15_))
		{
			if(copy_pConfig->CallBackFunc!=NULL)
			{
				/*Setting the trigger configuration*/
				if((copy_pConfig->TriggerSource)==EXTI_RISING)
				{
					//clear required Falling exti line bit
					EXTI->FTSR &= ~(1<<(copy_pConfig->ExtiLine));
					//clear required Rising exti line bit
					EXTI->RTSR &= ~(1<<(copy_pConfig->ExtiLine));
					//set required exti line bit
					EXTI->RTSR |= (1<<(copy_pConfig->ExtiLine));

				}
				else if((copy_pConfig->TriggerSource)==EXTI_FALLING)
				{
					//clear required Rising exti line bit
					EXTI->RTSR &= ~(1<<(copy_pConfig->ExtiLine));
					//clear Falling required exti line bit
					EXTI->FTSR &= ~(1<<(copy_pConfig->ExtiLine));
					//set required exti line bit
					EXTI->FTSR |= (1<<(copy_pConfig->ExtiLine));

				}
				else if((copy_pConfig->TriggerSource)==EXTI_BOTH)
				{
					//clear required exti line bit
					EXTI->FTSR &= ~(1<<(copy_pConfig->ExtiLine));
					EXTI->RTSR &= ~(1<<(copy_pConfig->ExtiLine));
					//set required exti line bit
					EXTI->FTSR |= (1<<(copy_pConfig->ExtiLine));
					EXTI->RTSR |= (1<<(copy_pConfig->ExtiLine));


				}
				else
				{
					Local_u8ErrorState=NOK;
				}


				/*Call back function*/
				func[(copy_pConfig->ExtiLine)]=copy_pConfig->CallBackFunc;

				/*Setting the Enable configuration*/
				//clear required exti line bit
				EXTI->IMR &= ~(1<<(copy_pConfig->ExtiLine));
				//Assigning required exti line bit
				EXTI->IMR |= ((copy_pConfig->IntState)<<(copy_pConfig->ExtiLine));

			}
			else
			{
				Local_u8ErrorState=NULL_PTR;
			}
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

uint8_t EXTI_u8SetTrigSrc(EXTI_Line_t copy_u8ExtiLine,EXTI_Trigger_t copy_u8TrigSrc)
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8ExtiLine>=EXTI0_)&&(copy_u8ExtiLine<=EXTI15_))
	{

			/*Setting the trigger configuration*/
			if((copy_u8TrigSrc)==EXTI_RISING)
			{
				//clear required Falling exti line bit
				EXTI->FTSR &= ~(1<<(copy_u8ExtiLine));
				//clear required Rising exti line bit
				EXTI->RTSR &= ~(1<<(copy_u8ExtiLine));
				//set required exti line bit
				EXTI->RTSR |= (1<<(copy_u8ExtiLine));

			}
			else if((copy_u8TrigSrc)==EXTI_FALLING)
			{
				//clear required Rising exti line bit
				EXTI->RTSR &= ~(1<<(copy_u8ExtiLine));
				//clear Falling required exti line bit
				EXTI->FTSR &= ~(1<<(copy_u8ExtiLine));
				//set required exti line bit
				EXTI->FTSR |= (1<<(copy_u8ExtiLine));

			}
			else if((copy_u8TrigSrc)==EXTI_BOTH)
			{
				//clear required exti line bit
				EXTI->FTSR &= ~(1<<(copy_u8ExtiLine));
				EXTI->RTSR &= ~(1<<(copy_u8ExtiLine));
				//set required exti line bit
				EXTI->FTSR |= (1<<(copy_u8ExtiLine));
				EXTI->RTSR |= (1<<(copy_u8ExtiLine));


			}
			else
			{
				Local_u8ErrorState=NOK;
			}



	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}

uint8_t EXTI_u8EnableInt(EXTI_Line_t copy_u8ExtiLine)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8ExtiLine>=EXTI0_)&&(copy_u8ExtiLine<=EXTI15_))
	{
		EXTI->IMR |= (1<<copy_u8ExtiLine);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t EXTI_u8DisableInt(EXTI_Line_t copy_u8ExtiLine)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8ExtiLine>=EXTI0_)&&(copy_u8ExtiLine<=EXTI15_))
	{
		EXTI->IMR &= ~(1<<copy_u8ExtiLine);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t copy_u8ExtiLine)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8ExtiLine>=EXTI0_)&&(copy_u8ExtiLine<=EXTI15_))
	{
		EXTI->PR = (1<<copy_u8ExtiLine);

	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_t copy_u8ExtiLine, uint8_t *copy_pu8copy_Val)
{
	uint8_t Local_u8ErrorState=OK;
	if(copy_pu8copy_Val!=NULL)
	{
		if((copy_u8ExtiLine>=EXTI0_)&&(copy_u8ExtiLine<=EXTI15_))
		{
			*copy_pu8copy_Val = ((EXTI->PR>>copy_u8ExtiLine)&1);

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

void EXTI0_IRQHandler()
{
	/*Clear Pending Flag*/
	EXTI_u8ClearPendingFlag(EXTI0_);
	/*Call callback function*/
	func[EXTI0_]();
}
void EXTI1_IRQHandler()
{
	/*Clear Pending Flag*/
	EXTI_u8ClearPendingFlag(EXTI1_);
	/*Call callback function*/
	func[EXTI1_]();
}
void EXTI2_IRQHandler()
{
	/*Clear Pending Flag*/
	EXTI_u8ClearPendingFlag(EXTI2_);
	/*Call callback function*/
	func[EXTI2_]();
}
void EXTI3_IRQHandler()
{
	/*Clear Pending Flag*/
	EXTI_u8ClearPendingFlag(EXTI3_);
	/*Call callback function*/
	func[EXTI3_]();
}
void EXTI4_IRQHandler()
{
	/*Clear Pending Flag*/
	EXTI_u8ClearPendingFlag(EXTI4_);
	/*Call callback function*/
	func[EXTI4_]();
}
void EXTI9_5_IRQHandler()
{
	if((((EXTI->PR)>>EXTI5_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI5_);
		/*Call callback function*/
		func[EXTI5_]();
	}
	if((((EXTI->PR)>>EXTI6_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI6_);
		/*Call callback function*/
		func[EXTI6_]();
	}
	if((((EXTI->PR)>>EXTI7_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI7_);
		/*Call callback function*/
		func[EXTI7_]();
	}
	if((((EXTI->PR)>>EXTI8_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI8_);
		/*Call callback function*/
		func[EXTI8_]();
	}
	if((((EXTI->PR)>>EXTI9_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI9_);
		/*Call callback function*/
		func[EXTI9_]();
	}
}
void EXTI15_10_IRQHandler()
{
	if((((EXTI->PR)>>EXTI10_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI10_);
		/*Call callback function*/
		func[EXTI10_]();
	}
	if((((EXTI->PR)>>EXTI1_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI11_);
		/*Call callback function*/
		func[EXTI11_]();
	}
	if((((EXTI->PR)>>EXTI12_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI12_);
		/*Call callback function*/
		func[EXTI12_]();
	}
	if((((EXTI->PR)>>EXTI13_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI13_);
		/*Call callback function*/
		func[EXTI13_]();
	}
	if((((EXTI->PR)>>EXTI14_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI14_);
		/*Call callback function*/
		func[EXTI14_]();
	}
	if((((EXTI->PR)>>EXTI15_)&1)==1)
	{
		/*Clear Pending Flag*/
		EXTI_u8ClearPendingFlag(EXTI15_);
		/*Call callback function*/
		func[EXTI15_]();
	}
}
