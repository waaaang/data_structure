#include "seq_queue.h"

seq_que *creat_seq_queue()
{
	seq_que *pQue = malloc(sizeof(seq_que));
	if(NULL == pQue)
	{
		perror("malloc pQue");
		return NULL;
	}

	pQue->front = 0;
	pQue->rear = 0;
	pQue->pbase = malloc(sizeof(dataType) * QUE_MAX_SIZE);
	if(NULL == pQue->pbase)
	{
		perror("malloc pQue->pbase");
		return NULL;
	}

	return pQue;
}

int is_full(seq_que *pQue)
{
	return (pQue->rear + 1) % QUE_MAX_SIZE == pQue->front;
}

int is_empty(seq_que *pQue)
{
	return pQue->rear == pQue->front;
}

void show_seq_queue(seq_que *pQue)
{
	int i = 0;
	for(i = pQue->front; i < pQue->rear; ++i)
	{
		printf("%d ", pQue->pbase[i]);
	}
	printf("\n");
}

int seq_enqueue(seq_que *pQue, dataType data)
{
	if(is_full(pQue))
	{
		return -1;
	}
	else
	{
		pQue->pbase[pQue->rear] = data;
		pQue->rear++;
		if((pQue->rear) % QUE_MAX_SIZE == 0)
		{
			pQue->rear = 0;
		}
	}
	return 0;
}

int leave_seq_queue(seq_que *pQue, dataType *data)
{
	if(is_empty(pQue))
	{
		return -1;
	}
	else
	{
		if(data != NULL)
		{
			*data = pQue->pbase[pQue->front];
		}
		pQue->front++;
		if((pQue->front) % QUE_MAX_SIZE == 0)
		{
			pQue->front = 0;
		}
	}
	return 0;
}

int get_seq_queue_len(seq_que *pQue)
{
	return (pQue->rear - pQue->front + QUE_MAX_SIZE) % QUE_MAX_SIZE;
}

void destroy_seq_queue(seq_que **pQue)
{
	free((*pQue)->pbase);
	free(*pQue);
	*pQue = NULL;
}


int main(int argc, const char *argv[])
{
	seq_que *pQue = NULL;
	pQue = creat_seq_queue();

	int i = 0;
	for(i = 0; i < 10; ++i)
	{
		seq_enqueue(pQue, i);
	}
	show_seq_queue(pQue);

	leave_seq_queue(pQue, NULL);
	show_seq_queue(pQue);


	printf("len = %d\n", get_seq_queue_len(pQue));

	destroy_seq_queue(&pQue);
	return 0;
}
