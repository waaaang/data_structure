#ifndef __LINK_H__
#define __LINK_H__

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
	DataType Data;
	struct node * pNext;
}LinkNode;

typedef struct list
{
	LinkNode *pHead;
	int cLen;
}LinkList;



#endif
