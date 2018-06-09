/*******************************************************************************/
/*  文件名：nxplpc11xx.h                                                       */
/*  功能：  存储器映射（也就是给MCU的所有寄存器定义地址）                      */
/*  制作：  瑞生嵌入式（Ration Embedded）                                      */
/*  日期：  2011年1月9日                                                       */
/*  联系：  15234021671     richgood@163.com                                   */
/*    Cortex-M0 技术论坛：ration.5d6d.com                                      */
/*******************************************************************************/

#ifndef __NXPLPC11xx_H__
#define __NXPLPC11xx_H__

/*****************************************************************/
/*               类型重定义：方便阅读程序                        */
/*****************************************************************/
typedef   signed          char    int8;     //8位带符号数
typedef   signed short     int    int16;    //16位带符号数
typedef   signed           int    int32;    //32位带符号数
typedef   signed       __int64    int64;    //64位带符号数
typedef unsigned          char    uint8;    //8位无符号数
typedef unsigned short     int    uint16;   //16位无符号数
typedef unsigned           int    uint32;   //32位无符号数
typedef unsigned       __int64    uint64;   //64位无符号数

#define R_en   volatile uint32		     //32位只读寄存器
#define W_en   volatile uint32		     //32位只写寄存器
#define RW_en  volatile uint32		     //32位可读可写寄存器
/*————————————————————————————————————————————————————————————————*/

/*****************************************************************/
/*                         定义中断号                            */
/*****************************************************************/
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  	NonMaskableInt_IRQn           = -14,    /*!< 2 Non Maskable Interrupt                           */
  	HardFault_IRQn                = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                   */
  	SVCall_IRQn                   = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                     */
  	PendSV_IRQn                   = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                     */
  	SysTick_IRQn                  = -1,     /*!< 15 Cortex-M0 系统定时器中断号                */

/************************  LPC11xx 中断号  *******************************************************/
  	WAKEUP0_IRQn                  = 0,        /* PIO0_0引脚唤醒中断号      */
  	WAKEUP1_IRQn                  = 1,        /* PIO0_1引脚唤醒中断号      */
  	WAKEUP2_IRQn                  = 2,		  /* PIO0_2引脚唤醒中断号      */
  	WAKEUP3_IRQn                  = 3,		  /* PIO0_3引脚唤醒中断号      */
  	WAKEUP4_IRQn                  = 4,   	  /* PIO0_4引脚唤醒中断号      */
  	WAKEUP5_IRQn                  = 5,        /* PIO0_5引脚唤醒中断号      */
  	WAKEUP6_IRQn                  = 6,        /* PIO0_6引脚唤醒中断号      */
  	WAKEUP7_IRQn                  = 7,        /* PIO0_7引脚唤醒中断号      */
  	WAKEUP8_IRQn                  = 8,        /* PIO0_8引脚唤醒中断号      */
  	WAKEUP9_IRQn                  = 9,        /* PIO0_9引脚唤醒中断号      */
  	WAKEUP10_IRQn                 = 10,       /* PIO0_10引脚唤醒中断号     */
  	WAKEUP11_IRQn                 = 11,       /* PIO0_11引脚唤醒中断号     */
  	WAKEUP12_IRQn                 = 12,       /* PIO1_0引脚唤醒中断号      */
  	SSP1_IRQn                     = 14,       /* SSP1中断号                */
  	I2C_IRQn                      = 15,       /* I2C中断号                 */
  	TIMER_16_0_IRQn               = 16,       /* TIM16B0中断号             */
  	TIMER_16_1_IRQn               = 17,       /* TIM16B1中断号             */
  	TIMER_32_0_IRQn               = 18,       /* TIM32B0中断号             */
  	TIMER_32_1_IRQn               = 19,       /* TIM16B1中断号             */
  	SSP0_IRQn                     = 20,       /* SSP0中断号                */
  	UART_IRQn                     = 21,       /* UART中断号                */
  	ADC_IRQn                      = 24,       /* A/D转换器中断号           */
  	WDT_IRQn                      = 25,       /* 看门狗中断                */  
  	BOD_IRQn                      = 26,       /* BOD中断                   */
  	EINT3_IRQn                    = 28,       /* 外部中断3                 */
  	EINT2_IRQn                    = 29,       /* 外部中断2                 */
  	EINT1_IRQn                    = 30,       /* 外部中断1                 */
  	EINT0_IRQn                    = 31,       /* 外部中断0                 */
}IRQn_Type;

/*————————————————————————————————————————————————————————————————————————————————————————————*/

#if defined ( __CC_ARM   )	 
#pragma anon_unions
#endif

/******************************************************************************/
/*                    处理器外围寄存器地址定义结构体                          */
/******************************************************************************/

