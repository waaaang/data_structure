#include "stack.h"

stackList *create_stack()
{
	stackList *plist = malloc(sizeof(stackList));
	if(NULL == plist)
	{
		perror("malloc");
		return NULL;
	}

	plist->len = 0;
	plist->pTop = NULL;
	
	return plist;
}

void stack_show(stackList *plist)
{
	stackNode *pTmpNode = plist->pTop;
	while(pTmpNode != NULL)
	{
		printf("%d ", pTmpNode->data);
		pTmpNode = pTmpNode->pNext;
	}
	printf("\n");
}

int stack_push(stackList *plist, dataType data)
{
	stackNode *pTmpNode = malloc(sizeof(stackNode));
	if(NULL == pTmpNode)
	{
		perror("malloc");
		return -1;
	}

	pTmpNode->data = data;
	pTmpNode->pNext = plist->pTop;

	plist->pTop = pTmpNode;
	plist->len++;
	return 0;
}

int is_empty(stackList *plist)
{
	return plist->len == 0;
}

int stack_pop(stackList *plist, dataType *data)
{
	stackNode *pTmpNode = plist->pTop;
	if(is_empty(plist))
	{
		return 0;
	}

	plist->pTop = pTmpNode->pNext;
	if(data != NULL)
	{
		*data = pTmpNode->data;
	}
	free(pTmpNode);
	plist->len--;
	return 0;
}


/*
stackNode *stack_top_element(stackList *plist)
{
	stackNode *pTmpNode = plist->pTop;
	while(pTmpNode->pNext != NULL)
	{
		pTmpNode = pTmpNode->pNext;
	}
	return pTmpNode;
}
*/

dataType stack_top_element(stackList *plist)
{
	if(!is_empty(plist))
	{
		return plist->pTop->data;
	}
}

void clear_stack(stackList *plist)
{
	while(plist->pTop != NULL)
	{
		stack_pop(plist, NULL);
	}
}

void destroy_stack(stackList **plist)
{
	clear_stack(*plist);
	free(*plist);
	*plist = NULL;
}

