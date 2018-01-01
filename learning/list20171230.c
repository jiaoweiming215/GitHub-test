/*****************************************************************************
*功能描述:    链表新增节点
删除节点
查找节点
插入节点
 ******************************************************************************/
//#include "ListApp.h"
#define TRUE 1
#define FALSE 0
typedef struct ListNode
{
   int iData;
   struct ListNode *pNext;
}LISTNODE_T;
#define LEN sizeof(LISTNODE_T)
/*新增节点*/
LISTNODE_T *AddNodeToTail(LISTNODE_T** pHead,int iData)
{
    LISTNODE_T *ptTmp,*ptElm,*ptHead;
    ptHead = *pHead;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(ptTmp == NULL)
    {
        printf("It's out of memory");
        return ptHead;
    }
    ptTmp->iData = iData;
    ptTmp->pNext = NULL;
    if(*pHead == NULL)
    {
        *pHead = ptTmp;
    }
    else
    {
       ptElm = *pHead;
       while(ptElm->pNext!=NULL)
       {
        ptElm = ptElm->pNext;
       }
       ptElm->pNext = ptTmp;
    }
    return ptHead;
}
/*删除节点*/
LISTNODE_T *DelNode(LISTNODE_T** pHead,int iData)
{
    LISTNODE_T *ptTmp,*ptTmp1,*ptHead;
    ptHead = *pHead;
    ptTmp = *pHead;
    if(ptHead == NULL)
    {
        printf("\nlist null\n");
    }
    else
    {
        if(iData ==ptTmp->iData)
        {
            ptHead = ptHead->pNext;
            free(ptTmp);
        }
        while((iData != ptTmp->iData)&&(ptTmp!= NULL))
        {
            ptTmp1 = ptTmp;
            ptTmp = ptTmp->pNext;
        }
        if((iData == ptTmp->iData)&&(ptTmp->pNext != NULL))
        {
            ptTmp1 = ptTmp->pNext;
            free(ptTmp);
        }
   }
   return ptHead;
}
/*查找节点*/
int GetElem(LISTNODE_T **pHead,int iData)
{
    LISTNODE_T *ptElm;
    ptElm = *pHead;
    if(ptElm == NULL)
    {
        printf("the list is NULL");
        return FALSE;
    }
    while(ptElm!=NULL)
    {
        if(ptElm->iData == iData)
        {
            printf("%d is in the list",iData);
            return TRUE;
        }
        ptElm = ptElm->pNext;
    }
    printf("%d is not in the list",iData);
    return FALSE;
}
/*插入节点*/
int InsertNode(LISTNODE_T **pHead,int iData)
{
    LISTNODE_T *ptElm,*ptTmp;
    ptTmp = (LISTNODE_T *)malloc(LEN);
    if(ptTmp == NULL)
    {
        printf("It's out of memory");
        return FALSE;
    }    
    ptTmp->iData = iData;
    ptTmp->pNext = NULL;
    if(*pHead == NULL)
    { 
        *pHead = ptElm;
        return TRUE;
    }
    else
    {
        ptElm = *pHead;
        while(ptElm->pNext!=NULL)
        {
            ptElm = ptElm->pNext;
        }
        ptElm->pNext = ptTmp;
        return TRUE;
    }
}
void main()
{
    LISTNODE_T *ptHead,*ptTmp;
    ptHead = NULL;
    
    ptHead = AddNodeToTail(&ptHead,1);

    ptTmp = ptHead;
    while(ptTmp!=NULL)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    ptHead = AddNodeToTail(&ptHead,2);
    ptHead = AddNodeToTail(&ptHead,3);
    ptTmp = ptHead;
    while(ptTmp!=NULL)
    {
        printf("%d\n",ptTmp->iData);
        ptTmp = ptTmp->pNext;
    }
    GetElem(&ptHead,2);
    GetElem(&ptHead,5);
    InsertNode(&ptHead,5);
    GetElem(&ptHead,5);
    ptHead = DelNode(&ptHead,5);
    GetElem(&ptHead,5);
    return TRUE;
}


