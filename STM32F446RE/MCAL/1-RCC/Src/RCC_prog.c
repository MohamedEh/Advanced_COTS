#include <stdint.h>
#include "Err_Type.h"
#include "BIT_MATH.h"
#include "STM32F446xx.h"

#include "RCC_prv.h"
#include "RCC_interface.h"




uint8_t RCC_u8SetClkStsSynch(uint8_t copy_u8ClkType,uint8_t copy_u8Status)
{
	uint8_t Local_u8ErrorState=OK;
	uint32_t Local_u32Counter;

	switch(copy_u8ClkType)
	{
	case HSE:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC->CR,CR_HSEON);
			while (((GET_BIT(RCC->CR,CR_HSERDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC->CR,CR_HSEON);

		}
		break;

	case HSI:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC->CR,CR_HSION);
			while (((GET_BIT(RCC->CR,CR_HSIRDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC->CR,CR_HSION);

		}
		break;

	case PLL_P: case PLL_R:
		if(copy_u8Status==ON)
		{
			SET_BIT(RCC->CR,CR_PLLON);
			while (((GET_BIT(RCC->CR,CR_PLLRDY))!= ON)&&(Local_u32Counter<RCC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
		}
		else if(copy_u8Status==OFF)
		{
			CLR_BIT(RCC->CR,CR_PLLON);
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
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8ClkType>=HSI)&&(copy_u8ClkType<=PLL_R))
	{
		RCC->CFGR = (RCC->CFGR &(~(CFGR_SW_MASK))) | copy_u8ClkType;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vHseConfig(uint8_t copy_u8BypassSts)
{
	uint8_t Local_u8ErrorState=OK;

	if((copy_u8BypassSts>=HSE_NOT_BYPASSED)&&(copy_u8BypassSts<=HSE_BYPASSED))
	{
		RCC->CR = ((RCC->CR &(~(CFGR_BYPASS_MASK<<CR_HSEBYP))) | (copy_u8BypassSts<<CR_HSEBYP));
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vPllConfig(RCC_Pll_Config_t* copy_pConfig)
{
	uint8_t Local_u8ErrorState=OK;

	if(((copy_pConfig->Pll_SRC>=HSI_SRC)&&(copy_pConfig->Pll_SRC<=HSE_SRC))&&((copy_pConfig->Pll_R>=PLLR_2)&&(copy_pConfig->Pll_R<=PLLR_7))&&((copy_pConfig->Pll_Q>=PLLQ_2)&&(copy_pConfig->Pll_Q<=PLLQ_15))&&((copy_pConfig->Pll_P>=PLLP_2)&&(copy_pConfig->Pll_P<=PLLP_8))&&((copy_pConfig->Pll_N>=PLLN_50)&&(copy_pConfig->Pll_N<=PLLN_100))&&((copy_pConfig->Pll_M>=PLLM_2)&&(copy_pConfig->Pll_M<=PLLM_63)))
	{

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLM_MASK<<PLL_CFGR_PLLM));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_M)<<PLL_CFGR_PLLM);

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLN_MASK<<PLL_CFGR_PLLN));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_N)<<PLL_CFGR_PLLN);

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLP_MASK<<PLL_CFGR_PLLP));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_P)<<PLL_CFGR_PLLP);

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLSRC_MASK<<PLL_CFGR_PLLSRC));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_SRC)<<PLL_CFGR_PLLSRC);

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLQ_MASK<<PLL_CFGR_PLLQ));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_Q)<<PLL_CFGR_PLLQ);

		RCC->PLLCFGR &= (~(PLL_CFGR_PLLR_MASK<<PLL_CFGR_PLLR));
		RCC->PLLCFGR |= ((copy_pConfig->Pll_R)<<PLL_CFGR_PLLR);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb1EnableClk(RCC_AHB1PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=GPIOAEN)&&(copy_u8Peripheral<=OTGHSULPIEN))
	{
		RCC->AHB1ENR |= (PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb1DisableClk(RCC_AHB1PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=GPIOAEN)&&(copy_u8Peripheral<=OTGHSULPIEN))
	{
		RCC->AHB1ENR &= ~(PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb2EnableClk(RCC_AHB2PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=DCMIEN)&&(copy_u8Peripheral<=OTGFSEN))
	{
		RCC->AHB2ENR |= (PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb2DisableClk(RCC_AHB2PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=DCMIEN)&&(copy_u8Peripheral<=OTGFSEN))
	{
		RCC->AHB2ENR &= ~(PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb3EnableClk(RCC_AHB3PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=FMCEN)&&(copy_u8Peripheral<=QSPIEN))
	{
		RCC->AHB3ENR |= (PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vAhb3DisableClk(RCC_AHB3PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=FMCEN)&&(copy_u8Peripheral<=QSPIEN))
	{
		RCC->AHB3ENR &= ~(PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vApb1EnableClk(RCC_APB1PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM2EN)&&(copy_u8Peripheral<=DACEN))
	{
		RCC->APB1ENR |= (PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vApb1DisableClk(RCC_APB1PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM2EN)&&(copy_u8Peripheral<=DACEN))
	{
		RCC->APB1ENR &= ~(PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vApb2EnableClk(RCC_APB2PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM1EN)&&(copy_u8Peripheral<=SAI2EN))
	{
		RCC->APB2ENR |= (PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
uint8_t RCC_vApb2DisableClk(RCC_APB2PeripheralEnable_t copy_u8Peripheral)
{
	uint8_t Local_u8ErrorState=OK;
	if((copy_u8Peripheral>=TIM1EN)&&(copy_u8Peripheral<=SAI2EN))
	{
		RCC->APB2ENR &= ~(PERIPHERAL_MASK<<copy_u8Peripheral);
	}


	else
	{
		Local_u8ErrorState=NOK;
	}


	return Local_u8ErrorState;
}
