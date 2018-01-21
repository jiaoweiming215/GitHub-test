/*****************************************************************************
* File       : queue.c
* Function   : Provide queue function
* Description: To be done.           
* Version    : V0.20
* Author     : JOE
* Date       : 17th Jan 2018
* History    :  No.  When           Who           What
*               1    20/Jan/2018     JOE           Create

 ******************************************************************************/
#include "queue.h"

/********************************************************
* Name       : int InitQueue(T_QUEUE *ptQueue)
* Function   :init the queue
* Input      : T_QUEUE *ptQueue :the point of queue struct 

* Output:    : 
* Return     : TRUE:queue init sucess
                   FALSE:queue init failed
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int InitQueue(T_QUEUE *ptQueue)
{
    ptQueue->piBase = (T_QUEUE *)malloc(LENGTH);
    if(NULL == ptQueue->piBase)
    {
        print("NO MEMORY!\n");
        return FALSE;
    }
    ptQueue->front = NULL;
    ptQueue->rear= NULL;
    return TRUE;
}
/********************************************************
* Name       :void FreeQueue(T_QUEUE *ptQueue)
* Function   :free the queue
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
void FreeQueue(T_QUEUE *ptQueue)
{
    if(ptQueue->piBase)
    {
        free(ptQueue->piBase);
    }
    ptQueue->piBase = NULL;
    ptQueue->front = NULL;
    ptQueue->rear = NULL;
    return ;
}
/********************************************************
* Name       :int inQueue(T_QUEUE *ptQueue,int iValue)
* Function   :insert data to the queue
* Input      : T_QUEUE *ptQueue :the point of queue struct
                  int iValue:the data of insert the queue
* Output:    : NULL
* Return     : TRUE:Sucess operation
                    FALSE:Failed operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int inQueue(T_QUEUE *ptQueue,int iValue)
{
    int iIndex;
    iIndex = isFullQueue(ptQueue);
    if(FALSE== iIndex)
    {   
        ptQueue->piBase[ptQueue->rear] = iValue;  
        ptQueue->rear = (ptQueue->rear+1) % MAXQSIZE;  
        return TRUE; 
    }
    else
    {
        return FALSE;
    }
}
/********************************************************
* Name       : int outQueue(T_QUEUE *ptQueue,int *iValue)
* Function   : output the data from queue
* Input      : T_QUEUE *ptQueue :the point of queue struct
                  int *iValue:the point of the data for get out
* Output:    : NULL
* Return     : TRUE:Sucess operation
                    FALSE:Failed operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int outQueue(T_QUEUE *ptQueue,int *iValue)
{
    int iIndex;
    iIndex = isEmptyQueue(ptQueue);
    if(TRUE == iIndex)
    {
        return FALSE;
    }
    else
    {
        *iValue = ptQueue->piBase[ptQueue->front];
        ptQueue->front = (ptQueue->front+1)%MAXQSIZE;
        return TRUE;
    }
}

/********************************************************
* Name       :bool isEmptyQueue(T_QUEUE *ptQueue)
* Function   :judge the queue is empty or not
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : TRUE:Sucess operation
                    FALSE:Failed operation
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isEmptyQueue(T_QUEUE *ptQueue)
{
    if(ptQueue->rear== ptQueue->front)
    {
        return TRUE;  
    }
    else
    {
        return FALSE; 
    }
}
/********************************************************
* Name       :bool isFullQueue(T_QUEUE *ptQueue)
* Function   :judge the queue is full or not
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : 
* Return     : TRUE:Sucess operation
                    FALSE:Failed operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isFullQueue(T_QUEUE *ptQueue)
{
    if((ptQueue->rear+1)%MAXQSIZE == ptQueue->front)
    {
        return TRUE;  
    }
    else
    {
        return FALSE; 
    }
}
/********************************************************
* Name       :int LengthQueue(T_QUEUE *ptQueue)
* Function   :get the quene length
* Input      : QUEUE_T *ptQueue 0X00000000~0XFFFFFFFF

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int LengthQueue(T_QUEUE *ptQueue)
{
    return ((ptQueue->rear - ptQueue->front + MAXQSIZE)%MAXQSIZE);
}
/********************************************************
* Name       :void TestQuene(void)
* Function   :test the quene function
* Input      : NULL
* Output:    : NULL
* Return     : NULL
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 20th Jan 2018
*********************************************************/
void TestQuene(void)
{
    int iValue = 0;
    static T_QUEUE stQueue;
    InitQueue(&stQueue);
    inQueue(&stQueue,1);
    inQueue(&stQueue,3);
    inQueue(&stQueue,5);
    inQueue(&stQueue,7);
    inQueue(&stQueue,9);
    
    outQueue(&stQueue,&iValue);
    printf("The front is %d\n",iValue);

}

int main()
{

    TestQuene();

    return TRUE;
}

/*End of file*/


