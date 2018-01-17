/*****************************************************************************
* File       : queue.c
* Function   : Provide time services
* Description: To be done.           
* Version    : V0.20
* Author     : JOE
* Date       : 17th Jan 2018
* History    :  No.  When           Who           What
*               1    17/Jan/2018     JOE           Create

 ******************************************************************************/
#include "queue.h"


/********************************************************
* Name       : void initQueue(QUEUE_T *pQueue)
* Function   :init the queue
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
void initQueue(QUEUE_T *pQueue)
{
    pQueue->piBase = (QUEUE_T *)malloc(LENGTH);
    if(NULL == pQueue->piBase)
    {
        print("NO MEMORY!\n");
    }
    pQueue->front = NULL;
    pQueue->rear= NULL;
    return;
}
/********************************************************
* Name       :void freeQueue(QUEUE_T *pQueue)
* Function   :init the queue
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
void freeQueue(QUEUE_T *pQueue)
{
    return ;
}
/********************************************************
* Name       :int inQueue(QUEUE_T *pQueue,int iValue)
* Function   :init the queue
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : TRUE Sucess operation
                    FALSE Failed operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int inQueue(QUEUE_T *pQueue,int iValue)
{
    int iIndex;
    iIndex = isFullQueue(pQueue);
    if(FALSE== iIndex)
    {   
        pQueue->piBase[pQueue->rear] = iValue;  
        pQueue->rear = (pQueue->rear+1) % MAXQSIZE;  
        return TRUE; 
    }
    else
    {
        return FALSE;
    }
}
/********************************************************
* Name       : int outQueue(QUEUE_T *pQueue,int *iValue)
* Function   :
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int outQueue(QUEUE_T *pQueue,int *iValue)
{
    int iIndex;
    iIndex = isEmptyQueue(pQueue);
    if(TRUE == iIndex)
    {
        return FALSE;
    }
    else
    {
        *iValue = pQueue->piBase[pQueue->front];
        pQueue->front = (pQueue->front+1)%MAXQSIZE;
        return TRUE;
    }
}

/********************************************************
* Name       :bool isEmptyQueue(QUEUE_T *pQueue)
* Function   :judge the queue is empty
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isEmptyQueue(QUEUE_T *pQueue)
{
    if(pQueue->rear== pQueue->front)
    {
        return TRUE;  
    }
    else
    {
        return FALSE; 
    }
}
/********************************************************
* Name       :bool isFullQueue(QUEUE_T *pQueue)
* Function   :judge the queue is full
* Input      : QUEUE_T *pQueue 

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isFullQueue(QUEUE_T *pQueue)
{
    if((pQueue->rear+1)%MAXQSIZE == pQueue->front)
    {
        return TRUE;  
    }
    else
    {
        return FALSE; 
    }
}
/********************************************************
* Name       :int LengthQueue(QUEUE_T *pQueue)
* Function   :get the quene length
* Input      : QUEUE_T *pQueue 0X00000000~0XFFFFFFFF

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
int LengthQueue(QUEUE_T *pQueue)
{
    return ((pQueue->rear-pQueue->front+MAXQSIZE)%MAXQSIZE);
}

int main()
{
    int iValue;
    QUEUE_T tQueue;

    initQueue(&tQueue);
    inQueue(&tQueue,1);
    inQueue(&tQueue,3);
    inQueue(&tQueue,5);
    inQueue(&tQueue,7);
    inQueue(&tQueue,9);
    return TRUE;
}

/*End of file*/


