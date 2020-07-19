#include "queue.h"

int main(int argc, const char *argv[])
{
	queue_list *plist = NULL;
	plist = creat_queue();

	enqueue(plist, 1);
	enqueue(plist, 2);
	enqueue(plist, 3);
	
	show_queue(plist);

	leave_queue(plist ,NULL);

	show_queue(plist);

	destroy_queue(&plist);
	return 0;
}
