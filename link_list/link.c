#include "link.h"

LinkList *creatLinkList()
{
	LinkList *pList = malloc(sizeof(LinkList));
	if(NULL == pList)
	{
		perror("fail to malloc");
		return NULL;
	}

	pList->pHead = NULL;
	pList->cLen = 0;

	return pList;
}

int insertHeadLinkList(LinkList *pList, DataType data)
{
	LinkNode *pInsertNode = malloc(sizeof(LinkNode));
	if(NULL == pInsertNode)
	{
		perror("fail to malloc");
		return -1;
	}

	pInsertNode->Data = data;
	
	pInsertNode->pNext = pList->pHead;
	pList->pHead = pInsertNode;

	pList->cLen++;
	
	return 0;
}

int showLinkList(LinkList *pList)
{
	LinkNode *pShowNode = pList->pHead;

	while(pShowNode != NULL)
	{
		printf("%d ", pShowNode->Data);
		pShowNode = pShowNode->pNext;
	}
	puts("");
	return 0;
}

int isEmpty(LinkList *pList)
{
	if(pList->pHead == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int insertTailLinkList(LinkList *pList, DataType data)
{
	LinkNode *pTmpNode = pList->pHead;

	LinkNode *pInsertNode = malloc(sizeof(LinkNode));
	if(NULL == pInsertNode)
	{
		perror("fail to malloc");
		return -1;
	}

	pInsertNode->Data = data;
	pInsertNode->pNext = NULL;

	if(isEmpty(pList))
	{
		insertHeadLinkList(pList, data);
	}

	while(pTmpNode->pNext != NULL)
	{
		pTmpNode = pTmpNode->pNext; 
	}
	pTmpNode->pNext = pInsertNode;

	pList->cLen++;
	return 0;

}

int deleteHead(LinkList *pList)
{
	LinkNode *pTmpNode = pList->pHead;

	if(isEmpty(pList))
	{
		return -1;
	}

	pList->pHead = pTmpNode->pNext;
	free(pTmpNode);

	pList->cLen--;

	return 0;
}

int deleteTail(LinkList *pList)
{
	LinkNode *pTmpNode = pList->pHead;
	if(isEmpty(pList))
	{
		return -1;
	}
	else if(pList->cLen == 1)
	{
		deleteHead(pList);
	}
	else
	{
		while(pTmpNode->pNext->pNext != NULL)
		{
			pTmpNode = pTmpNode->pNext;
		}
		free(pTmpNode->pNext);
		pTmpNode->pNext = NULL;
		pList->cLen--;
	}
	return 0;
}

LinkNode *findNode(LinkList *pList, DataType data)
{
	LinkNode *pTmpNode = pList->pHead;
	while(pTmpNode != NULL)
	{
		if(pTmpNode->Data == data)
		{
			return pTmpNode;
		}
		pTmpNode = pTmpNode->pNext;
	}
	return NULL;
}

int modifyNode(LinkList *pList, DataType oldData, DataType data)
{
	LinkNode *pTmpNode = NULL;
	pTmpNode = findNode(pList, oldData);
	if(pTmpNode != NULL)
	{
		pTmpNode->Data = data;
	}

	return 0;
}
int destroyList(LinkList **ppList)
{
	while((*ppList)->pHead != NULL)
	{
		deleteHead(*ppList);
	}
	free(*ppList);
	*ppList = NULL;
	return 0;
}

int converList(LinkList *pList)
{
	LinkNode *pTmpNode = pList->pHead;
	pList->pHead = NULL;
	LinkNode *pInsertNode = NULL;
	while(pTmpNode != NULL)
	{
		pInsertNode = pTmpNode;
		pTmpNode = pTmpNode->pNext;

		pInsertNode->pNext = pList->pHead;
		pList->pHead = pInsertNode;
	}
	return 0;
}

LinkNode *findMidNode(LinkList *pList)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pList->pHead;

	while(pFast != NULL)
	{
		pFast = pFast->pNext;
		if(pFast == NULL)
		{
			return pSlow;
		}
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}
	return pSlow;
}

LinkNode *find_last_k_node(LinkList *pList, int k)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pList->pHead;

	while(k--)
	{
		pFast = pFast->pNext;
	}

	while(pFast != NULL)
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}
	return pSlow;
}

