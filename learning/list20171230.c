/*****************************************************************************
* File       : ListApp.c
* Function   : The listapp can add node,delete node, search node and insert node
* Description: To be done.           
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
* History    :  No.  When           Who           What
*                   1    2/Jan/2018     JOE           Create

 ******************************************************************************/
#define TRUE 1
#define FALSE 0
typedef struct ListNode
{
   int iData;
   struct ListNode *pNext;
}LISTNODE_T;
#define LEN sizeof(LISTNODE_T)
/********************************************************
* Name       : LISTNODE_T *AddNodeToTail(LISTNODE_T **pHead,int iData)
* Function   : Add node to tail
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : pHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *AddNodeToTail(LISTNODE_T **pHead,int iData)
{
    LISTNODE_T *ptTmp,*ptElm;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }
    ptTmp->iData = iData;
    ptTmp->pNext = NULL;
    if(NULL == *pHead)
    {
        *pHead = ptTmp;
    }
    else
    {
       ptElm = *pHead;
       while(NULL != ptElm->pNext)
       {
        ptElm = ptElm->pNext;
       }
       ptElm->pNext = ptTmp;
    }
    return ptTmp;
}
/********************************************************
* Name       : int DelNode(LISTNODE_T **pHead,int iData)
* Function   : Delete node from list
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : pHead The head of the list 0x00000000~0xffffffff   
* Return     :  FALSE Node del fail
*              TRUE  Node del sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/

int DelNode(LISTNODE_T **pHead,int iData)
{
     LISTNODE_T *ptTmp,*ptTmp1,*ptHead;
     ptHead = *pHead;
     ptTmp = *pHead;
     if(NULL == ptHead)
     {
         printf("\nlist null\n");
        return FALSE;
     }
     else
     {
         if(iData == ptTmp->iData)
         {
             ptHead = ptHead->pNext;
             *pHead = ptHead;
             free(ptTmp);
         }
        else
        {
            while((iData != ptTmp->iData)&&(NULL != ptTmp))
             {
                 ptTmp1 = ptTmp;
                 ptTmp = ptTmp->pNext;
             }
             if((iData == ptTmp->iData)&&(NULL != ptTmp))
             {
                 ptTmp1 = ptTmp->pNext;
                 free(ptTmp);
             }

        }
         
    }
    return TRUE;
}
/********************************************************
* Name       : int GetElem(LISTNODE_T **pHead,int iData)
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
    ptElm = *pHead;
    if(NULL == ptElm)
    {
        printf("the list is NULL");
        return FALSE;
    }
    while(NULL != ptElm)
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
* Name       : LISTNODE_T *InsertNode(LISTNODE_T **pHead,int iData)
* Function   : Insert node to list,put the big  behind small
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

* Output:    : pHead The head of the list 0x00000000~0xffffffff   
* Return     : NULL   Failed operation
*            : Other  Sucess operation
*              0x00000004~0xffffffff   Node insert sucess.
* Description: To be done
* Version    : V0.10
* Author     : JOE
* Date       : 2nd Jan 2018
*********************************************************/
LISTNODE_T *InsertNode(LISTNODE_T **pHead,int iData)
{
    LISTNODE_T *ptElm,*ptTmp;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(NULL == ptTmp)
    {
        printf("It's out of memory");
        return NULL;
    }    
    ptElm = *pHead;
    ptTmp->iData = iData;
    ptTmp->pNext = NULL;
    if(NULL == *pHead)
    { 
        *pHead = ptTmp;
    }
    else
    {
        while((NULL != ptElm->pNext)&&(ptTmp->iData > ptElm->iData))
        {
            ptElm = ptElm->pNext;
        }
        if(ptTmp->iData <= ptElm->iData)
        {
            if(ptElm == *pHead)
            {
                *pHead = ptTmp;
                ptTmp ->pNext =ptElm;
            }
            else if(NULL != ptElm->pNext)
            {
                ptTmp->pNext = ptElm;
            }
        }
        else
        {
            ptElm->pNext = ptTmp;
        }
    }
    return ptTmp;
}

int main()
{
    int iTmp;
    LISTNODE_T *ptHead,*ptTmp,*ptNode;
    ptHead = NULL;
    
    ptNode = AddNodeToTail(&ptHead,1);

    ptTmp = ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    ptNode = AddNodeToTail(&ptHead,2);
    ptNode = AddNodeToTail(&ptHead,3);
    ptTmp = ptHead;
    while(NULL != ptTmp)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    GetElem(&ptHead,2);
    GetElem(&ptHead,5);
    ptNode = InsertNode(&ptHead,5);
    GetElem(&ptHead,5);
    iTmp = DelNode(&ptHead,5);
    GetElem(&ptHead,5);
    return TRUE;
}



