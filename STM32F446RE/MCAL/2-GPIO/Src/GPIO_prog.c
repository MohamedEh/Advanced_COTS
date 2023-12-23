/*********************************************************/
/* @file GPIO_prog.c
 * @author Mohamed Ehab
 * @brief the GPIO main source file, including functions' definitions
 *
 */
#include <stdint.h>
#include "Err_Type.h"

#include "STM32F446xx.h"
#include "GPIO_interface.h"
#include "GPIO_prv.h"


static GPIO_RegDef_t* GPIO_Port[GPIO_PERIPHERAL_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};
/*************************************************************/
 /*@fn GPIO_u8PinInit
  * @brief the function initializes the gpio pin according to the input parameters
  * @param[in] Pinconfig : the initialization values of the pin
  * @retval ErrorStatus
  *
 */
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* copy_pPinConfig)
{
	uint8_t Local_u8ErrorState=OK;
	if(copy_pPinConfig!=NULL)
	{
		if((copy_pPinConfig->Port<=PORTH)&&(copy_pPinConfig->PinNum<=PIN15))
		{
			//Select GPIO Mode : input , output, analog, alternate function
			//Clear Mode bits
			(GPIO_Port[copy_pPinConfig->Port]->MODER) &= ~(MODER_MASK<<(copy_pPinConfig->PinNum*MODER_PIN_ACCESS));
			//Assign Mode bits
			(GPIO_Port[copy_pPinConfig->Port]->MODER) |= (copy_pPinConfig->Mode<<(copy_pPinConfig->PinNum*MODER_PIN_ACCESS));

			//Select GPIO pull state: nopull,pullup,pulldown
			//Clear Pull type bits
			(GPIO_Port[copy_pPinConfig->Port]->PUPDR) &= ~(PUPDR_MASK<<(copy_pPinConfig->PinNum*PUPDR_PIN_ACCESS));
			//Assign Pull type bits
			(GPIO_Port[copy_pPinConfig->Port]->PUPDR) |= (copy_pPinConfig->Mode<<(copy_pPinConfig->PinNum*PUPDR_PIN_ACCESS));

			//Select GPIO Output type & speed in case pin is output or AF
			if((copy_pPinConfig->Mode==OUTPUT)||(copy_pPinConfig->Mode==ALTERNATE_FUNCTION))
			{
				//Select output type : PUSH PULL or Open Drain
				//Clear Output type bits
				(GPIO_Port[copy_pPinConfig->Port]->OTYPER) &= ~(OTYPER_MASK<<copy_pPinConfig->PinNum);
				//Assign Output type bits
				(GPIO_Port[copy_pPinConfig->Port]->OTYPER) |= (copy_pPinConfig->OutputType<<copy_pPinConfig->PinNum);

				//Select Output Speed: Low,Medium,High,Fast
				//Clear Output Speed bits
				(GPIO_Port[copy_pPinConfig->Port]->OSPEEDR) &= ~(OSPEEDR_MASK<<(copy_pPinConfig->PinNum*OSPEEDR_PIN_ACCESS));
				//Assign Output Speed bits
				(GPIO_Port[copy_pPinConfig->Port]->OSPEEDR) |= (copy_pPinConfig->Mode<<(copy_pPinConfig->PinNum*OSPEEDR_PIN_ACCESS));

				//Select the Pin Alternate Function
				if(copy_pPinConfig->Mode==ALTERNATE_FUNCTION)
				{
					//AF type
					//Clear req bits using mask
					GPIO_Port[copy_pPinConfig->Port]->AFR[copy_pPinConfig->PinNum/AFR_PIN_SHIFTING] &= ~(AFR_MASK<<((copy_pPinConfig->PinNum%AFR_PIN_SHIFTING)*AFR_PIN_ACCESS));
					//Assign req bits
					GPIO_Port[copy_pPinConfig->Port]->AFR[copy_pPinConfig->PinNum/AFR_PIN_SHIFTING] |= (copy_pPinConfig->AltFunc<<((copy_pPinConfig->PinNum%AFR_PIN_SHIFTING)*AFR_PIN_ACCESS));
				}
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
/*************************************************************/
 /* @fn GPIO_u8SetPinValue
  * @brief the function outputs a certain value on an output pin
  * @param[in] copy_u8Port : the port number, get options @Port_t enum
  * @param[in] PinNum : The pin  number , get options @Pin_t enum
  * @param[in] PinVal : the output value , get options @PinVal_t enum
  * @retval ErrorStatus
  *
 */
uint8_t GPIO_u8SetPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t copy_u8PinVal)
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8Port<=PORTH)&&(copy_u8PinNum<=PIN15))

	{
		if (copy_u8PinVal==PIN_LOW)
		{
			(GPIO_Port[copy_u8Port]->ODR) &= ~(1<<copy_u8PinNum);
			//GPIO_Port[copy_u8Port]->BSRR = 1<<(16+copy_u8PinNum)  faster
		}
		else if(copy_u8PinVal==PIN_HIGH)
		{
			(GPIO_Port[copy_u8Port]->ODR) |= 1<<copy_u8PinNum;
			//GPIO_Port[copy_u8Port]->BSRR = 1<<(copy_u8PinNum)  faster

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

uint8_t GPIO_u8TogglePinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Port<=PORTH)&&(copy_u8PinNum<=PIN15))
	{
		(GPIO_Port[copy_u8Port]->ODR) ^= 1<<copy_u8PinNum;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}

uint8_t GPIO_u8ReadPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t* copy_pPinVal)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Port<=PORTH)&&(copy_u8PinNum<=PIN15))
	{
		*copy_pPinVal= ((GPIO_Port[copy_u8Port]->IDR)>>copy_u8PinNum) & 1;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
