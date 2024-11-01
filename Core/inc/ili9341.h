/* vim: set ai et ts=4 sw=4: */
#ifndef __ILI9341_H__
#define __ILI9341_H__

//#include "stm32f4xx.h"
//#include "stm32f411xe.h"
#include "RCC_F411.h"
#include "fonts.h"
#include <stdbool.h>
#include "SPI_master_F411.h"

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

/*** Redefine if necessary ***/
//#define ILI9341_SPI_PORT hspi1
extern SPI_ ILI9341_SPI_PORT;

#define ILI9341_RES_On      GPIOA->BSRR |= GPIO_BSRR_BS12;
#define ILI9341_RES_OFF     GPIOA->BSRR |= GPIO_BSRR_BR12;

#define ILI9341_CS_On       GPIOB->BSRR |= GPIO_BSRR_BS6;
#define ILI9341_CS_OFF  	GPIOB->BSRR |= GPIO_BSRR_BR6;

#define ILI9341_DC_On      	GPIOB->BSRR |= GPIO_BSRR_BS2;
#define ILI9341_DC_Off  	GPIOB->BSRR |= GPIO_BSRR_BR2;

#define ILI9341_LED_On      GPIOA->BSRR |= GPIO_BSRR_BS9;
#define ILI9341_LED_Off  	GPIOA->BSRR |= GPIO_BSRR_BR9;

// default orientation
#define ILI9341_WIDTH  240
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR)

// rotate right
/*
#define ILI9341_WIDTH  320
#define ILI9341_HEIGHT 240
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)
*/

// rotate left
/*
#define ILI9341_WIDTH  320
#define ILI9341_HEIGHT 240
#define ILI9341_ROTATION (ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)
*/

// upside down
/*
#define ILI9341_WIDTH  240
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR)
*/

/****************************/

// Color definitions
#define	ILI9341_BLACK   0x0000
#define	ILI9341_BLUE    0x001F
#define	ILI9341_RED     0xF800
#define	ILI9341_GREEN   0x07E0
#define ILI9341_CYAN    0x07FF
#define ILI9341_MAGENTA 0xF81F
#define ILI9341_YELLOW  0xFFE0
#define ILI9341_WHITE   0xFFFF
#define ILI9341_COLOR565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

// call before initializing any SPI devices
void ILI9341_Unselect();

void GPIO_LCD_Init(void);
void ILI9341_Init(void);
void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_WriteString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor);
void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ILI9341_InvertColors(bool invert);

#endif // __ILI9341_H__
