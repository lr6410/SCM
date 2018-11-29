#include "DynamicLinkLibrary.h"

extern unsigned int DynamicStaticVar = 0x00000007;



static unsigned int *HostStaticVar = 0;
Fun fun = (Fun)0;

extern void DelayUs(unsigned int t)
{
    unsigned int i,j;

    for(i = 0 ; i < t; i ++){
        for(j = 0 ; j < 0x3; j++){
        }
    }    
}

extern void StaticVarInit(unsigned int addr,unsigned int **v_addr,unsigned int *s_addr)
{
    fun = (Fun)addr;
    *v_addr = &DynamicStaticVar;
    HostStaticVar = s_addr;
} 

extern void RunHostFun(void)
{          
    if((*HostStaticVar)){
        fun(1);
        (*HostStaticVar)=0;
    }else{
        fun(0);
        (*HostStaticVar)=1;
    }    
}





