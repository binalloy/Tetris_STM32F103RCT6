#include "millis.h"

volatile uint32_t time_ms = 0;

void SysTick_Configuration(uint32_t us)
{
  /* Setup SysTick Timer for 1 msec interrupts  */
  if(SysTick_Config(SystemCoreClock / 1000000 * us))  //SysTick配置函数
  {
    /* Capture error */
    while (1);
  }
  /* Configure the SysTick handler priority */
  //   NVIC_SetPriority(SysTick_IRQn, 0x0);                       //SysTick中断优先级设置
}

void SysTick_Handler(void)
{
   time_ms++;
}

uint32_t millis(void){
  return time_ms;
}

uint32_t macro(void){
  return (SysTick->LOAD - SysTick->VAL)/(SystemCoreClock/1000000);
}

void millis_init(void){
  SysTick_Configuration(1000);
}
