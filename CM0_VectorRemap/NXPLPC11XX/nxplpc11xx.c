#include "nxplpc11xx.h"

/***********************************************/
/*  函数功能：配置系统时钟                     */
/*  说明：    选择外部12M晶振作为系统时钟，并通*/
/*            过倍频器（PLL）把时钟倍频4倍     */
/*  注意：    使用其它值晶振时修改倍频值，最后 */
/*            时钟要满足<=50MHz                */
/***********************************************/
void SysCLK_config(void)
{
	uint8 i;
	/*执行以下代码选择外部12M晶振作为时钟源*/
	SYSCON->PDRUNCFG     &= ~(1 << 5);          //系统振荡器上电   
  	SYSCON->SYSOSCCTRL    = 0x00000000;			//振荡器未被旁路，1~20Mhz频率输入
  	for (i = 0; i < 200; i++) __nop();		    //等待振荡器稳定
 	SYSCON->SYSPLLCLKSEL  = 0x00000001;         //PLL时钟源选择“系统振荡器”
  	SYSCON->SYSPLLCLKUEN  = 0x01;               //更新PLL选择时钟源
  	SYSCON->SYSPLLCLKUEN  = 0x00;               //先写0，再写1达到更新时钟源的目的（数据手册规定）
  	SYSCON->SYSPLLCLKUEN  = 0x01;
  	while (!(SYSCON->SYSPLLCLKUEN & 0x01));     //确定时钟源更新后向下执行
	/*执行以下代码倍频为48MHz*/
	SYSCON->SYSPLLCTRL    = 0x00000023;     	//设置M=4;P=2; FCLKOUT=12*4=48Mhz
  	SYSCON->PDRUNCFG     &= ~(1 << 7);          //PLL上电
  	while (!(SYSCON->SYSPLLSTAT & 0x01));	    //确定PLL锁定以后向下执行
	/*主时钟源选择倍频以后的时钟*/
	SYSCON->MAINCLKSEL    = 0x00000003;			//主时钟源选择PLL后的时钟
	SYSCON->MAINCLKUEN    = 0x01;				//更新主时钟源
	SYSCON->MAINCLKUEN    = 0x00;				//先写0，再写1达到更新时钟源的目的（数据手册规定）
	SYSCON->MAINCLKUEN    = 0x01;
	while (!(SYSCON->MAINCLKUEN & 0x01));	    //确定主时钟锁定以后向下执行
	SYSCON->SYSAHBCLKDIV  = 0x01;				//AHB时钟分频值为1，使AHB时钟设置为48Mhz
	SYSCON->SYSAHBCLKCTRL |= (1<<6);            //使能GPIO时钟（用单片机好像没有不用GPIO的时候）
}



/***********************************************/
/*  函数功能：使能CLKOUT脚输出频率             */
/*  入口参数：CLKOUT_DIV,即CLKOUT分频值，1~255 */
/*  说明：    此函数可用来测试时钟真实性       */
/***********************************************/
void CLKOUT_EN(uint8 CLKOUT_DIV)
{
	SYSCON->SYSAHBCLKCTRL |= (1<<16);          // 使能IOCON时钟 
	IOCON->PIO0_1=0XD1;						   // 把P0.1脚设置为CLKOUT引脚
	SYSCON->SYSAHBCLKCTRL &= ~(1<<16);          // 禁能IOCON时钟
	SYSCON->CLKOUTDIV   = CLKOUT_DIV;			//CLKOUT时钟值为48/CLKOUT_DIV
	SYSCON->CLKOUTCLKSEL= 0X00000003;	  		//CLKOUT时钟源选择为主时钟
	SYSCON->CLKOUTUEN   =0X01;
	SYSCON->CLKOUTUEN   =0X00;
	SYSCON->CLKOUTUEN   =0X01;
	while (!(SYSCON->CLKOUTUEN & 0x01));        //确定时钟源更新后向下执行
}

/**********************************************/
/*  函数功能：SysTick延时                     */
/*  入口参数：毫秒值或微秒值                  */
/*  说明：    利用系统定时器实现              */
/*            48Mhz时钟工作下                 */
/**********************************************/
static volatile uint32 TimeTick = 0;
		  
void SysTick_Handler(void)					  //系统定时器中断服务函数
{
	TimeTick++;
}

void delay_ms(uint32 ms) /* 注意：这里的参数最大取699，否则会超出24位计数器值 */
{
	SYSTICK->STRELOAD =	(((24000)*ms)-1);	  //往重载计数器里写值
	SYSTICK->STCURR   =	 0;					  //计数器清零
	SYSTICK->STCTRL  |=  ((1<<1)|(1<<0));     //开启计数器,开启计数器中断
	while(!TimeTick);
	TimeTick = 0;
	SYSTICK->STCTRL =0;	
}

void delay_us(uint32 us)
{
	SYSTICK->STRELOAD =	(((24)*us)-1);	  //往重载计数器里写值
	SYSTICK->STCURR   =	 0;					  //计数器清零
	SYSTICK->STCTRL  |=  ((1<<1)|(1<<0));     //开启计数器,开启计数器中断
	while(!TimeTick);
	TimeTick = 0;
	SYSTICK->STCTRL =0;	
}


