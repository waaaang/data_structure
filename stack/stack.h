#ifndef __STACK_H__
#define __STACK_H__


#include <stdio.h>
#include <stdlib.h>


typedef int dataType;

typedef struct node
{
	dataType data;
	struct node *pNext;
}stackNode;

typedef struct list
{
	stackNode *pTop;
	int len;
}stackList;


extern stackList *create_stack();
extern void stack_show(stackList *plist);
extern int stack_push(stackList *plist, dataType data);
extern int is_empty(stackList *plist);
extern int stack_pop(stackList *plist, dataType *data);
extern dataType stack_top_element(stackList *plist);
extern void clear_stack(stackList *plist);
extern void destroy_stack(stackList **plist);
#endif