/*--------------------- 系统配置模块(SYSCON)基址 ：0x40048000 ----------------------*/
typedef struct
{
  	RW_en  SYSMEMREMAP;         /*“系统存储器重映射”寄存器，    地址偏移：0x000 (R/W) */
  	RW_en  PRESETCTRL;          /*    “外设复位控制”寄存器，    地址偏移: 0x004 (R/W) */
  	RW_en  SYSPLLCTRL;          /*    “系统倍频控制”寄存器，    地址偏移: 0x008 (R/W) */
  	RW_en  SYSPLLSTAT;          /*    “系统倍频状态”寄存器，    地址偏移: 0x00C (R)   */
    uint32 RESERVED0[4];		/*                  保留区，禁止在此操作              */
  	RW_en  SYSOSCCTRL;          /*  “系统振荡器控制”寄存器，    地址偏移: 0x020 (R/W) */
  	RW_en  WDTOSCCTRL;          /*“看门狗振荡器控制”寄存器，    地址偏移: 0x024 (R/W) */
  	RW_en  IRCCTRL;             /*“内部RC振荡器控制”寄存器，    地址偏移: 0x028 (R/W) */
    uint32 RESERVED1[1];		/*                  保留区，禁止在此操作              */
  	RW_en  SYSRESSTAT;          /*    “系统复位状态”寄存器，    地址偏移: 0x030 (R)   */
    uint32 RESERVED2[3];		/*                  保留区，禁止在此操作              */
  	RW_en  SYSPLLCLKSEL;        /*“系统倍频时钟来源选择”寄存器，地址偏移: 0x040 (R/W) */	
  	RW_en  SYSPLLCLKUEN;        /*“系统倍频时钟更新使能”寄存器，地址偏移: 0x044 (R/W) */
    uint32 RESERVED3[10];	    /*                  保留区，禁止在此操作              */
  	RW_en  MAINCLKSEL;          /*  “主时钟来源选择”寄存器，    地址偏移: 0x070 (R/W) */
  	RW_en  MAINCLKUEN;          /*  “主时钟更新使能”寄存器，    地址偏移: 0x074 (R/W) */
  	RW_en  SYSAHBCLKDIV;        /* “系统AHB时钟分频”寄存器，    地址偏移: 0x078 (R/W) */
    uint32 RESERVED4[1];		/*                  保留区，禁止在此操作              */
  	RW_en  SYSAHBCLKCTRL;       /* “系统AHB时钟控制”寄存器，    地址偏移: 0x080 (R/W) */
    uint32 RESERVED5[4];		/*                  保留区，禁止在此操作              */
  	RW_en  SSP0CLKDIV;          /*    “SSP0时钟分频”寄存器，    地址偏移: 0x094 (R/W) */          
  	RW_en  UARTCLKDIV;          /*    “UART时钟分频”寄存器，    地址偏移: 0x098 (R/W) */
  	RW_en  SSP1CLKDIV;          /*    “SSP1时钟分频”寄存器，    地址偏移: 0x09C (R/W) */          
    uint32 RESERVED6[4];		/*                  保留区，禁止在此操作              */
  	RW_en  SYSTICKCLKDIV;       /*“系统滴答定时器分频”寄存器，  地址偏移: 0x0B0 (R/W) */          
    uint32 RESERVED7[7];		/*                  保留区，禁止在此操作              */
  	RW_en  WDTCLKSEL;           /*“看门狗时钟源选择”寄存器，    地址偏移: 0x0D0 (R/W) */
  	RW_en  WDTCLKUEN;           /*“看门狗时钟更新使能”寄存器，  地址偏移: 0x0D4 (R/W) */
  	RW_en  WDTCLKDIV;           /*“看门狗时钟分频”寄存器，      地址偏移: 0x0D8 (R/W) */
    uint32 RESERVED8[1];        /*                  保留区，禁止在此操作              */         
  	RW_en  CLKOUTCLKSEL;        /*“CLKOUT时钟源选择”寄存器，    地址偏移: 0x0E0 (R/W) */
  	RW_en  CLKOUTUEN;           /*“CLKOUT时钟更新使能”寄存器，  地址偏移: 0x0E4 (R/W) */
  	RW_en  CLKOUTDIV;           /*“CLKOUT时钟分频”寄存器，      地址偏移: 0x0E8 (R/W) */       
    uint32 RESERVED9[5];  	    /*                  保留区，禁止在此操作              */
  	RW_en  PIOPORCAP0;          /*“POR捕获PIO状态0”寄存器，     地址偏移: 0x100 (R)   */           
  	RW_en  PIOPORCAP1;          /*“POR捕获PIO状态1”寄存器，     地址偏移: 0x104 (R)   */   
    uint32 RESERVED10[18];	    /*                  保留区，禁止在此操作              */
  	RW_en  BODCTRL;             /*        “BOD控制”寄存器，     地址偏移：0x150 (R/W) */
    uint32 RESERVED11[1];	    /*                  保留区，禁止在此操作              */
  	RW_en  SYSTCKCAL;           /*“系统滴答定时器校准”寄存器，  地址偏移: 0x158 (R/W) */
    uint32 RESERVED12[41];      /*                  保留区，禁止在此操作              */       
  	RW_en  STARTAPRP0;          /*“唤醒逻辑边沿控制0”寄存器，   地址偏移: 0x200 (R/W) */     
  	RW_en  STARTERP0;           /*“唤醒逻辑信号使能0”寄存器，   地址偏移: 0x204 (R/W) */      
  	RW_en  STARTRSRP0CLR;       /*“唤醒逻辑复位0”寄存器，       地址偏移: 0x208 (W)   */
  	RW_en  STARTSRP0;           /*“唤醒逻辑状态0”寄存器，       地址偏移: 0x20C (R/W) */
    uint32 RESERVED14[8];	    /*                  保留区，禁止在此操作              */
  	RW_en  PDSLEEPCFG;          /*     “深度睡眠配置”寄存器，   地址偏移: 0x230 (R/W) */
  	RW_en  PDAWAKECFG;          /*         “唤醒配置”寄存器，   地址偏移: 0x234 (R/W) */        
  	RW_en  PDRUNCFG;            /*         “掉电配置”寄存器，   地址偏移: 0x238 (R/W) */
    uint32 RESERVED15[110];	    /*                  保留区，禁止在此操作              */
  	R_en   DEVICE_ID;           /*       “处理器编号”寄存器，   地址偏移: 0x3F4 (R)   */
}SYSCON_TypeDef;
/*------------------------------------------------------------------------------------*/


