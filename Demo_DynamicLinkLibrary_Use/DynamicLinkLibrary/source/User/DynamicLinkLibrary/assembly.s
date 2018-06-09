                
                         
                AREA    FunctionArray, DATA, READONLY, ALIGN=0      
Fun_Start
  
            
        DCD     0x000000C4  ;Image$$ER_IROM1$$Base; len       ;&&&&&&&&&&&&&&&&&&&&&&   1
        DCD     0x00000007  ;version
        DCD     0x080040B4 - 0x08004000    
        DCB     "DelayUs"
        DCB     "%"     ;&&&&&&&&&&&&&&&&&&&&&&&&&& 3 ;函数名结尾，且%表示是 Thumb Code，如果是&,也表示是函数名结尾，但&表示是ARM Code
        DCD     0x0800403C - 0x08004000 + 1   ;&&&&&&&&&&&&&&&&&&&&&&&  2

        DCB     "RunHostFun"
        DCB     "%%"                  ;&&&&&&&&&&&&&&&&&&&&&&&&&& 3
        DCD     0x08004054 - 0x08004000 + 1  ;&&&&&&&&&&&&&&&&&&&&&&&&&      2  
    
        DCB     "StaticVarInit" 
        DCB     "%%%"               ;&&&&&&&&&&&&&&&&&&&&&&&&&& 3
        DCD     0x08004094 - 0x08004000 + 1        ;&&&&&&&&&&&&&&&&&&&&&&&&&& 2
    
    


        END




