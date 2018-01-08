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
   int iNum;
   int iOldTim;
   
   struct ListNode *pNext;
}LISTNODE_T;

static  LISTNODE_T *sg_ptHead = NULL;

#define LEN sizeof(LISTNODE_T)
