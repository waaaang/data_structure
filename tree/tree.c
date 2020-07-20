#include "tree.h"

char tree[] = "ABDG###E#H##CF###";
int idx = 0;

bt_node *create_bin_tree()
{
	bt_node *pnode = NULL;
	char ch = tree[idx++];
	if(ch == '#')
	{
		return NULL;
	}
	else
	{
		pnode = malloc(sizeof(bt_node));
		if(NULL == pnode)
		{
			perror("malloc pnode");
			return NULL;
		}
		pnode->data = ch;
		pnode->pLeft = create_bin_tree();
		pnode->pRight = create_bin_tree();
	}
	return pnode;
}

void preOrder(bt_node *pRoot)
{
	if(NULL == pRoot)
	{
		return ;
	}
	else
	{
		printf("%c", pRoot->data);
		fflush(stdout);
		preOrder(pRoot->pLeft);
		preOrder(pRoot->pRight);
	}

}

void midOrder(bt_node *pRoot)
{
	if(NULL == pRoot)
	{
		return ;
	}
	else
	{
		midOrder(pRoot->pLeft);
		printf("%c", pRoot->data);
		fflush(stdout);
		midOrder(pRoot->pRight);
	}
}

void rearOrder(bt_node *pRoot)
{
	if(NULL == pRoot)
	{
		return ;
	}
	else
	{
		rearOrder(pRoot->pLeft);
		rearOrder(pRoot->pRight);
		printf("%c", pRoot->data);
		fflush(stdout);
	}
}

int tree_node_num(bt_node *pRoot)
{
	int left_node_num = 0;
	int right_node_num = 0;

	if(NULL == pRoot)
	{
		return 0;
	}
	else
	{
		left_node_num = tree_node_num(pRoot->pLeft);
		right_node_num = tree_node_num(pRoot->pRight);
	}
	return left_node_num + right_node_num + 1;
}

void destroy_tree(bt_node **pRoot)
{
	if(NULL == (*pRoot))
	{
		return ;
	}
	else
	{
		destroy_tree(&(*pRoot)->pLeft);
		destroy_tree(&(*pRoot)->pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}
