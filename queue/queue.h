#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>


typedef int dataType;

typedef struct node
{
	dataType data;
	struct node *pNext;
}queue_node;

typedef struct list
{
	queue_node *pFront;
	queue_node *pRear;
	int len;
}queue_list;

extern queue_list *creat_queue();
extern int enqueue(queue_list *plist, dataType data);
extern void show_queue(queue_list *plist);
extern int leave_queue(queue_list *plist, dataType *data);
extern int destroy_queue(queue_list **plist);
#endif
