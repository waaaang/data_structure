#include "queue.h"

queue_list *creat_queue()
{
	queue_list *plist = malloc(sizeof(queue_list));
	if(NULL == plist)
	{
		perror("malloc");
		return NULL;
	}

	plist->len = 0;
	plist->pFront = NULL;
	plist->pRear = NULL;

	return plist;
}

int is_empty(queue_list *plist)
{
	return plist->len == 0;
}

void show_queue(queue_list *plist)
{
	queue_node *pTmpNode = plist->pFront;
	while(pTmpNode != NULL)
	{
		printf("%d ", pTmpNode->data);
		pTmpNode = pTmpNode->pNext;
	}
	printf("\n");
}

//入队
int enqueue(queue_list *plist, dataType data)
{
	queue_node *pTmpNode = malloc(sizeof(queue_node));
	if(NULL == pTmpNode)
	{
		perror("malloc");
		return -1;
	}

	pTmpNode->data = data;
	pTmpNode->pNext = NULL;

	if(is_empty(plist))
	{
		plist->pFront = pTmpNode;
		plist->pRear = pTmpNode;
	}
	else
	{
		plist->pRear->pNext = pTmpNode;
		plist->pRear = pTmpNode;
	}
	plist->len++;
	return 0;
}

int leave_queue(queue_list *plist, dataType *data)
{
	queue_node *pTmpNode = plist->pFront;
	
	if(is_empty(plist))
	{
		return -1;
	}

	plist->pFront = pTmpNode->pNext;
	if(data != NULL)
	{
		*data = pTmpNode->data;
	}
	free(pTmpNode);

	if(plist->pFront == NULL)
	{
		plist->pRear = NULL;
	}

	return 0;
}

int destroy_queue(queue_list **plist)
{
	while((*plist)->pFront != NULL)
	{
		leave_queue(*plist, NULL);
	}
	free(*plist);
	*plist = NULL;
	return 0;
}
