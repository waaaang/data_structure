#ifndef __SEQ_QUEUE_H__
#define __SEQ_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define QUE_MAX_SIZE  10

typedef int dataType;

typedef struct que
{
	dataType *pbase;
	int front;
	int rear;
}seq_que;


#endif
