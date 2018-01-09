/*****************************************************************************
* File       : ListApp.c
* Function   : The listapp can add node,delete node, search node and insert node
* Description: To be done.           
* Version    : V0.10
* Author     : JOE
* Date       : 8th Jan 2018
* History    :  No.  When           Who           What
*               1    8/Jan/2018     JOE           Create

 ******************************************************************************/
#define TRUE 1
#define FALSE 0

typedef struct ListNode
{
   int iTmId;
   int iOldTm;
   int iTmOut;
   struct ListNode *pNext;
}LISTNODE_T;

static  LISTNODE_T *sg_ptHead = NULL;
static unsigned int sg_u32OldTm = 0;
static LISTNODE_T sg_tNode;/*The node can't be deleted*/

#define LEN sizeof(LISTNODE_T)
/********************************************************
* Name       : LISTNODE_T *AddNodeToTail(int iTmId,int iTmOut)
* Function   :Add node to tail
* Input      : int iTmId 1~2^32  the tmr ID
               int iTmOut 1~2^32 timing interval

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *AddNodeToTail(int iTmId,int iTmOut)
{
    LISTNODE_T *ptTmp,*ptElm;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }
    ptTmp->iTmId = iTmId;
    ptTmp->iOldTm = sg_u32OldTm;
    ptTmp->iTmOut = iTmOut;
    ptTmp->pNext = sg_ptHead;
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
        if(iTmId == ptTmp->iTmId)
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
* Name       : int GetElem(LISTNODE_T **pHead,int iTmId)
* Function   : find node from list
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
               int iTmId 1~2^32   the tmr ID

* Output:    : None
* Return     : FALSE   Failed operation
*            : TRUE  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
int GetElem(LISTNODE_T **pHead,int iTmId)
{
    LISTNODE_T *ptElm;
    ptElm = sg_ptHead->pNext;
    while(sg_ptHead != ptElm)
    {
        if(iTmId == ptElm->iTmId)
        {
            printf("%d is in the list",iTmId);
            return TRUE;
        }
        ptElm = ptElm->pNext;
    }
    printf("%d is not in the list",iTmId);
    return FALSE;
}
/********************************************************
* Name       : LISTNODE_T *InsertNode(int iTmId)
* Function   : Insert node to list,put the big  behind small
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
               int iTmId 1~2^32 the tmr ID

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
*              0x00000004~0xffffffff   Node insert sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *InsertNode(int iTmId,int iTmOut)
{
    LISTNODE_T *ptElm,*ptTmp;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }
    ptElm = sg_ptHead;
    ptTmp->iTmId = iTmId;
    ptTmp->iOldTm = sg_u32OldTm;
    ptTmp->iTmOut = iTmOut;
    /*the insert iData is the first must modify sg_ptHead*/
    if(sg_ptHead->pNext == sg_ptHead)
    {
        sg_ptHead->pNext = ptTmp;
        return ptTmp;
    }
    while((sg_ptHead != ptElm->pNext)&&(ptTmp->iTmId > ptElm->iTmId))
    {
        ptElm = ptElm->pNext;
    }
    ptTmp->pNext = ptElm->pNext;
    ptElm->pNext = ptTmp;
    return ptTmp;
}

int main()
{
    int iTmp;
    LISTNODE_T *ptHead,*ptTmp,*ptNode;
    /*init a static global circular list */
    sg_tNode.iData = 0;
    sg_tNode.pNext =sg_ptHead;
    sg_ptHead = sg_tNode;
    sg_u32OldTm = 0;
    ptNode = AddNodeToTail(1,10);

    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iTmId);
        ptTmp = ptTmp->pNext;
    }
    ptNode = AddNodeToTail(2,20);
    ptNode = AddNodeToTail(3,30);
    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iTmId);
        ptTmp = ptTmp->pNext;
    }
    GetElem(2);
    GetElem(5);
    ptNode = InsertNode(5,50);
    GetElem(5);
    iTmp = DelNode(5);
    GetElem(5);
    while(1)
    {
        while(sg_ptHead != ptTmp->pNext)
        {
            if(ptTmp->iTmOut > sg_u32OldTm - ptTmp->iOldTm)
            {
                printf("%d\n",ptTmp->iTmId);
            }
            ptTmp = ptTmp->pNext;
        }
    }
    return TRUE;
}

/*End of file*/


