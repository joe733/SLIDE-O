#include "stm32f10x.h"

void delay(long);
void gpio_ports_enable(void);

void delay(long cycles)
{
  while(cycles >0)
  cycles--; // delay, it is not in milliseconds or microseconds, but rather in some 'wasted clock cycles'
}
 
void gpio_ports_enable(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |     RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPCEN; //ports A & B clock enabled
  GPIOC->CRH = 0x44344444; //Pin C13 enable. 
}
 
int main(void)
{
 gpio_ports_enable();
 
 for(;;)  //main loop - read "forever", or you may use 'while(1)'
 {
   GPIOC->BSRR = GPIO_BSRR_BS13; 
   delay(5000000);
   GPIOC->BSRR = GPIO_BSRR_BR13; 
   delay(5000000); 
 } 
 }
 
