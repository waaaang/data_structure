#ifndef __DOUBLE_LINK__
#define __DOUBLE_LINK__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
	int id;
	char name[32];
	int score;
}dataType;

typedef struct node
{
	dataType data;
	struct node *pPre;
	struct node *pNext;
}double_node;

typedef struct list
{
	double_node *phead;
	int len;
}double_list;


#endif
