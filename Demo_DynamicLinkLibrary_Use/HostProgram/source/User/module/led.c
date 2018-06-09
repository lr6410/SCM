#include "led.h"


extern unsigned int *DynamicStaticVar;

unsigned int back_fun(unsigned int i,unsigned char c);
//static BFun fun = (BFun)back_fun;

unsigned int MW = 0;// 被dll直接访问


extern void LED_A_Control(void)
{    
    static unsigned int i = 0 ,j = 0;
#if     (BARD_TYPE == HOME)    

#elif   (BARD_TYPE == COMPANY)

    if( 10000 == (*DynamicStaticVar)){
        (*DynamicStaticVar) = 0;
         i = 0; j = 0;
    }else{
        (*DynamicStaticVar) ++;
        j ++;
        if(j<=800){
            i = j;
        }else if(j < 1600){
            i = 1600 - j;
        }else{
            j = 0;i = 0;
        }
    }        
    GPIO_SetBits(GPIOA,GPIO_Pin_6);
    DelayUs(i);    
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    DelayUs(800 - i); 

#else  
#endif
}

extern void LED_B_RunHostFun(void)
{
    static unsigned int i = 0;
    
    if(0x500 == i ){
        i = 0;
        RunHostFun();
    }else{
        i ++;
    }
}


extern void LED_B_Control(unsigned int sw)
{    
#if     (BARD_TYPE == HOME)  
#elif   (BARD_TYPE == COMPANY)
        
    if(sw){
        GPIO_SetBits(GPIOA,GPIO_Pin_7);
    }else{  
        GPIO_ResetBits(GPIOA,GPIO_Pin_7);
    }

#else  
#endif
}


//unsigned int back_fun(unsigned int i,unsigned char c)   
//{
//    static unsigned int a = 0;
//    
//    a ++;
//    MW = MW;
//    if(50 == a){
//        *SW = 1;
//    }
//    return a;
//}

