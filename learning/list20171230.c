/*****************************************************************************
*功能描述:	链表新增节点
 ******************************************************************************/
//#include "ListApp.h"
typedef struct ListNode
{
   int iData;
   struct ListNode *pNext;
}LISTNODE_T;
#define LEN sizeof(LISTNODE_T)
/*新增节点*/
void AddNodeToTail(LISTNODE_T** pHead,LISTNODE_T *pNode)
{
    LISTNODE_T *ptTmp;
	ptTmp = (LISTNODE_T *)malloc(LEN);
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
}


