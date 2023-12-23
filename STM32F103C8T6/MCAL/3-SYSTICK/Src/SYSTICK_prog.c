/*********************************************************/
/* @file SYSTICK_prog.c
 * @author Mohamed Ehab
 * @brief the SYSTICK main source file, including functions' definitions
 *
 */
#include <stdint.h>

#include <math.h>
#include "Err_Type.h"

#include "STM32F103xx.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_prv.h"

/*************************************************************/
 /*@fn SYSTICK_u8DelayMs
  * @brief the function sets the delay time in milliseconds
  * @param[in] copy_u32Time : The time required in milliseconds
  * @retval ErrorStatus
  */
uint8_t SYSTICK_u8DelayMs(uint32_t copy_u32Time)
{
	//You must enable FPU
	uint8_t Local_u8ErrorState=OK;
	uint32_t Local_u32Counter=0;
	//set clock source to processor clock
	//clear clock source bit
	SYSTICK->CSR &= ~(1<<CLKSOURCE);
	//Assign Clock Source bit
	SYSTICK->CSR |= (1<<CLKSOURCE);

	//Get Tov=2^resolution * Ttick
	uint32_t Local_u32Tov = (OVF_TICKS/TIMER_FREQ); //in us
	uint32_t Local_u32Preload = (uint32_t)((float)((float)(((float)copy_u32Time*(float)US_CONVERSION)/(float)Local_u32Tov)-(float)((copy_u32Time*US_CONVERSION)/Local_u32Tov))*(float)OVF_TICKS);//preload needed ticks
	uint32_t Local_u32Cov = ceil((float)(((float)copy_u32Time*US_CONVERSION)/(float)Local_u32Tov)); //no of overflow

	//Set Preload Value
	SYSTICK->RVR = Local_u32Preload;

	//Enable Counter
	SYSTICK->CSR |= (1<<ENABLE);
	while(Local_u32Counter<Local_u32Cov)
	{
		while(!((SYSTICK->CSR>>COUNTFLAG)&1));
		Local_u32Counter++;
	}
	//Disable Counter
	SYSTICK->CSR &= ~(1<<ENABLE);
	return Local_u8ErrorState;
}
uint8_t SYSTICK_u8DelayUs(uint32_t copy_u32Time)
{
	uint8_t Local_u8ErrorState=OK;
	uint32_t Local_u32Counter=0;
	//set clock source to processor clock
	//clear clock source bit
	SYSTICK->CSR &= ~(1<<CLKSOURCE);
	//Assign Clock Source bit
	SYSTICK->CSR |= (1<<CLKSOURCE);

	//Get Tov=2^resolution * Ttick
	uint32_t Local_u32Tov = (OVF_TICKS/TIMER_FREQ); //in us
	uint32_t Local_u32Preload = (uint32_t)((float)((float)(((float)copy_u32Time)/(float)Local_u32Tov)-(float)((copy_u32Time)/Local_u32Tov))*(float)OVF_TICKS);//preload needed ticks
	uint32_t Local_u32Cov = ceil((float)(((float)copy_u32Time)/(float)Local_u32Tov)); //no of overflow

	//Set Preload Value
	SYSTICK->RVR = Local_u32Preload;

	//Enable Counter
	SYSTICK->CSR |= (1<<ENABLE);
	while(Local_u32Counter<Local_u32Cov)
	{
		while(!((SYSTICK->CSR>>COUNTFLAG)&1));
		Local_u32Counter++;
	}
	//Disable Counter
	SYSTICK->CSR &= ~(1<<ENABLE);
	return Local_u8ErrorState;
}
