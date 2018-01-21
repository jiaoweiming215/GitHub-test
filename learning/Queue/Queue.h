/******************************************************************************
* File       : Queue.h
* Function   : Provide timer services.
* description: To be done.           
* Version    : V0.20
* Author     : JOE
* Date       : 17th Jan 2018
* History    :  No.  When           Who           What
*               1    17/Jan/2018     JOE           Create
******************************************************************************/
    
#ifndef _QUEUE_H_
#define _QUEUE_H_
    
#ifdef __cplusplus
    extern "C" {
#endif

#define NULL (0)
#define TRUE (1)
#define FALSE (0)
#define MAXQSIZE (10)
#define LENGTH (sizeof(T_QUEUE))
typedef struct Queue
{
   int *piBase;
   int front;
   int rear;
}T_QUEUE;

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
int InitQueue(T_QUEUE *ptQueue);
/********************************************************
* Name       :void freeQueue(T_QUEUE *ptQueue)
* Function   :free the queue
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : 
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
void FreeQueue(T_QUEUE *ptQueue);
/********************************************************
* Name       :int inQueue(T_QUEUE *ptQueue,int iValue)
* Function   :add data to the queue
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
int insertQueue(T_QUEUE *ptQueue,int iValue);
/********************************************************
* Name       : int outQueue(T_QUEUE *ptQueue,int *iValue)
* Function   :
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
int outQueue(T_QUEUE *ptQueue,int *iValue);
/********************************************************
* Name       :bool isEmptyQueue(T_QUEUE *ptQueue)
* Function   :judge the queue is empty
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : TRUE:Sucess operation
                    FALSE:Failed operation
* Return     : 
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isEmptyQueue(T_QUEUE *ptQueue);
/********************************************************
* Name       :bool isFullQueue(T_QUEUE *ptQueue)
* Function   :judge the queue is full
* Input      : T_QUEUE *ptQueue :the point of queue struct

* Output:    : 
* Return     : TRUE:Sucess operation
                    FALSE:Failed operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 17th Jan 2018
*********************************************************/
bool isFullQueue(T_QUEUE *ptQueue);
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
int LengthQueue(T_QUEUE *ptQueue);
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
void TestQuene(void);

#ifdef __cplusplus
}
#endif

#endif /* _QUEUE_H_ */

/* End of file */



