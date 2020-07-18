#include "double_link.h"


double_list *creat_double_link()
{
	double_list *plist = malloc(sizeof(double_list));
	if(NULL == plist)
	{
		perror("malloc");
		return NULL;
	}

	plist->phead = NULL;
	plist->len = 0;

	return plist;
}

int head_insert(double_list *plist, dataType *data)
{
	double_node *pinsert_node = malloc(sizeof(double_node));
	if(pinsert_node == NULL)
	{
		perror("malloc");
		return -1;
	}

	memcpy(&pinsert_node->data, data, sizeof(dataType));
	pinsert_node->pPre = NULL;
	pinsert_node->pNext = NULL;

	pinsert_node->pNext = plist->phead;
	if(plist->phead != NULL)
	{
		plist->phead->pPre = pinsert_node;
	}
	plist->phead = pinsert_node;
	plist->len++;
	return 0;
}

int is_empty(double_list *plist)
{
	return plist->len == 0;
}

int show_double_link(double_list *plist, int flag)
{
	double_node *pTmpNode = plist->phead;

	if(0 == flag)
	{
		while(pTmpNode != NULL)
		{
			printf("%d %s %d\n", pTmpNode->data.id, pTmpNode->data.name, pTmpNode->data.score);
			pTmpNode = pTmpNode->pNext;
		}
	}
	else if(1 == flag)
	{
		if(is_empty(plist))
		{
			return -1;
		}
		while(pTmpNode->pNext != NULL)
		{
			pTmpNode = pTmpNode->pNext;	
		}
		while(pTmpNode != NULL)
		{
			printf("%d %s %d\n", pTmpNode->data.id, pTmpNode->data.name, pTmpNode->data.score);
			pTmpNode = pTmpNode->pPre;
		}
	}
	printf("\n");
}

int tail_insert(double_list *plist, dataType *data)
{
	double_node *pTmpNode = malloc(sizeof(double_node));
	if(NULL == pTmpNode)
	{
		perror("malloc");
		return -1;
	}
	memcpy(&pTmpNode->data, data, sizeof(double_node));
	pTmpNode->pPre = NULL;
	pTmpNode->pNext = NULL;

	if(is_empty(plist))
	{
		plist->phead = pTmpNode;
	}
	else
	{
		double_node *ptmp = plist->phead;
		while(ptmp->pNext != NULL)
		{
			ptmp = ptmp->pNext;
		}
		ptmp->pNext = pTmpNode;
		pTmpNode->pPre = ptmp;
	}
	plist->len++;
	return 0;
}

int head_delete(double_list *plist)
{
	double_node *pTmpNode = plist->phead;
	if(is_empty(plist))
	{
		return -1;
	}
	else if(plist->len == 1)
	{
		free(pTmpNode);
		plist->phead = NULL;
	}
	else
	{
		plist->phead = pTmpNode->pNext;
		free(pTmpNode);
		plist->phead->pPre = NULL;
	}
	plist->len--;
	return 0;
}

int tail_delete(double_list *plist)
{
	double_node *pTmpNode = plist->phead;
	if(is_empty(plist))
	{
		return -1;
	}
	else if(plist->len == 1)
	{
		head_delete(plist);
	}
	else
	{
		while(pTmpNode->pNext->pNext != NULL)
		{
			pTmpNode = pTmpNode->pNext;
		}
		free(pTmpNode->pNext);
		pTmpNode->pNext = NULL;
		plist->len--;
	}
	return 0;
}

void destroy_list(double_list **plist)
{
	while((*plist)->phead != NULL)
	{
		head_delete(*plist);
		//tail_delete(*plist);
	}
	free(*plist);
	*plist = NULL;
}

int main(int argc, const char *argv[])
{
	double_list *plist = NULL;

	dataType stu[5] = {{1, "zhangsan", 90},
		{2, "lisi", 80}, {3, "wanger", 89},
		{4, "zhaowu", 99}, {5, "maliu", 78}};
	plist = creat_double_link();
	
	head_insert(plist, &stu[0]);
	head_insert(plist, &stu[1]);
	head_insert(plist, &stu[2]);
	head_insert(plist, &stu[3]);
	
	show_double_link(plist, 1);
	show_double_link(plist, 0);

	tail_insert(plist, &stu[4]);
	
	show_double_link(plist, 0);

	head_delete(plist);

	show_double_link(plist, 0);

	tail_delete(plist);

	show_double_link(plist, 0);

	destroy_list(&plist);

	return 0;
}
