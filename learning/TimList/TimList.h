/******************************************************************************
* File       : TimList.h
* Function   : Provide timer services.
* description: To be done.           
* Version    : V0.20
* Author     : JOE
* Date       : 10th Jan 2018
* History    :  No.  When           Who           What
*               1    10/Jan/2018     JOE           Create
******************************************************************************/
    
#ifndef _TIM_LIST_H_
#define _TIM_LIST_H_
    
#ifdef __cplusplus
    extern "C" {
#endif


#define TRUE 1
#define FALSE 0
#define LEN sizeof(LISTNODE_T)

typedef void (*PTMCB)(void);

typedef struct ListNode
{
   struct ListNode *pNext;
   TIMER tTimer;
}LISTNODE_T;

typedef struct Timer
{
   PTMCB pTmCallback;
   int iTmId;
   int iOldTm;
   int iTmOut;
   int iCnt;
}TIMER;


 
#ifdef __cplusplus
}
#endif

#endif /* _TIM_LIST_H_ */

/* End of file */



