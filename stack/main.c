#include "stack.h"


int main(int argc, const char *argv[])
{
	stackList *plist = NULL;
	
	plist = create_stack();

	stack_push(plist, 1);
	stack_push(plist, 2);
	stack_push(plist, 3);
	stack_push(plist, 4);
	stack_push(plist, 5);
	stack_push(plist, 6);

	stack_show(plist);

	//stack_pop(plist, NULL);

	//stack_show(plist);

	dataType data = 0;
	data = stack_top_element(plist);
	printf("%d\n", data);

	destroy_stack(&plist);
	return 0;
}
