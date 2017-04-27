/************************************************************/
OSTaskCreate，
函数功能：创建新任务，可在多任务环境启动之前，也可在正在运行的任务中创建任务
函数参数：task：指向任务代码的指针--函数指针；pdata：传递给任务的参数--变量指针；
          ptos：指向任务堆栈栈顶的指针；prio：任务优先级
/************************************************************/
INT8U OSTaskCreat（void(*task)(void *pd),void *pdata,OS_STK *ptos,INT8U prio,）
/************************************************************/
OSTaskDel
函数功能：删除指定优先级的任务，被删除的任务将回到休眠状态，可使用OSTaskCreat重新创建
函数参数：prio：指定要删除任务的优先级
返回值：OS_NO_ERR:函数调用成功；0S_TASK_DEL_IDLE:错误，试图删除空闲任务
        OS_TASK_DEL_ERR:错误，指定要删除的任务不存在；OS_PRIO_INVALID:参数指定的优先级大于OS_LOWEST_PRIO
        OS_TASK_DEL_ISR:错误，试图在中断处理程序中删除任务
/************************************************************/
INT8U OSTaskDel（INT8U pio）
