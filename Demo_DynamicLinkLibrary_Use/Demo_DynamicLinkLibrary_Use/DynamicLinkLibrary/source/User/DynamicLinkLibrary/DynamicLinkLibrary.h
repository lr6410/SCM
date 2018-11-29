#ifndef _DYNAMIC_LINK_LIBRARY_H_
#define _DYNAMIC_LINK_LIBRARY_H_


typedef void (*Fun)(unsigned int);
typedef unsigned int (*TFun)(void);
typedef void (*NFun)(unsigned int addr,unsigned int **v_addr,unsigned int *s_addr);


//extern unsigned int DynamicStaticVar;
//extern void DelayUs(unsigned int k);

//extern void StaticVarInit(unsigned int addr,unsigned int **v_addr,unsigned int *s_addr);


#endif /* _DYNAMIC_LINK_LIBRARY_H_ */


