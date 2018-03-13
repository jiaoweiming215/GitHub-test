/************************************************************************************************************
使用pendsvc异常，在异常函数中，将R4~R11寄存器保存到缓冲区，再恢复R4~R11寄存器，模拟任务切换时的寄存器的保存与恢复
************************************************************************************************************/

#define NVIC_INT_CTRL 0xE000ED04
#define NVIC_PENDSVSET 0x10000000
#define NVIC_SYSPRI2 0xE000ED22
#define NVIC_PENDSV_PRI 0x000000FF

#define MEM32(addr)  *(volatile unsigned long *)(addr)
#define MEM8(addr)  *(volatile unsigned char *)(addr)

void triggerPendSVC()
{
    MEM8(NVIC_SYSPRI2) = NVIC_PENDSV_PRI;//设置中断优先级为最低
    MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;//
    
}
typedef struct _BlockType_c
{
    unsigned long * stackPtr;
}BLOCKTYPE_T;

BLOCKTYPE_T * blockPtr;
void dly(int iCnt)
{
    while(--iCnt > 0);
}

int iFlg;
unsigned long stackBuffer[1024];
BLOCKTYPE_T block;
int main()
{
    block.stackPtr = &stackBuffer[1024];
    blockPtr = &block;
   for(;;)
   {
       iFlg = 0;
       dly(100);
       iFlg = 1;
       dly(100);
       
       triggerPendSVC();
   }
   
}