int is_loop(LinkList *pList)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pList->pHead;

	while(pFast != NULL)
	{
		pFast = pFast->pNext;
		if(NULL == pFast)
		{
			return 0;
		}
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
		if(pFast == pSlow)
		{
			return 1;
		}
	}
}

LinkNode *josef(LinkList *pList)
{
	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = NULL;
	while(pList->cLen > 1)
	{
		pSlow = pFast;
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;
		pSlow->pNext = pFast->pNext;
		free(pFast);
		pList->cLen--;
		pFast = pSlow->pNext;
	}
	return pSlow;
}

int delete_point_node(LinkList *pList, DataType data)
{
	if(isEmpty(pList))
	{
		return 0;
	}

	LinkNode *pFast = pList->pHead;
	LinkNode *pSlow = pList->pHead;
	
	while(pFast != NULL)
	{
		if(pFast->Data == data)
		{
			if(pFast == pSlow)
			{
				pList->pHead = pFast->pNext;
				free(pFast);
				pFast = pList->pHead;
				pSlow = pList->pHead;
			}
			else
			{
				pSlow->pNext = pFast->pNext;
				free(pFast);
				pFast = pSlow->pNext;
			}
			pList->cLen--;
		}
		else
		{
			pSlow = pFast;
			pFast = pFast->pNext;
		}
	}

	return 0;
}

void insert_sort(LinkList *pList)
{
	if(isEmpty(pList) || 1 == pList->cLen)
	{
		return ;
	}
	/* 断开原链表， 指针指向第二个节点*/
	LinkNode *pTmpNode = pList->pHead->pNext;
	/* 让第一个节点的指针域为空 */
	pList->pHead->pNext = NULL;

	LinkNode *pInsertNode = NULL;

	while(pTmpNode != NULL)
	{
		pInsertNode = pTmpNode;
		pTmpNode = pTmpNode->pNext;
		pInsertNode->pNext = NULL;
		
		if(pInsertNode->Data < pList->pHead->Data)
		{
			pInsertNode->pNext = pList->pHead;
			pList->pHead = pInsertNode;
		}
		else
		{
			LinkNode *ptmp = pList->pHead;
			while(ptmp != NULL && ptmp->pNext != NULL && ptmp->pNext->Data < pInsertNode->Data)
			{
				ptmp = ptmp->pNext;
			}
			pInsertNode->pNext = ptmp->pNext;
			ptmp->pNext = pInsertNode;
		}

	}
}

int main(int argc, const char *argv[])
{
	LinkList *pList = NULL;
	LinkNode *pTmpNode = NULL;
	LinkNode *pMidNode = NULL;

	pList = creatLinkList();

	insertHeadLinkList(pList, 4);
	insertHeadLinkList(pList, 12);
	insertHeadLinkList(pList, 2);
	insertHeadLinkList(pList, 10);
	
	insertTailLinkList(pList, 5);
	insertTailLinkList(pList, 0);
	insertTailLinkList(pList, 7);
	insertTailLinkList(pList, -1);

	showLinkList(pList);
//	delete_point_node(pList, 3);
	insert_sort(pList);

	showLinkList(pList);


	//deleteHead(pList);

	//deleteTail(pList);

/*
	pTmpNode = findNode(pList, 3);
	if(pTmpNode == NULL)
	{
		printf("not found!\n");
	}
	else
	{
		printf("found it : %d\n", pTmpNode->Data);
	}
//	modifyNode(pList, 3, 10);

	showLinkList(pList);

	//converList(pList);

	//showLinkList(pList);

	pMidNode = findMidNode(pList);
	if(pMidNode != NULL)
	{
		printf("mid node : %d\n", pMidNode->Data);
	}

	pTmpNode = find_last_k_node(pList, 3);
	printf("last k  node : %d\n", pTmpNode->Data);
	pTmpNode = pList->pHead;
	while(pTmpNode->pNext != NULL)
	{
		pTmpNode = pTmpNode->pNext;
	}
	pTmpNode->pNext = pList->pHead;

	int ret = is_loop(pList);
	if(ret)
	{
		printf("is loop\n");
	}
	else
	{
		printf("is not a loop");
	}

	pTmpNode = josef(pList);
	printf("last one %d\n", pTmpNode->Data);
//	destroyList(&pList);
*/
	return 0;
}
