/*****************************************************************************
* File       : ListApp.c
* Function   : The listapp can add node,delete node, search node and insert node
* Description: To be done.           
* Version    : V0.10
* Author     : JOE
* Date       : 3rd Jan 2018
* History    :  No.  When           Who           What
*                  1    3/Jan/2018     JOE           Create

 ******************************************************************************/
#define TRUE 1
#define FALSE 0

typedef struct ListNode
{
   int iData;
   struct ListNode *pNext;
}LISTNODE_T;

static  LISTNODE_T *sg_ptHead = NULL;

#define LEN sizeof(LISTNODE_T)
/********************************************************
* Name       : LISTNODE_T *AddNodeToTail(int iData)
* Function   : Add node to tail
* Input      : LISTNODE_T **pHead  0x00000000~0xffffffff    Address of the head node's address;
                   int iData 1~255   Data for add

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
    ptTmp->pNext = NULL;
    if(NULL == sg_ptHead)
    {
        sg_ptHead = ptTmp;
    }
    else
    {
       ptElm = sg_ptHead;
       while(NULL != ptElm->pNext)
       {
        ptElm = ptElm->pNext;
       }
       ptElm->pNext = ptTmp;
    }
    return ptTmp;
}
/********************************************************
* Name       : int DelNode(int iData)
* Function   : Delete node from list
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
     LISTNODE_T *ptTmp,*ptTmp1,*ptHead;
     ptHead = sg_ptHead;
     if(NULL == sg_ptHead)
     {
         printf("\nlist null\n");
        return FALSE;
     }
     else
     {
         if(iData == ptTmp->iData)
         {
             ptHead = ptHead->pNext;
             sg_ptHead = ptHead;
             free(ptTmp);
         }
        else
        {
            ptTmp = sg_ptHead->pNext;
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
    ptElm = sg_ptHead;
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
    ptTmp->pNext = NULL;
    if(NULL == sg_ptHead)
    { 
        sg_ptHead = ptTmp;
    }
    else
    {
        while((NULL != ptElm->pNext)&&(ptTmp->iData > ptElm->iData))
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
    sg_ptHead = NULL;
    
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

