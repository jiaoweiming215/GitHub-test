/*****************************************************************************
*功能描述:	链表新增节点
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
int AddNodeToTail(LISTNODE_T** pHead,LISTNODE_T *pNode)
{
    LISTNODE_T *ptTmp;
	if(*pHead == NULL)
    {
		ptTmp = (LISTNODE_T *)malloc(LEN);
		if(ptTmp == NULL)
		{
			return FALSE;
		}
        *pHead = pNode;
		ptTmp = *pHead;
		pNode->pNext = NULL;
	}
	else
	{
       ptTmp = *pHead;
	   while(ptTmp->pNext!=NULL)
	   {
        ptTmp = ptTmp->pNext;
	   }
	   ptTmp = (LISTNODE_T *)malloc(LEN);
	   if(ptTmp == NULL)
	   {
		   return FALSE;
	   }
	   ptTmp->pNext = pNode;
	   pNode->pNext = NULL;
	}
	return TRUE;
}

/*void del(LISTNODE_T** pHead,int iData)
{
   LISTNODE_T *ptTmp;
   
   
}*/

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
	LISTNODE_T tNode1,tNode2;
	ptHead = NULL;
	tNode1.iData = 1; 
	AddNodeToTail(&ptHead,&tNode1);

    ptTmp = ptHead;
    while(ptTmp!=NULL)
    {
        printf("%d",ptTmp->iData);
		ptTmp = ptTmp->pNext;
	}
	tNode2.iData = 2; 
	AddNodeToTail(&ptHead,&tNode2);

    ptTmp = ptHead;
    while(ptTmp!=NULL)
    {
        printf("%d",ptTmp->iData);
		ptTmp = ptTmp->pNext;
	}
	GetElem(&ptHead,2);
	GetElem(&ptHead,5);
	InsertNode(&ptHead,5);
	GetElem(&ptHead,5);
	return TRUE;
}


