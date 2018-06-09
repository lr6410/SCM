#ifndef _LED_H_
#define _LED_H_


#include "module_public.h"
#include "../unit/gpio.h"
#include "../service/DynamicLinkLibraryLoader.h"


//typedef unsigned int (*BFun)(unsigned int,unsigned char);



extern void LED_A_Control(void);
extern void LED_B_Control(unsigned int sw);
extern void LED_B_RunHostFun(void);

#endif /* _LED_H_ */
