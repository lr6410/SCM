#include "gpio.h"

extern void LED_GPIO_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
#if (BARD_TYPE == HOME)    
	
	/* Enable the GPIO_LED Clock */
	RCC_AHB1PeriphClockCmd(  RCC_AHB1Periph_GPIOE, ENABLE); 		
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
#elif (BARD_TYPE == COMPANY)
	RCC_AHB1PeriphClockCmd(  RCC_AHB1Periph_GPIOA, ENABLE); 		
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);
    DelayMs(200);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);
    DelayMs(200);
    GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);
    DelayMs(200);
#else
#endif
}
