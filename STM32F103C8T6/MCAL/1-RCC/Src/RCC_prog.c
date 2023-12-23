#include <stdint.h>
#include "Err_Type.h"
#include "BIT_MATH.h"

#include "STM32F103xx.h"
#include "RCC_prv.h"
#include "RCC_interface.h"

RCC_RegDef_t* RCC_pReg = (RCC_RegDef_t*)0x40021000;


uint8_t RCC_u8SetClkStsSynch(uint8_t copy_u8ClkType,uint8_t copy_u8Status)
//Function to set the status of the clock sources
{
	uint8_t Local_u8ErrorState=OK;
	uint32_t Local_u32Counter=0;

	switch(copy_u8ClkType)
	{
	case HSE:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC_pReg->CR,CR_HSEON);
			while (((GET_BIT(RCC_pReg->CR,CR_HSERDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC_pReg->CR,CR_HSEON);

		}
		break;

	case HSI:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC_pReg->CR,CR_HSION);
			while (((GET_BIT(RCC_pReg->CR,CR_HSIRDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC_pReg->CR,CR_HSION);

		}
		break;

	case PLL:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC_pReg->CR,CR_PLLON);
			while (((GET_BIT(RCC_pReg->CR,CR_PLLRDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC_pReg->CR,CR_PLLON);
		}
		break;

	default:
		Local_u8ErrorState=NOK;
		break;


	}
	if(Local_u32Counter==RCC_u32TIMEOUT_COUNT)
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;

}
uint8_t RCC_vSetSysClk(uint8_t copy_u8ClkType)
//Function to set the source clock of the system
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8ClkType>=HSI)&&(copy_u8ClkType<=PLL))
	{
		RCC_pReg->CFGR = (RCC_pReg->CFGR &(~(CFGR_SW_MASK))) | copy_u8ClkType;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vHseConfig(uint8_t copy_u8DivSts)
//function to set the division status of the HSE clock source
{
	uint8_t Local_u8ErrorState=OK;

	if(copy_u8DivSts==HSE_CLK_DIV_2)
	{

		SET_BIT(RCC_pReg->CFGR,CFGR_PLLXTPRE);
	}
	else if (copy_u8DivSts==HSE_CLK_NO_DIV)
	{
		CLR_BIT(RCC_pReg->CFGR,CFGR_PLLXTPRE);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vPllConfig(uint8_t copy_u8PllMul,uint8_t copy_u8PllSrc)
//function to set the config parameters of the PLL clock source
{
	uint8_t Local_u8ErrorState=OK;

	if(((copy_u8PllMul>=MULT_2)&&(copy_u8PllMul<=MULT_16))&&((copy_u8PllSrc>=HSI)&&(copy_u8PllSrc<=HSE)))
	{
		RCC_pReg->CFGR =(RCC_pReg->CFGR&(~(CFGR_PLLMUL_MASK<<18)))|(((copy_u8PllMul<<18)|(copy_u8PllSrc<<16)));
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhbEnableClk(uint8_t copy_u8Peripheral)
//Function to Enable clock to peripherals of the AHB bus
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8Peripheral>=DMA1)&&(copy_u8Peripheral<=SDIO))
	{
		SET_BIT(RCC_pReg->AHBENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;


}
uint8_t RCC_vAhbDisableClk(uint8_t copy_u8Peripheral)
//Function to DISABLE clock to peripherals of the AHB bus

{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=DMA1)&&(copy_u8Peripheral<=SDIO))
	{
		CLR_BIT(RCC_pReg->AHBENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}	return Local_u8ErrorState;
}
uint8_t RCC_vApb1EnableClk(uint8_t copy_u8Peripheral)
//Function to Enable clock to peripherals of the APB1 bus

{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM2)&&(copy_u8Peripheral<=DAC))
	{
		SET_BIT(RCC_pReg->APB1ENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t RCC_vApb1DisableClk(uint8_t copy_u8Peripheral)
//Function to Disable clock to peripherals of the APB1 bus

{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM2)&&(copy_u8Peripheral<=DAC))
	{
		CLR_BIT(RCC_pReg->APB1ENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t RCC_vApb2EnableClk(uint8_t copy_u8Peripheral)
//Function to Enable clock to peripherals of the APB2 bus

{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=AFIO_)&&(copy_u8Peripheral<=TIM11))
	{
		SET_BIT(RCC_pReg->APB2ENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
uint8_t RCC_vApb2DisableClk(uint8_t copy_u8Peripheral)
//Function to Disable clock to peripherals of the APB2 bus

{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=AFIO_)&&(copy_u8Peripheral<=TIM11))
	{
		CLR_BIT(RCC_pReg->APB2ENR,copy_u8Peripheral);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
