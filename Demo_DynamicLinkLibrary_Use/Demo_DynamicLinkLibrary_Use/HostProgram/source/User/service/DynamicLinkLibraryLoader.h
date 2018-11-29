#ifndef _DYNAMICLINKLIBRARYLOADER_H_
#define _DYNAMICLINKLIBRARYLOADER_H_

#include "../../../../DynamicLinkLibrary/source/User/DynamicLinkLibrary/DynamicLinkLibrary.h"
#include "../../Support/stm32f4xx.h"


#define ADDR_DLL  0x08004000  // 如果有文件系统，就从文件系统获取地址。或者其他搜索方式获取地址，所以它是可以变化的，这里仅以宏的方式，固定地址。 


#define     SIZE_DLL_MEM    48
#define     SIZE_MEM_INT    SIZE_DLL_MEM / sizeof(unsigned int)


extern Fun DelayUs;
extern TFun RunHostFun;
extern void LED_B_Control(unsigned int sw);
extern void DynamicLoader(unsigned int AddrDynamicLinkLib);

#endif /* _DYNAMICLINKLIBRARYLOADER_H_ */
