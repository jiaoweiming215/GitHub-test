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
#define MAXQSIZE 10
#define LENGTH sizeof(QUEUE_T)
typedef struct Queue
{
   int *piBase;
   int front;
   int rear;
}QUEUE_T;

void initQueue(QUEUE_T *pQueue);
void freeQueue(QUEUE_T *pQueue);
void inQueue(QUEUE_T *pQueue);
void outQueue(QUEUE_T *pQueue);
bool isEmptyQueue(QUEUE_T *pQueue);
bool isFullQueue(QUEUE_T *pQueue);
int LengthQueue(QUEUE_T *pQueue);
#ifdef __cplusplus
}
#endif

#endif /* _QUEUE_H_ */

/* End of file */



