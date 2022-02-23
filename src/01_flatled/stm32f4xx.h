/*
 * =====================================================================================
 *
 *       Filename:  stm32f4xx.h
 *
 *    Description:  stm32f4xx specific data
 *
 *        Version:  1.0
 *        Created:  02/20/2022 03:30:53 PM
 *       Revision:  none
 *
 *         Author:  xine (xine), xinedev@outlook.com
 *   Organization:  xinedev
 *
 * =====================================================================================
 */
#ifndef STM32F4XX_H_
#define STM32F4XX_H_

#define PERIPH_BASE     ((unsigned int)0x40000000)

/* bus base address */
#define APB1PERIPH_BASE  PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000)

/* GPIO address */
#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x1C00)

/* GPIO F buffers */
#define GPIOF_MODER *(unsigned int *)(GPIOF_BASE+0x00)
#define GPIOF_OTYPER *(unsigned int *)(GPIOF_BASE+0x04)
#define GPIOF_OSPEEDR *(unsigned int *)(GPIOF_BASE+0x08)
#define GPIOF_PUPDR *(unsigned int *)(GPIOF_BASE+0x0C)
#define GPIOF_IDR *(unsigned int *)(GPIOF_BASE+0x10)
#define GPIOF_ODR *(unsigned int *)(GPIOF_BASE+0x14)
#define GPIOF_BSRR *(unsigned int *)(GPIOF_BASE+0x18)
#define GPIOF_LCKR *(unsigned int *)(GPIOF_BASE+0x1C)
#define GPIOF_AFRL *(unsigned int *)(GPIOF_BASE+0x20)
#define GPIOF_AFRH *(unsigned int *)(GPIOF_BASE+0x24)

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800)
#define RCC_AHB1ENR *(unsigned int *)(RCC_BASE + 0x30)


extern void SystemInit(void);

#endif /* end of STM32F4XX_H_ */

