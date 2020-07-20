#ifndef __TREE_H__
#define __TREE_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
	char data;
	struct node *pLeft;
	struct node *pRight;
}bt_node;

extern bt_node *create_bin_tree();
extern void preOrder(bt_node *pRoot);
extern void midOrder(bt_node *pRoot);
extern void rearOrder(bt_node *pRoot);
extern int tree_node_num(bt_node *pRoot);
extern void destroy_tree(bt_node **pRoot);
#endif