/*-------------------引脚配置模块 (IOCON)基址：0x40044000 --------------------------*/
typedef struct
{
  	RW_en PIO2_6;                 /*                       "PIO2_6"引脚，地址偏移: 0x000 (R/W) */
   	uint32 RESERVED0[1];		  /*保留区，禁止在此操作                                       */
  	RW_en PIO2_0;                 /*             "PIO2_0/DTR/SSEL1"引脚，地址偏移: 0x008 (R/W) */
  	RW_en RESET_PIO0_0;           /*                 "RESET/PIO0_0"引脚，地址偏移: 0x00C (R/W) */
  	RW_en PIO0_1;                 /*    "PIO0_1/CLKOUT/CT32B0_MAT2"引脚，地址偏移: 0x010 (R/W) */
  	RW_en PIO1_8;                 /*           "PIO1_8/CT16B1_CAP0"引脚，地址偏移: 0x014 (R/W) */
    uint32 RESERVED1[1];		  /*保留区，禁止在此操作                                       */
 	RW_en PIO0_2;                 /*     "PIO0_2/SSEL0/CT16B0_CAP0"引脚，地址偏移: 0x01C (R/W) */
  	RW_en PIO2_7;                 /*                       "PIO2_7"引脚，地址偏移: 0x020 (R/W) */
  	RW_en PIO2_8;                 /*                       "PIO2_8"引脚，地址偏移: 0x024 (R/W) */
  	RW_en PIO2_1;                 /*             "PIO2_1/nDSR/SCK1"引脚，地址偏移: 0x028 (R/W) */
  	RW_en PIO0_3;                 /*                       "PIO0_3"引脚，地址偏移: 0x02C (R/W) */
  	RW_en PIO0_4;                 /*                   "PIO0_4/SCL"引脚，地址偏移: 0x030 (R/W) */
  	RW_en PIO0_5;                 /*                   "PIO0_5/SDA"引脚，地址偏移: 0x034 (R/W) */
  	RW_en PIO1_9;                 /*           "PIO1_9/CT16B1_MAT0"引脚，地址偏移: 0x038 (R/W) */
  	RW_en PIO3_4;                 /*                       "PIO3_4"引脚，地址偏移: 0x03C (R/W) */
  	RW_en PIO2_4;                 /*                       "PIO2_4"引脚，地址偏移: 0x040 (R/W) */
  	RW_en PIO2_5;                 /*                       "PIO2_5"引脚，地址偏移: 0x044 (R/W) */
  	RW_en PIO3_5;                 /*                       "PIO3_5"引脚，地址偏移: 0x048 (R/W) */
  	RW_en PIO0_6;                 /*                  "PIO0_6/SCK0"引脚，地址偏移: 0x04C (R/W) */
  	RW_en PIO0_7;                 /*                  "PIO0_7/nCTS"引脚，地址偏移: 0x050 (R/W) */
  	RW_en PIO2_9;                 /*                       "PIO2_9"引脚，地址偏移: 0x054 (R/W) */
  	RW_en PIO2_10;                /*                      "PIO2_10"引脚，地址偏移: 0x058 (R/W) */
  	RW_en PIO2_2;                 /*             "PIO2_2/DCD/MISO1"引脚，地址偏移: 0x05C (R/W) */
  	RW_en PIO0_8;                 /*      "PIO0_8/MISO0/CT16B0_MAT0"引脚，地址偏移: 0x060 (R/W) */
  	RW_en PIO0_9;                 /*      "PIO0_9/MOSI0/CT16B0_MAT1"引脚，地址偏移: 0x064 (R/W) */
  	RW_en PIO0_10;                /*"SWCLK/PIO0_10/SCK0/CT16B0_MAT2"引脚，地址偏移: 0x068 (R/W) */
  	RW_en PIO1_10;                /*       "PIO1_10/AD6/CT16B1_MAT1"引脚，地址偏移: 0x06C (R/W) */
  	RW_en PIO2_11;                /*                  "PIO2_11/SCK0"引脚，地址偏移: 0x070 (R/W) */
  	RW_en PIO0_11;                /*   "TDI/PIO0_11/AD0/CT32B0_MAT3"引脚，地址偏移: 0x074 (R/W) */
  	RW_en PIO1_0;                 /*    "TMS/PIO1_0/AD1/CT32B1_CAP0"引脚，地址偏移: 0x078 (R/W) */
  	RW_en PIO1_1;                 /*    "TDO/PIO1_1/AD2/CT32B1_MAT0"引脚，地址偏移: 0x07C (R/W) */
  	RW_en PIO1_2;                 /*  "nTRST/PIO1_2/AD3/CT32B1_MAT1"引脚，地址偏移: 0x080 (R/W) */
  	RW_en PIO3_0;                 /*                   "PIO3_0/nDTR"引脚，地址偏移: 0x084 (R/W) */
  	RW_en PIO3_1;                 /*                   "PIO3_1/nDSR"引脚，地址偏移: 0x088 (R/W) */
  	RW_en PIO2_3;                 /*               "PIO2_3/RI/MOSI1"引脚，地址偏移: 0x08C (R/W) */
  	RW_en PIO1_3;                 /*  "SWDIO/PIO1_3/AD4/CT32B1_MAT2"引脚，地址偏移: 0x090 (R/W) */
  	RW_en PIO1_4;                 /*        "PIO1_4/AD5/CT32B1_MAT3"引脚，地址偏移: 0x094 (R/W) */
  	RW_en PIO1_11;                /*                   "PIO1_11/AD7"引脚，地址偏移: 0x098 (R/W) */
  	RW_en PIO3_2;                 /*                   "PIO3_2/nDCD"引脚，地址偏移: 0x09C (R/W) */
  	RW_en PIO1_5;                 /*       "PIO1_5/nRTS/CT32B0_CAP0"引脚，地址偏移: 0x0A0 (R/W) */
  	RW_en PIO1_6;                 /*        "PIO1_6/RXD/CT32B0_MAT0"引脚，地址偏移: 0x0A4 (R/W) */
  	RW_en PIO1_7;                 /*        "PIO1_7/TXD/CT32B0_MAT1"引脚，地址偏移: 0x0A8 (R/W) */
  	RW_en PIO3_3;                 /*                    "PIO3_3/nRI"引脚，地址偏移: 0x0AC (R/W) */
  	RW_en SCK_LOC;                /*             "SCK"引脚位置选择寄存器，地址偏移: 0x0B0 (R/W) */
  	RW_en DSR_LOC;                /*             "DSR"引脚位置选择寄存器，地址偏移: 0x0B4 (R/W) */
  	RW_en DCD_LOC;                /*             "DCD"引脚位置选择寄存器，地址偏移: 0x0B8 (R/W) */
  	RW_en RI_LOC;                 /*              "RI"引脚位置选择寄存器，地址偏移: 0x0BC (R/W) */
}IOCON_TypeDef;
/*----------------------------------------------------------------------------------------------*/


