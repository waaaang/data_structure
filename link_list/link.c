#include "link.h"


LinkList *creatLinkList()
{
	LinkList *pList = malloc(sizeof(LinkList));
	if (NULL == pList)
	{
		perror("fail to malloc");
		return NULL;
	}
	pList->pHead = NULL;
	pList->cLen = 0;

	return pList;
}


int insertHeadLinkList(LinkList *pList,DataType data)
{
	LinkNode *pInsertNode = malloc(sizeof(LinkNode));
	if (NULL == pInsertNode)
	{
		perror("fail to malloc");
		return -1;
	}
	pInsertNode->data = data;

	pInsertNode->pNext = pList->pHead;
	pList->pHead = pInsertNode;
	pList->cLen++;

	return 0;
}

void showLinkList(LinkList *pList)
{
	LinkNode *pTmpNode = pList->pHead;

	while (pTmpNode != NULL)
	{
		printf("%d ",pTmpNode->data);
		pTmpNode = pTmpNode->pNext;
	}
	printf("\n");
}

int isEmptyLinkList(LinkList *pList)
{
	return pList->cLen == 0;
}
int insertTailLinkList(LinkList *pList,DataType data)
{
	LinkNode *pInsertNode = malloc(sizeof(LinkNode));
	if (NULL == pInsertNode)
	{
		perror("fail to malloc");
		return -1;
	}
	pInsertNode->data = data;
	pInsertNode->pNext = NULL;

	if (isEmptyLinkList(pList))
	{
		insertHeadLinkList(pList,data);
	}
	else
	{
		LinkNode *pTmpNode = pList->pHead;
		while (pTmpNode->pNext != NULL)
		{
			pTmpNode = pTmpNode->pNext;
		}
		pTmpNode->pNext = pInsertNode;
		pList->cLen++;
	}

	return 0;
}
int deleteHeadLinkList(LinkList *pList)
{
	if (isEmptyLinkList(pList))
	{
		return 0;
	}
	LinkNode *pFreeNode = pList->pHead;
	pList->pHead = pFreeNode->pNext;
	free(pFreeNode);
	pList->cLen--;

	return 0;
}

int deleteTailLinkList(LinkList *pList)
{
	if (isEmptyLinkList(pList))
	{
		return 0;
	}
	else if (1 == pList->cLen)
	{
		deleteHeadLinkList(pList);
	}
	else
	{
		LinkNode *pTmpNode = pList->pHead;
		while (pTmpNode->pNext->pNext != NULL)
		{
			pTmpNode = pTmpNode->pNext;
		}
		free(pTmpNode->pNext);
		pTmpNode->pNext = NULL;
		pList->cLen--;
	}

	return 0;
}

LinkNode *findLinkNode(LinkList *pList,DataType data)
{
	LinkNode *pTmpNode = pList->pHead;
	while (pTmpNode != NULL)
	{
		if (pTmpNode->data == data)
		{
			return pTmpNode;
		}
		pTmpNode = pTmpNode->pNext;
	}
	
	return NULL;
}
int modifyLinkList(LinkList *pList,DataType olddata,DataType newdata)
{
	LinkNode *pTmpNode = NULL;
	while ((pTmpNode = findLinkNode(pList,olddata)) != NULL)
	{
		pTmpNode->data = newdata;	
	}
	return 0;
}

void destroyLinkList(LinkList **ppList)
{
	if (isEmptyLinkList(*ppList))
	{
		free(*ppList);
		return ;
	}
	while ((*ppList)->pHead != NULL)
	{
		deleteHeadLinkList(*ppList);
	}
	free(*ppList);
	*ppList = NULL;

	return ;
}

LinkNode *findMidLinkList(LinkList *pList)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pFast;

	while (pFast != NULL)
	{
		pFast = pFast->pNext;
		if (NULL == pFast)
		{
			break;
		}
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}

	return pSlow;
}
LinkNode *findLastKNode(LinkList *pList,int K)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pFast;
	int i = 0;
	for (i = 0; i < K;i++)
	{
		pFast = pFast->pNext;
	}
	while (pFast != NULL)
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}

	return pSlow;
}
int isLoopLinkList(LinkList *pList)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pFast;

	while (pFast != NULL)
	{
		pFast = pFast->pNext;
		if (NULL == pFast)
		{
			return 0;
		}
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
		if (pFast == pSlow)
		{
			return 1;
		}
	}
}

int main(int argc, const char *argv[])
{
	LinkList *pList = NULL;
	LinkNode *pTmpNode = NULL;
	pList = creatLinkList();

	insertHeadLinkList(pList,1);
	insertHeadLinkList(pList,2);
	insertHeadLinkList(pList,3);
	insertHeadLinkList(pList,4);
	insertHeadLinkList(pList,4);
	insertHeadLinkList(pList,4);
//	insertHeadLinkList(pList,4);

	insertTailLinkList(pList,5);

	showLinkList(pList);
#if 0
	deleteHeadLinkList(pList);
	showLinkList(pList);

	deleteTailLinkList(pList);
	showLinkList(pList);

	pTmpNode = findLinkNode(pList,2);
	if (NULL != pTmpNode)
	{
		printf("find node %d\n",pTmpNode->data);
	}
	else
	{
		printf("not find.\n");
	}

	modifyLinkList(pList,4,10);
	showLinkList(pList);
#endif

	pTmpNode = findMidLinkList(pList);
	printf("mid node %d\n",pTmpNode->data);

	pTmpNode = findLastKNode(pList,3);
	printf("last k node %d\n",pTmpNode->data);
	
	pTmpNode = pList->pHead;
	while (pTmpNode->pNext != NULL)
	{
		pTmpNode = pTmpNode->pNext;
	}
	pTmpNode->pNext = pList->pHead;

	int ret = isLoopLinkList(pList);
	if (ret)
	{
		printf("Is loop\n");
	}
	else
	{
		printf("Is not loop\n");
	}


//	destroyLinkList(&pList);

	return 0;
}


