#ifndef SYSTICK_PRV_H
#define SYSTICK_PRV_H

#define CLKSOURCE			2U				//bit 2
#define OVF_TICKS			16777216UL		//2^n
#define TIMER_FREQ			8UL				//in MHZ
#define US_CONVERSION		1000			//ms->us
#define ENABLE				0U				//bit 0
#define COUNTFLAG			16U				//bit 16
#endif