/*----------------------- 电源管理单元(PMU)基址：0x40038000 --------------------------*/
typedef struct
{
  	RW_en PCON;                   /*电源控制寄存器，地址偏移: 0x000 (R/W) */
  	RW_en GPREG0;                 /*通用寄存器0，   地址偏移: 0x004 (R/W) */
  	RW_en GPREG1;                 /*通用寄存器1，   地址偏移: 0x008 (R/W) */
  	RW_en GPREG2;                 /*通用寄存器2，   地址偏移: 0x00C (R/W) */
  	RW_en GPREG3;                 /*通用寄存器3，   地址偏移: 0x010 (R/W) */
  	RW_en GPREG4;                 /*通用寄存器4，   地址偏移: 0x014 (R/W) */
}PMU_TypeDef;
/*——————————————————————————————————————————————————————————————————————————————————————*/


/*------------------------- 通用输入输出口(GPIO) --------------------------*/
/*------------------------- GPIO0基址：0x50000000 -------------------------*/
/*------------------------- GPIO1基址：0x50010000 -------------------------*/
/*------------------------- GPIO2基址：0x50020000 -------------------------*/
/*------------------------- GPIO3基址：0x50030000 -------------------------*/
typedef struct
{
	union 
  	{
    	RW_en MASKED_ACCESS[4096];  
    	struct 
		{
         	uint32 RESERVED0[4095];
    		RW_en  DATA;          /*端口n数据寄存器，          地址偏移: 0x3FFC (R/W) */
    	};
  	};
    uint32 RESERVED1[4096];
  	RW_en DIR;                    /*端口n数据方向寄存器，      地址偏移: 0x8000 (R/W) */
  	RW_en IS;                     /*端口n中断感应寄存器，      地址偏移: 0x8004 (R/W) */
  	RW_en IBE;                    /*端口n双边沿触发寄存器，    地址偏移: 0x8008 (R/W) */
  	RW_en IEV;                    /*端口n中断事件寄存器，      地址偏移: 0x800C (R/W) */
  	RW_en IE;                     /*端口n中断屏蔽寄存器，      地址偏移: 0x8010 (R/W) */
  	RW_en RIS;                    /*端口n原始中断状态寄存器，  地址偏移: 0x8014 (R)   */
  	RW_en MIS;                    /*端口n被屏蔽中断状态寄存器，地址偏移: 0x8018 (R)   */
  	RW_en IC;                     /*端口n中断清除寄存器，      地址偏移: 0x801C (R/W) */
} GPIO_TypeDef;
/*———————————————————————————————————————————————————————————————————————————————————————————— */


