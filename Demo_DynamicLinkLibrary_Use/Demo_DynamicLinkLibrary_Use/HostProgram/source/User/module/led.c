#include "led.h"


extern unsigned int *DynamicStaticVar;

extern void LED_A_Control(void)
{    
    static unsigned int i = 0 ,j = 0;
#if     (BARD_TYPE == HOME)    

#elif   (BARD_TYPE == COMPANY)

    //if( 0 == (*DynamicStaticVar)){
       // (*DynamicStaticVar) = 0;
       //  i = 0; j = 0;
    //}else{
        (*DynamicStaticVar) ++;
        j ++;
        if(j<=800){
            i = j;
        }else if(j < 1600){
            i = 1600 - j;
        }else{
            j = 0;i = 0;
        }
   // }        
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




