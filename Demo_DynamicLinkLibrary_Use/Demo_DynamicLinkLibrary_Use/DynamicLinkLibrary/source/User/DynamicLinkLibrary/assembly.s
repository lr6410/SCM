            
DLL_VERSION EQU 0x00000008

                         
        AREA    FunctionArray, DATA, READONLY, ALIGN=0


Fun_Start

       ;IMPORT  |Image$$LR_IROM1$$Length| 
        IMPORT  |Image$$ER_IROM1$$Length| 
        IMPORT  |Image$$RW_IRAM1$$Length| 
        IMPORT  |Image$$ER_IROM2$$Length|            
            
        IMPORT  |Image$$ER_IROM1$$RO$$Base|
        IMPORT  |Image$$RW_IRAM1$$RO$$Base|  
        IMPORT  |Image$$ER_IROM2$$RO$$Base|    

        IMPORT  |Image$$ER_IROM1$$RO$$Limit|
        IMPORT  |Image$$RW_IRAM1$$RO$$Limit|  
        IMPORT  |Image$$ER_IROM2$$RO$$Limit|    
           
        ;IMPORT  DelayUs
        ;ENTRY  
        DCD     |Image$$ER_IROM1$$Length| + |Image$$RW_IRAM1$$Length| + |Image$$ER_IROM2$$Length|   
            ; - |Image$$ER_IROM1$$RO$$Base| ;0x000000C4              ;//动态库的长度
        DCD     DLL_VERSION  ;0x00000007  ;动态库版本 version   
            
        DCD     |Image$$ER_IROM1$$Length| ;  |Image$$ER_IROM2$$RO$$Limit| - |Image$$ER_IROM1$$RO$$Base|   ;   ;;;; |Image$$ER_IROM2$$RO$$Limit| - |Image$$ER_IROM1$$RO$$Base|;;|Image$$ER_IROM1$$RO$$Limit| ; |Image$$RW_IRAM1$$RO$$Base| ;- |Image$$ER_IROM1$$RO$$Base|  ;0x080040B4 - 0x08004000    ;// 静态变量的偏移地址
        DCB     "DelayUs" 
        ;DCB     "%"     ;注意要用%填充空缺，把下面的DCD指令顶到4倍地址处    如果是ARM Code，则用&来填充
        ;函数名结尾，且%表示是 Thumb Code，如果是&,也表示是函数名结尾，但&表示是ARM Code
        DCD     0x0800404C - 0x08004000 + 1   ;是Thumb Code的话，自己加1

        DCB     "RunHostFun"
        ;DCB     "%%"                  ;注意要用%填充空缺，把下面的DCD指令顶到4倍地址处   如果是ARM Code，则用&来填充
        DCD     0x08004064 - 0x08004000 + 1  ;是Thumb Code的话，自己加1
    
        DCB     "StaticVarInit" 
        ;DCB     "%%%"               ;注意要用%填充空缺，把下面的DCD指令顶到4倍地址处    如果是ARM Code，则用&来填充
        DCD     0x080040A4 - 0x08004000 + 1        ;是Thumb Code的话，自己加1
    
        END