/*------------------------------ 定时器模块 (TMR) ----------------------------*/
/*------------------------------ TIM16B0基址：0x4000C000 ---------------------*/
/*------------------------------ TIM16B1基址：0x40010000 ---------------------*/
/*------------------------------ TIM32B0基址；0x40014000 ---------------------*/
/*------------------------------ TIM32B1基址：0x40018000 ---------------------*/
typedef struct
{
  	RW_en  IR;                     /*中断寄存器，        地址偏移: 0x000 (R/W) */
  	RW_en  TCR;                    /*定时控制寄存器，    地址偏移: 0x004 (R/W) */
  	RW_en  TC;                     /*计数器寄存器，      地址偏移: 0x008 (R/W) */
  	RW_en  PR;                     /*预分频寄存器，      地址偏移: 0x00C (R/W) */
  	RW_en  PC;                     /*预分频计数器寄存器，地址偏移: 0x010 (R/W) */
	RW_en  MCR;                    /*匹配控制寄存器，    地址偏移: 0x014 (R/W) */
  	RW_en  MR0;                    /*匹配寄存器0，       地址偏移: 0x018 (R/W) */
  	RW_en  MR1;                    /*匹配寄存器1，       地址偏移: 0x01C (R/W) */
  	RW_en  MR2;                    /*匹配寄存器2，       地址偏移: 0x020 (R/W) */
  	RW_en  MR3;                    /*匹配寄存器3，       地址偏移: 0x024 (R/W) */
  	RW_en  CCR;                    /*捕获控制寄存器，    地址偏移: 0x028 (R/W) */
  	R_en   CR0;                    /*捕获寄存器0，       地址偏移: 0x02C (R)   */
    uint32 RESERVED1[3];		   /*           保留区，禁止在此操作           */
  	RW_en  EMR;                    /*外部匹配寄存器，    地址偏移: 0x03C (R/W) */
    uint32 RESERVED2[12];		   /*           保留区，禁止在此操作           */
  	RW_en  CTCR;                   /*计数控制寄存器，    地址偏移: 0x070 (R/W) */
  	RW_en  PWMC;                   /*PWM控制寄存器，     地址偏移: 0x074 (R/W) */
}TMR_TypeDef;
/*—————————————————————————————————————————————————————————————————————————————————————————————— */


/*-------------------- 通用异步收发器模块(UART) 基址：0x40008000 -------------*/
typedef struct
{
  	union 
	{
  		R_en   RBR;               /*接收缓冲寄存器，    地址偏移: 0x000 (R)   */
  		W_en   THR;               /*发送保持寄存器，    地址偏移: 0x000 (W)   */
  		RW_en  DLL;               /*除数锁存低位寄存器，地址偏移: 0x000 (R/W) */
  	};
  	union 
	{
  		RW_en  DLM;               /*除数锁存高位寄存器，地址偏移: 0x004 (R/W) */
  		RW_en  IER;               /*中断允许寄存器，    地址偏移: 0x004 (R/W) */
  	};
  	union 
	{
  		R_en  IIR;                /*中断状态寄存器，      地址偏移: 0x008 (R) */
 	 	W_en  FCR;                /*FIFO控制寄存器，    地址偏移: 0x008 (W) */
  	};
  	RW_en  LCR;                   /*数据格式控制寄存器，              地址偏移: 0x00C (R/W) */
  	RW_en  MCR;                   /*Medom控制寄存器，                 地址偏移: 0x010 (R/W) */
  	R_en   LSR;                   /*发送接收状态寄存器，              地址偏移: 0x014 (R)   */
  	R_en   MSR;                   /*Modem状态寄存器，                 地址偏移: 0x018 (R)   */
  	RW_en  SCR;                   /*暂存寄存器，                      地址偏移: 0x01C (R/W) */
  	RW_en  ACR;                   /*自动波特率控制寄存器，            地址偏移: 0x020 (R/W) */
    uint32 RESERVED0;			  /*                  保留区，禁止在此操作                  */
  	RW_en  FDR;                   /*分数分频寄存器，                  地址偏移: 0x028 (R/W) */
    uint32 RESERVED1;			  /*                  保留区，禁止在此操作                  */
  	RW_en  TER;                   /*发送允许寄存器，                  地址偏移: 0x030 (R/W) */
    uint32 RESERVED2[6];		  /*                  保留区，禁止在此操作                  */
  	RW_en  RS485CTRL;             /*RS-485/EIA-485控制寄存器，        地址偏移: 0x04C (R/W) */
  	RW_en  ADRMATCH;              /*RS-485/EIA-485地址匹配寄存器，    地址偏移: 0x050 (R/W) */
  	RW_en  RS485DLY;              /*RS-485/EIA-485方向控制延迟寄存器，地址偏移: 0x054 (R/W) */
  	R_en   FIFOLVL;               /*FIFO状态寄存器，                  地址偏移: 0x058 (R)   */
}UART_TypeDef;
/*—————————————————————————————————————————————————————————————————————————————————————————— */


