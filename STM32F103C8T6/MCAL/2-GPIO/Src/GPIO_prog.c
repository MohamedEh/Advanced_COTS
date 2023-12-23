/*********************************************************/
/* @file GPIO_prog.c
 * @author Mohamed Ehab
 * @brief the GPIO main source file, including functions' definitions
 *
 */
#include <stdint.h>
#include "Err_Type.h"

#include "STM32F103xx.h"
#include "GPIO_interface.h"
#include "GPIO_prv.h"


static GPIO_RegDef_t* GPIO_Port[GPIO_PERIPHERAL_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG};
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
		if((copy_pPinConfig->Port<=PORTG)&&(copy_pPinConfig->PinNum<=PIN15))
		{
			//Select GPIO Mode : input , output, analog, alternate function
			//Clear Mode bits
			if(copy_pPinConfig->PinNum<=PIN7)
			{
				(GPIO_Port[copy_pPinConfig->Port]->CRL) &= ~(CRL_MASK<<(copy_pPinConfig->PinNum*CRL_PIN_ACCESS));
				//Assign Mode bits
				(GPIO_Port[copy_pPinConfig->Port]->CRL) |= ((copy_pPinConfig->Mode|(copy_pPinConfig->CNFMode<<CNF_ACCESS))<<(copy_pPinConfig->PinNum*CRL_PIN_ACCESS));
			}
			else if(copy_pPinConfig->PinNum>=PIN8)
			{
				(GPIO_Port[copy_pPinConfig->Port]->CRH) &= ~(CRH_MASK<<((copy_pPinConfig->PinNum%8)*CRH_PIN_ACCESS));
				//Assign Mode bits
				(GPIO_Port[copy_pPinConfig->Port]->CRH) |= ((copy_pPinConfig->Mode|(copy_pPinConfig->CNFMode<<CNF_ACCESS))<<((copy_pPinConfig->PinNum%8)*CRH_PIN_ACCESS));
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
/* @fn GPIO_u8AFPinInit
 * @brief the function Set the Alternate Function of certain pin
 * @param[in] copy_pPinConfig :  the AF values of the pin
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8AFPinInit(const AFIO_PinConfig_t* copy_pPinConfig)
{
	uint8_t Local_u8ErrorState=OK;
	if(copy_pPinConfig!=NULL)
	{
		if((copy_pPinConfig->Port<=PORTG)&&(copy_pPinConfig->PinNum<=PIN15)&&(copy_pPinConfig->Peripheral>=AFIO_SPI1)&&(copy_pPinConfig->Peripheral<=AFIO_SWJ_CFG))
		{
			//Select GPIO Mode : input , output, analog, alternate function
			//Clear Mode bits
			AFIO->EVCR &= ~(EVCR_MASK);

			AFIO->EVCR |= (copy_pPinConfig->PinNum)|(copy_pPinConfig->Port<<EVCR_PORT_ACCESS)|(EVCR_EVOE_SET_VALUE<<EVCR_EVOE_ACCESS);

			if(((copy_pPinConfig->Peripheral>=AFIO_SPI1)&&(copy_pPinConfig->Peripheral<=AFIO_USART2))||((copy_pPinConfig->Peripheral>=AFIO_PD01)&&(copy_pPinConfig->Peripheral<=AFIO_ADC2_REG))||(copy_pPinConfig->Peripheral==AFIO_TIM4))
			{
				AFIO->MAPR &= ~(MAPR_MASK_1<<copy_pPinConfig->Peripheral);
				AFIO->MAPR |= (copy_pPinConfig->Remap<<copy_pPinConfig->Peripheral);
			}

			else if(((copy_pPinConfig->Peripheral>=AFIO_USART3)&&(copy_pPinConfig->Peripheral>=AFIO_TIM3))||(copy_pPinConfig->Peripheral==AFIO_CAN))
			{
				AFIO->MAPR &= ~(MAPR_MASK_2<<copy_pPinConfig->Peripheral);
				AFIO->MAPR |= (copy_pPinConfig->Remap<<copy_pPinConfig->Peripheral);
			}

			else if(copy_pPinConfig->Peripheral==AFIO_SWJ_CFG)
			{
				AFIO->MAPR &= ~(MAPR_MASK_SWJ<<copy_pPinConfig->Peripheral);
				AFIO->MAPR |= (copy_pPinConfig->SWJ<<copy_pPinConfig->Peripheral);
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

	if((copy_u8Port<=PORTG)&&(copy_u8PinNum<=PIN15))

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
	if((copy_u8Port<=PORTG)&&(copy_u8PinNum<=PIN15))
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
	if((copy_u8Port<=PORTG)&&(copy_u8PinNum<=PIN15))
	{
		*copy_pPinVal= ((GPIO_Port[copy_u8Port]->IDR)>>copy_u8PinNum) & 1;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
