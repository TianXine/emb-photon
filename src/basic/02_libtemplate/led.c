/*
 * =====================================================================================
 *
 *       Filename:  led.c
 *
 *    Description:  LED blink
 *
 *        Version:  1.0
 *        Created:  2022/2/26 10:14:03
 *       Revision:  none
 *
 *         Author:  xine (xine), xinedev@outlook.com
 *   Organization:  xinedev
 *
 * =====================================================================================
 */

#include "led.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

void delay(uint32_t tiks)
{
    while (tiks--) {
    }
}

void ledInit()
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
}

void ledBlink()
{
    while (1) {
        GPIO_ResetBits(GPIOF, GPIO_Pin_9);
        delay(0x0ffffff);
        GPIO_SetBits(GPIOF, GPIO_Pin_9);
        delay(0x0ffffff);

        GPIO_ResetBits(GPIOF, GPIO_Pin_10);
        delay(0x0ffffff);
        GPIO_SetBits(GPIOF, GPIO_Pin_10);
        delay(0x0ffffff);
    }
}