/*--------------------------- 同步串行通信模块(SSP) ----------------------------*/
/*--------------------------- SSP0基址：0x40040000  ----------------------------*/
/*--------------------------- SSP1基址；0x40058000  （HVQFN33封装没有SSP1）-----*/
typedef struct
{
  	RW_en CR0;            /*SSP控制寄存器0，             地址偏移: 0x000 (R/W) */
  	RW_en CR1;            /*SSP控制寄存器1，             地址偏移: 0x004 (R/W) */
 	RW_en DR;             /*SSP数据寄存器，              地址偏移: 0x008 (R/W) */
  	R_en  SR;             /*SSP状态寄存器，              地址偏移：0x00C (R)   */
  	RW_en CPSR;           /*SSP时钟预分频寄存器，        地址偏移: 0x010 (R/W) */
  	RW_en IMSC;           /*SSP中断屏蔽设置和清除寄存器，地址偏移: 0x014 (R/W) */
  	RW_en RIS;            /*SSP原始中断状态寄存器，      地址偏移: 0x018 (R/W) */
  	RW_en MIS;            /*SSP中断屏蔽状态寄存器，      地址偏移: 0x01C (R/W) */
  	RW_en ICR;            /*SSP中断清除寄存器，          地址偏移: 0x020 (R/W) */
}SSP_TypeDef;
/*————————————————————————————————————————————————————————————————————————————————————*/


/*------------- I2C通信模块寄存器(I2C) 基址：0x40000000-------------------------------*/
typedef struct
{
  	RW_en CONSET;            /*I2C控制设置寄存器，     地址偏移: 0x000 (R/W) */
  	R_en  STAT;              /*I2C状态寄存器，         地址偏移: 0x004 (R)   */
  	RW_en DAT;               /*I2C数据寄存器，         地址偏移: 0x008 (R/W) */
  	RW_en ADR0;              /*I2C从机地址0寄存器，    地址偏移: 0x00C (R/W) */
  	RW_en SCLH;              /*I2C时钟高电平值寄存器， 地址偏移: 0x010 (R/W) */
  	RW_en SCLL;              /*I2C时钟低电平值寄存器， 地址偏移: 0x014 (R/W) */
  	W_en  CONCLR;            /*I2C控制清除寄存器，     地址偏移: 0x018 (W)   */
  	RW_en MMCTRL;            /*I2C监测模式控制寄存器， 地址偏移: 0x01C (R/W) */
  	RW_en ADR1;              /*I2C从机地址1寄存器，    地址偏移: 0x020 (R/W) */
  	RW_en ADR2;              /*I2C从机地址1寄存器，    地址偏移: 0x024 (R/W) */
  	RW_en ADR3;              /*I2C从机地址1寄存器，    地址偏移: 0x028 (R/W) */
  	R_en  DATA_BUFFER;       /*I2C数据缓冲寄存器，     地址偏移: 0x02C ( /W) */
  	RW_en MASK0;             /*I2C从机地址屏蔽寄存器0，地址偏移: 0x030 (R/W) */
  	RW_en MASK1;             /*I2C从机地址屏蔽寄存器1，地址偏移: 0x034 (R/W) */
  	RW_en MASK2;             /*I2C从机地址屏蔽寄存器2，地址偏移: 0x038 (R/W) */
  	RW_en MASK3;             /*I2C从机地址屏蔽寄存器3，地址偏移: 0x03C (R/W) */
}I2C_TypeDef;
/*—————————————————————————————————————————————————————————————————————————————————————————*/


