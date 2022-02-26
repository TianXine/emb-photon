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
#include "stm32f4xx_conf.h"
#include "led.h"

int main() {
  ledInit();
  ledBlink();
}
