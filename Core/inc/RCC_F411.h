/*
 * RCC_F411.h
 *
 *  Created on: Oct 26, 2024
 *      Author: ganibllo
 */

#ifndef INC_RCC_F411_H_
#define INC_RCC_F411_H_


#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "stdint.h"

#define F_CPU 		100000000UL		//Freq
#define TimerTick  	F_CPU/1000-1	//1kHz

#define TIMx_EnableIT(TIMx) TIMx->DIER |= TIM_DIER_UIE
#define TIMx_EnableCNT(TIMx) TIMx->CR1 |= TIM_CR1_CEN

void RCC_Init(void);
void Tim11_init(void);
void Systick_init(void);
void dMs(uint32_t times);

#endif /* INC_RCC_F411_H_ */
