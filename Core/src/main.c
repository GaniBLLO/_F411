/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <main.h>
#include "RCC_F411.h"
#include "SPI_master_F411.h"

#define Enable_RTOS	0

#if Enable_RTOS
    #include "FreeRTOS.h"
    #include "task.h"
    #include "queue.h"
#endif

void RCC_Init(void);
void Systick_init(void);
void GPIO_LCD_Init(void);
void Tim11_init(void);


int main(void)
{
	//*******************Init RCC & Systick
	RCC_Init();
	Systick_init();

	//*******************Init GPIOs
	GPIO_LCD_Init();
	Tim11_init();
//	GPIO_SD_Init();
//	GPIO_UART_Init();
//	GPIO_ETH_Init();

    /* Loop forever */
	for(;;);
}