/*------------------- 看门狗定时器(WDT)基址：0x40004000 -----------------------*/
typedef struct
{
  	RW_en MOD;              /*看门狗模式寄存器，  地址偏移: 0x000 (R/W) */
  	RW_en TC;               /*看门狗常量寄存器，  地址偏移: 0x004 (R/W) */
  	W_en  FEED;             /*看门狗喂狗寄存器，  地址偏移: 0x008 (W)   */
  	R_en  TV;               /*看门狗当前值寄存器，地址偏移: 0x00C (R/ ) */
}WDT_TypeDef;
/*————————————————————————————————————————————————————————————————————————————*/




/*----------------------  模数转换器(ADC)基址：0x4001C000 ---------------------*/
typedef struct
{
  	RW_en  CR;              /*AD控制寄存器，       地址偏移: 0x000       (R/W) */
  	RW_en  GDR;             /*AD全局数据寄存器，   地址偏移: 0x004       (R/W) */
    uint32 RESERVED0;		/*             保留位，不要在此操作                */
  	RW_en  INTEN;           /*AD中断使能寄存器，   地址偏移: 0x00C       (R/W) */
  	RW_en  DR[8];           /*AD通道0~7数据寄存器，地址偏移: 0x010-0x02C (R/W) */
  	R_en   STAT;            /*AD状态寄存器，       地址偏移: 0x030         (R) */
}ADC_TypeDef;
/*—————————————————————————————————————————————————————————————————————————————*/



/*--------------------中断控制模块 (NVIC)基址：0xE000E100 --------------------- */
/*------------------- Cortex-M0私有外设 --------------------------------------*/
typedef struct
{
  	RW_en  ISER[1];                      /*中断设置使能寄存器，地址偏移；0x000 （R/W）*/
  	uint32 RESERVED0[31];
  	RW_en  ICER[1];                      /*中断清除使能寄存器，地址偏移：0x080 （R/W）*/
  	uint32 RSERVED1[31];
  	RW_en  ISPR[1];                      /*中断设置挂起寄存器，地址偏移：0x100 （R/W）*/
  	uint32 RESERVED2[31];
  	RW_en  ICPR[1];                      /*中断清除挂起寄存器，地址偏移：0x180 （R/W）*/
  	uint32 RESERVED3[31];
  	uint32 RESERVED4[64];
  	RW_en  IPR[8];                       /*中断优先级寄存器，  地址偏移：0x300~0x31C（R/W）*/
}NVIC_Type;


/*------------------- 系统控制模块（SCB）基址：0xE000ED00-------------------- */
/*------------------- Cortex-M0私有外设 --------------------------------------*/
typedef struct
{
  	R_en   CPUID;                        /*!< CPU ID Base Register                                     */
  	RW_en  ICSR;                         /*!< Interrupt Control State Register                         */
  	uint32 RESERVED0;
  	RW_en  AIRCR;                        /*!< Application Interrupt / Reset Control Register           */
  	RW_en  SCR;                          /*!< System Control Register                                  */
  	RW_en  CCR;                          /*!< Configuration Control Register                           */
  	uint32 RESERVED1;
  	RW_en  SHP[2];                       /*!< System Handlers Priority Registers. [0] is RESERVED      */
  	RW_en  SHCSR;                        /*!< System Handler Control and State Register                */
  	uint32 RESERVED2[2];
  	RW_en  DFSR;                         /*!< Debug Fault Status Register                              */
}SCB_Type;
/*————————————————————————————————————————————————————————————————————————————————————————*/

/*-----------------  系统滴答定时器模块(Systick)基址；E000E000  ---------------*/
/*------------------- Cortex-M0私有外设 --------------------------------------*/
typedef struct
{
	RW_en  STCTRL;		        /* 系统定时器控制和状态寄存器，地址偏移；0x010 (R/W)*/
	RW_en  STRELOAD;			/* 系统定时器重载寄存器，      地址偏移；0x014 (R/W)*/
	RW_en  STCURR;				/* 系统定时器当前计数值寄存器，地址偏移：0x018 (R/W)*/
	RW_en  STCALIB;				/* 系统定时器校准值寄存器，    地址偏移：0x01C (R/W)*/
}SYSTICK_TypeDef;
/*——————————————————————————————————————————————————————————————————————————————*/

/*------------------ 内核调试模块（DEBUG）基址：0xE000EDF0--------------------- */
/*------------------- Cortex-M0私有外设 --------------------------------------*/
typedef struct
{
  	RW_en DHCSR;                        /*!< Debug Halting Control and Status Register       */
  	W_en  DCRSR;                        /*!< Debug Core Register Selector Register           */
  	RW_en DCRDR;                        /*!< Debug Core Register Data Register               */
  	RW_en DEMCR;                        /*!< Debug Exception and Monitor Control Register    */
}DEBUG_Type;
/*————————————————————————————————————————————————————————————————————————————————————*/

/***************************************************/
/*          Cortex-M0私有外设基址定义              */
/***************************************************/
#define SCS_BASE          (0xE000E000UL)            //系统控制区域基址

