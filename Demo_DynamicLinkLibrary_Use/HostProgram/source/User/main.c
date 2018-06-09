#include "main.h"



int main(void)
{
	LED_GPIO_Init();
    
    DynamicLoader(ADDR_DLL);
	while(1){
        LED_A_Control();
        LED_B_RunHostFun();
	}
}
