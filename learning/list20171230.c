/*****************************************************************************
*功能描述:	链表新增节点
链表删除节点
查找节点
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
	ptTmp = (LISTNODE_T *)malloc(LEN);
	if(ptTmp == NULL)
	{
        return FALSE;
	}
	if(*pHead == NULL)
    {
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
	return TRUE;
}


