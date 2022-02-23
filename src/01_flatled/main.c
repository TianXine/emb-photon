/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main
 *
 *        Version:  1.0
 *        Created:  02/20/2022 03:29:35 PM
 *       Revision:  none
 *
 *         Author:  xine (xine), xinedev@outlook.com
 *   Organization:  xinedev
 *
 * =====================================================================================
 */

#include "stm32f4xx.h"

typedef unsigned int u32;

void SystemInit() {}

static void delay(u32 i) {
  while (i--)
    ;
}

int main() {
  // Enable RCC for GPIOF
  RCC_AHB1ENR |= ( 0x01 << 5 | 0x01 << 6 );
  GPIOF_MODER = (1 << (2 * 9) | 1 << (2*10)); // set GPIOF to general output
  GPIOG_MODER = (1 << (2 * 9) | 1 << (2*10)); // set GPIOG to general output
  char keepRunning = 1;
  while (keepRunning) {
	// LED0
    GPIOF_BSRR = (1 << (16 + 9));
    delay(0xFFFFF);
    GPIOF_BSRR = (1 << 9);
    delay(0xFFFFF);

	// LED1
	GPIOG_BSRR = (1 << (16+10));
    delay(0xFFFFF);
    GPIOG_BSRR = (1 << 10);
    delay(0xFFFFF);
  }
  return 0;
}

/**
 * @brief reset handler
 * @note overwrite the Reset_Handler in assembly.
 * */
void Reset_Handler()
{
	SystemInit();
	main();
}