#define DEBUG_BASE        (0xE000EDF0UL)            //DEBUG调试基址
#define SYSTICK_BASE      (SCS_BASE +  0x0010)      //系统滴答定时器基址
#define NVIC_BASE         (SCS_BASE +  0x0100)      //中断向量基址
#define SCB_BASE          (SCS_BASE +  0x0D00)      //系统控制模块基址

/****************************************************/
/*              LPC11xx外设基址定义                 */
/****************************************************/
/*----------   存储器映射基址  -------------- */
#define FLASH_BASE        (0x00000000UL)
#define RAM_BASE          (0x10000000UL)
#define APB0_BASE         (0x40000000UL)
#define AHB_BASE          (0x50000000UL)

/* -----------  APB0外设基址 -----------------*/
#define I2C_BASE          (APB0_BASE + 0x00000)
#define WDT_BASE          (APB0_BASE + 0x04000)
#define UART_BASE         (APB0_BASE + 0x08000)
#define CT16B0_BASE       (APB0_BASE + 0x0C000)
#define CT16B1_BASE       (APB0_BASE + 0x10000)
#define CT32B0_BASE       (APB0_BASE + 0x14000)
#define CT32B1_BASE       (APB0_BASE + 0x18000)
#define ADC_BASE          (APB0_BASE + 0x1C000)
#define PMU_BASE          (APB0_BASE + 0x38000)
#define SSP0_BASE         (APB0_BASE + 0x40000)
#define IOCON_BASE        (APB0_BASE + 0x44000)
#define SYSCON_BASE       (APB0_BASE + 0x48000)
#define SSP1_BASE         (APB0_BASE + 0x58000)

/* ------------- AHB外设基址  --------------- */	
#define GPIO_BASE         (AHB_BASE  + 0x00000)
#define GPIO0_BASE        (AHB_BASE  + 0x00000)
#define GPIO1_BASE        (AHB_BASE  + 0x10000)
#define GPIO2_BASE        (AHB_BASE  + 0x20000)
#define GPIO3_BASE        (AHB_BASE  + 0x30000)

/*******************************************************/
/*                    外设声明                         */
/*          (下面就是LPC1114的所有硬件资源)            */
/*******************************************************/
#define I2C         ((I2C_TypeDef    *) I2C_BASE   ) //I2C通信口
#define WDT         ((WDT_TypeDef    *) WDT_BASE   ) //看门狗
#define UART        ((UART_TypeDef   *) UART_BASE  ) //串口
#define TMR16B0     ((TMR_TypeDef    *) CT16B0_BASE) //16位定时器0
#define TMR16B1     ((TMR_TypeDef    *) CT16B1_BASE) //16位定时器1
#define TMR32B0     ((TMR_TypeDef    *) CT32B0_BASE) //32位定时器0
#define TMR32B1     ((TMR_TypeDef    *) CT32B1_BASE) //32位定时器1
#define ADC         ((ADC_TypeDef    *) ADC_BASE   ) //模数转换器
#define PMU         ((PMU_TypeDef    *) PMU_BASE   ) //功耗管理
#define SSP0        ((SSP_TypeDef    *) SSP0_BASE  ) //SPI通信口0
#define SSP1        ((SSP_TypeDef    *) SSP1_BASE  ) //SPI通信口1
#define IOCON       ((IOCON_TypeDef  *) IOCON_BASE ) //IO配置
#define SYSCON      ((SYSCON_TypeDef *) SYSCON_BASE) //系统配置
#define GPIO0       ((GPIO_TypeDef   *) GPIO0_BASE ) //P0口
#define GPIO1       ((GPIO_TypeDef   *) GPIO1_BASE ) //P1口
#define GPIO2       ((GPIO_TypeDef   *) GPIO2_BASE ) //P2口
#define GPIO3       ((GPIO_TypeDef   *) GPIO3_BASE ) //P3口

#define SYSTICK     ((SYSTICK_TypeDef*) SYSTICK_BASE)//系统滴答定时器 （M0私有外设）
#define SCB         ((SCB_Type       *) SCB_BASE    )//系统控制模块   （M0私有外设）
#define NVIC        ((NVIC_Type      *) NVIC_BASE   )//中断向量控制模块（M0私有外设）
#define DEBUG       ((DEBUG_Type     *) DEBUG_BASE  )//DEBUG调试模块   （M0私有外设）

/*————————————————————————————————————————————————————————————————————————————————————*/

/*************************************/
extern void SysCLK_config(void);
extern void CLKOUT_EN(uint8 CLKOUT_DIV);
extern void delay_ms(uint32 ms);
extern void delay_us(uint32 us);

static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  	NVIC->ISER[0] = (1 << ((uint32)(IRQn) & 0x1F)); 
}

static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  	NVIC->ICER[0] = (1 << ((uint32)(IRQn) & 0x1F)); 
}


#endif  /* __NXPLPC11xx_H__ */




