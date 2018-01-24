/*****************************************************************************
* File       : TimList.c
* Function   : Provide time services
* Description: To be done.           
* Version    : V0.20
* Author     : JOE
* Date       : 10th Jan 2018
* History    :  No.  When           Who           What
*               1    10/Jan/2018     JOE           Create

 ******************************************************************************/
#include "TimList.h"

static  LISTNODE_T *sg_ptHead = NULL;
static unsigned int sg_u32SysTm = 0;
static LISTNODE_T sg_tNode;/*The node can't be deleted*/

/********************************************************
* Name       : LISTNODE_T *AddNodeToTail(TIMER* timer)
* Function   :Add node to tail
* Input      : TIMER* timer Pointer of timers set by user.

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *AddNodeToTail(TIMER* timer)
{
    LISTNODE_T *ptTmp,*ptElm;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }
    ptTmp->tTimer.iTmId = timer->iTmId;
    ptTmp->tTimer.iOldTm = sg_u32SysTm;
    ptTmp->tTimer.iTmOut = timer->iTmOut;
    ptTmp->tTimer.iCnt = timer->iCnt;
    ptTmp->tTimer.pTmCallback = timer->pTmCallback;
    if(NULL == timer->pPara)
    {
        ptTmp->tTimer.pPara = (void *)ptTmp;
    }
    else
    {
        ptTmp->tTimer.pPara = timer->pPara;
    }
    
    ptTmp->tTimer.pNext = sg_ptHead;
    /*the add iData is the first must modify sg_ptHead*/
    if(sg_ptHead->pNext == sg_ptHead)
    {
        sg_ptHead->pNext = ptTmp;
        return ptTmp;
    }
    ptElm = sg_ptHead;
    while(sg_ptHead != ptElm->pNext)
    {
        ptElm = ptElm->pNext;
    }
    ptElm->pNext = ptTmp;
    return ptTmp;
}
/********************************************************
* Name       : int DelNode(int iTmId)
* Function   : Delete a node from list which value is equal to idata 
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
               int iTmId 1~2^32   the tmr ID

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     :  FALSE Node del fail
*              TRUE  Node del sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/

int DelNode(int iTmId)
{
    LISTNODE_T *ptTmp,*ptTmp1;
    ptTmp = sg_ptHead->pNext;
    /*del all nodes which value is equal to idata*/
    while(sg_ptHead != ptTmp)
    {
        if(iTmId == ptTmp->tTimer.iTmId)
        {
            ptTmp1 = ptTmp->pNext;
            free(ptTmp);
            ptTmp1 = ptTmp;
            continue;
        }
        ptTmp1 = ptTmp;
        ptTmp = ptTmp->pNext;
    }
    return TRUE;
}

/********************************************************
* Name       : void print()
* Function   : print task
* Input      : int iCnt 1~2^32 the tmr ID

* Output:    : NULL
* Return     : NULL   
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 15th Jan 2018
*********************************************************/
void print(void *pare)
{
    int a;
    a = (int*)pare;
    printf("%d\n",a);
}

void print1(void *pare)
{
    printf("task2\n");
}
void print2(void *pare)
{
    printf("task3\n");
}

int main()
{
    int iTmp;
    LISTNODE_T *ptHead,*ptTmp,*ptNode;
    TIMER tTimer;
    /*init a static global circular list */
    sg_tNode.tTimer.iData = 0;
    sg_tNode.pNext =sg_ptHead;
    sg_ptHead = sg_tNode;
    sg_tNode.tTimer.pTmCallback = NULL;
    sg_u32SysTm = 0;
    tTimer.iTmId = 1;
    tTimer.iTmOut= 10;
    tTimer.iCnt= 0xaa;
    tTimer.pTmCallback = print;
    ptNode = AddNodeToTail(&tTimer);

    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iTmId);
        ptTmp = ptTmp->pNext;
    }
    tTimer.iTmId = 2;
    tTimer.iTmOut= 20;
    tTimer.iCnt= 0x01;
    tTimer.pTmCallback = print1;
    ptNode = AddNodeToTail(&tTimer);
    tTimer.iTmId = 3;
    tTimer.iTmOut= 30;
    tTimer.iCnt= 0x02;
    tTimer.pTmCallback = print2;
    ptNode = AddNodeToTail(&tTimer);
    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iTmId);
        ptTmp = ptTmp->pNext;
    }

    iTmp = DelNode(5);
    while(1)
    {
        ptTmp = sg_ptHead;
        while(sg_ptHead != ptTmp->pNext)
        {
            if(NULL != ptTmp->tTimer.iCnt)
            {
                if(ptTmp->tTimer.iTmOut > sg_u32SysTm - ptTmp->tTimer.iOldTm)
                {
                    ptTmp->iOldTm = sg_u32SysTm;
                    if(NULL != ptTmp->tTimer.pTmCallback)
                    {
                        ptTmp->tTimer.pTmCallback(ptTmp->tTimer.pPara);
                    }
                }
            }
            else
            {
                DelNode(ptTmp->tTimer.iTmId);
            }
            if(0xAA != ptTmp->tTimer.iCnt)
            {
                ptTmp->tTimer.iCnt--;
            }
            ptTmp = ptTmp->pNext;
        }
    }
    return TRUE;
}

/*End of file*/


