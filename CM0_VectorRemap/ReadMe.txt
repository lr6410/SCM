CM0的中断向量表重映射机制实现的技术原理：

CM0核没有VTOR寄存器，也就是说，CM0不支持中断向量表重映射的CPU直接的特性支持，但要想实现中断向量重映射并不是不能做到。
在系统默认的中断向量表区域，也即是flash的起始地址处，写入特定地址，特定地址指向RAM区。在这个区域建立新的中断向量表。
但它与系统默认的中断向量表不同的是，它需要跳转指令配合。跳转指令结合地址池，跳转范围可以覆盖32位的地址空间。
将中断的ISR地址写入新的地址池，就可以完成重映射。

举例来说：
源码的功能是，两个key，对应两个led。按对应的key，对应的led亮起。其中，使用GPIO中断，来识别key动作，在ISR中点亮led。
这里就单独实现了PIOINT0_IRQHandler的中断重定向，其他中断，或者系统异常、SVC、PendSV都可参考同样的方法来实现。



实现步骤：
第1步.
在启动代码中，系统默认的中断向量表段中找到PIOINT1_IRQHandler，它是16+30的下标项。
将DCD PIOINT1_IRQHandler 中PIOINT1_IRQHandler 替换成(0x10000000 + (16+30)*4+1)，计算出也就是0x100000B9。

0x10000000是ARM给CM0定的RAM起始地址。因为每一项占的长度是4B，所以这里要乘4，加1是因为Thumb指令，给到PC时，最低位要是1。

第2步.
在启动代码中添加一个段，可以直接拷贝AREA    RESET, DATA, READONLY这个段，粘贴到上面，修改段名为Vector_RAM，DATA属性改为CODE。
为避免标签重定义，将__Vectors修改为__Vectors_RAM。

然后找到DCD     PIOINT1_IRQHandler  项，改为
	LDR 	R0,PIOINT1_IRQHandler_RAM	;DCD     (0x20000000 + (16+30)*4+1);PIOINT1_IRQHandler        ; 16+30: PIO INT1
	BX		R0;MOV 	PC,R0 - OK

并在DCD列表的下面加上  PIOINT1_IRQHandler_RAM				DCD		PIOINT1_IRQHandler
建立地址池。注意不要在这个段的上面加，也不要在DCD列表的中间加！而在DCD列表的下面加。

ARMv6-M中的LDR Rn，#Lable，是两字节的指令，而ARMv7-M中这样的指令是四字节。
此外，ARMv6-M中，这条指令，Rn只能是R0-R7，而ARMv7-M，似乎没有这样的限制。
所以这里不能用PC做Rn，所以还需要BX R0，让CPU跳转到ISR处。MOV PC,R0也可以。
ARMv7-M，就可以用LDR PC，#DCD_ISR,完成跳转。

这里必须用8字节长度完成跳转，毕竟光地址就要占4字节。其实系统发生中断时，LDR R0，#DCD_ISR 和 BX R0，可以不大准确的理解是CPU
隐式的执行了，所以不需要显式的写出，只需要DCD #ISR。所以它在只需要4字节就可以完成。

第3步.
使用分散加载文件，要求编译器把Vector_RAM的加载域定在RAM起始处。在sct文件中，RW中加入一行startup_LPC11xx.o (Vector_RAM,+First)，即可。

之后，在C/C++源码中，不需要做任何改动和支持。



如果不需要将前中断向量表中的前16项做重映射，可以将之从汇编段中删除掉，但同时，在__Vectors中，对应的ISR全部要同步新地址。
将(0x10000000 + (16+30)*4+1);中的16+去掉即可，这样可以节省一些空间。当然，也可以不用这么规整的映射到那些地方。只要知道这个流程是怎么实现的，
也可按自己定的地址来跳转，也可以省掉一些不用的中断RAM。

以上仅仅提供了思路，和一种实现方法。




