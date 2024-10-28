/*
 * RCC_F411.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ganibllo
 */
#include "RCC_F411.h"

void RCC_Init(void){

	//Enable internal High-speed clock
	RCC->CR |= RCC_CR_HSION;

	//w8 enabling
	while(!(RCC->CR & RCC_CR_HSIRDY));

	FLASH->ACR |= FLASH_ACR_PRFTEN;

	// Flash 2 wait state
	FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
	FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_3WS;

	//Dis. external osc.
	RCC->CR &= ~RCC_CR_HSEON;
	RCC->CR &= ~RCC_CR_HSEBYP;
	RCC->CR &= ~RCC_CR_CSSON;

	//Clear bits for PLL
	RCC->CR &= ~RCC_CR_PLLON;
	RCC->CR &= ~RCC_CR_PLLI2SON;

	//Dis.PLL for settings
	RCC->CR &= ~RCC_CR_PLLON;

	//Clear "/M" then make it /8
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_3;

	//Clear "*N" then make it *80
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_1;

	//Clear "/p" then make it /2
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLP_1;

	//Choose HSI in "PLL Source MUX"
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;

	//Dis.PLL for "USB OTG_FS"
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLQ_2;

	//Enable "MAIN PLL" and w8 enabling
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLON));

	//"System clock MUX"
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_1;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1);

	//AHB "/x " then "/1"
	RCC->CFGR &= ~RCC_CFGR_HPRE;

	//APB1 = /2
	RCC->CFGR &= ~RCC_CFGR_PPRE1;
	RCC->CFGR |= RCC_CFGR_PPRE1;
	//APB2 = /1
	RCC->CFGR &= ~RCC_CFGR_PPRE2;

	//No clock for external input signal? need to check
	RCC->CFGR &= ~RCC_CFGR_RTCPRE;

	//PLL clock selected for external output
	RCC->CFGR &= ~RCC_CFGR_MCO1;
	RCC->CFGR |= RCC_CFGR_MCO1;
	//SYSCLK selected for external output
	RCC->CFGR &= ~RCC_CFGR_MCO2;

	RCC->CFGR &= ~RCC_CFGR_MCO1PRE;
	RCC->CFGR &= ~RCC_CFGR_MCO2PRE;

	//Enable clk for GPIOs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

}


void Systick_init(void){
	//Dis. count
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

	//interrupt
	SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

	//Источник синхронизации без делителя
	SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

	//Count to = 0;
	SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	//Count = 0;
    SysTick->VAL &= ~SysTick_VAL_CURRENT_Msk;
    //Count to TimerTick
	SysTick->LOAD = TimerTick;
	SysTick->VAL = TimerTick;

	//Enb. count
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}