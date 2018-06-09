/******************************************************************/
/* 名称：按键控制LED实验(中断方式实现)                            */
/* 效果：按下按键1，LED1亮，释放按键，LED1灭                      */
/*       按下按键2，LED2亮，释放按键，LED2灭                      */
/* 硬件连接：P1.0---KEY1   P1.1---KEY2                            */
/*           P1.9---LED1   P1.10--LED2                            */
/* 作者：lintar      技美电子工作室                               */
/*                  （店址：lintar.taobao.com）                   */
/*                  （E-mail：lintar1368@126.com）                */
/* 联系方式：QQ:1049624740     旺旺：技美电子工作室               */
/******************************************************************/

#include "nxplpc11xx.h"

//GPIO1中断服务函数
void PIOINT1_IRQHandler(void)
{	
	if((GPIO1->MIS&0x001)==0x001)	   // 检测是不是P1.0引脚产生的中断
	{
		GPIO1->DATA &= ~(1<<9);				 // 开LED1
		while((GPIO1->DATA&(1<<0))!=(1<<0));	 // 等待按键释放
		GPIO1->DATA |= (1<<9);				 // 关LED1	
	}
	else if((GPIO1->MIS&0x002)==0x002) // 检测是不是P1.1引脚产生的中断
	{
		GPIO1->DATA &= ~(1<<10);			 // 开LED2
		while((GPIO1->DATA&(1<<1))!=(1<<1));	 // 等待按键释放
		GPIO1->DATA |= (1<<10);				 // 关LED2
	}
	GPIO1->IC = 0x3FF;  // 清除GPIO1上的中断
}


int main(void)
{	
	
	SysCLK_config(); // 时钟配置
	
	SYSCON->SYSAHBCLKCTRL |= (1<<16); // 使能IOCON时钟(bit16)
	IOCON->PIO1_0 = 0XD1; //把PIN33设置为P1.0脚
	IOCON->PIO1_1 = 0XD1; //把PIN34设置为P1.1脚
	SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // 禁能IOCON时钟(bit16)

	//把P1.0和P1.1设置为输入
	GPIO1->DIR &= ~(1<<0);
	GPIO1->DIR &= ~(1<<1);
	//把P1.9和P1.10引脚设置为输出
	GPIO1->DIR |= (1<<9);
	GPIO1->DIR |= (1<<10);
	//关LED1  LED2
 	GPIO1->DATA |= (1<<9);
	GPIO1->DATA |= (1<<10); 
	
	GPIO1->IS &= ~(1<<0); //选择P1.0为边沿触发
	GPIO1->IEV &= ~(1<<0);//选择P1.0为下降沿触发 
	GPIO1->IE |= (1<<0);  //设置P1.0中断不被屏蔽

	GPIO1->IS &= ~(1<<1); //选择P1.1为边沿触发
	GPIO1->IEV &= ~(1<<1);//选择P1.1为下降沿触发
	GPIO1->IE |= (1<<1);  //设置P1.1中断不被屏蔽
	NVIC_EnableIRQ(EINT1_IRQn);	// 使能GPIO1中断
	
	while(1)
	{
		;
	}
}

