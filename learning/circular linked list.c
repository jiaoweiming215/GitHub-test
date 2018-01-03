/*****************************************************************************
* File       : circular linked list.c
* Function   : The  file complete circular linked list,can add node,delete node, search node and insert node
* Description: To be done.           
* Version    : V0.10
* Author     : JOE
* Date       : 4th Jan 2018
* History    :  No.  When           Who           What
*                  1    4/Jan/2018     JOE           Create

 ******************************************************************************/
#define TRUE 1
#define FALSE 0

typedef struct ListNode
{
   int iData;
   struct ListNode *pNext;
}LISTNODE_T;

static LISTNODE_T *sg_ptHead = NULL;
static LISTNODE_T sg_tNode;/*The node can't be deleted*/
#define LEN sizeof(LISTNODE_T)
/********************************************************
* Name       : LISTNODE_T *AddNodeToTail(int iData)
* Function   :Add node to tail
* Input      : int iData 1~255   Data for add

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *AddNodeToTail(int iData)
{
    LISTNODE_T *ptTmp,*ptElm;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }
    ptTmp->iData = iData;
    ptTmp->pNext = sg_ptHead;
    ptElm = sg_ptHead;
    while(sg_ptHead != ptElm->pNext)
    {
        ptElm = ptElm->pNext;
    }
    ptElm->pNext = ptTmp;
    return ptTmp;
}
/********************************************************
* Name       : int DelNode(int iData)
* Function   : Delete a node from list which value is equal to idata 
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     :  FALSE Node del fail
*              TRUE  Node del sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/

int DelNode(int iData)
{
    LISTNODE_T *ptTmp,*ptTmp1;
    ptTmp = sg_ptHead->pNext;
    
    while((iData != ptTmp->iData)&&(sg_ptHead != ptTmp))
    {
        ptTmp1 = ptTmp;
        ptTmp = ptTmp->pNext;
    }
    if((iData == ptTmp->iData)&&(sg_ptHead != ptTmp))
    {
        ptTmp1 = ptTmp->pNext;
        free(ptTmp);
    }
    
    return TRUE;
}
/********************************************************
* Name       : int GetElem(int iData)
* Function   : find node from list
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : None
* Return     : FALSE   Failed operation
*            : TRUE  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
int GetElem(LISTNODE_T **pHead,int iData)
{
    LISTNODE_T *ptElm;
    ptElm = sg_ptHead->pNext;
    while(sg_ptHead != ptElm)
    {
        if(iData == ptElm->iData)
        {
            printf("%d is in the list",iData);
            return TRUE;
        }
        ptElm = ptElm->pNext;
    }
    printf("%d is not in the list",iData);
    return FALSE;
}
/********************************************************
* Name       : LISTNODE_T *InsertNode(int iData)
* Function   : Insert node to list,put the big  behind small
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : sg_ptHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
*              0x00000004~0xffffffff   Node insert sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *InsertNode(int iData)
{
    LISTNODE_T *ptElm,*ptTmp;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }    
    ptElm = sg_ptHead;
    ptTmp->iData = iData;
    ptTmp->pNext = sg_ptHead;
    while((sg_ptHead != ptElm->pNext)&&(ptTmp->iData > ptElm->iData))
    {
        ptElm = ptElm->pNext;
    }
    if(ptTmp->iData <= ptElm->iData)
    {
        if(ptElm == sg_ptHead)
        {
            sg_ptHead = ptTmp;
            ptTmp ->pNext =ptElm;
        }
        else if(sg_ptHead != ptElm->pNext)
        {
            ptTmp->pNext = ptElm;
        }
    }
    else
    {
        ptElm->pNext = ptTmp;
    }
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
    
    ptNode = AddNodeToTail(1);

    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    ptNode = AddNodeToTail(2);
    ptNode = AddNodeToTail(3);
    ptTmp = sg_ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    GetElem(2);
    GetElem(5);
    ptNode = InsertNode(5);
    GetElem(5);
    iTmp = DelNode(5);
    GetElem(5);
    return TRUE;
}

/*End of file*/


