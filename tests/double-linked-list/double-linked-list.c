#define TLIB_DOUBLE_LINKED_LIST_IMPLEMENTATION
#include "Tlib/list.h"

#include <stdio.h>

int main(void)
{
	//creating an initial node
	printf("creating an initial node: ");
	T_node *node0 = T_list_new_node(NULL);

	if(node0)
	{
		printf("successful\n");
	}
	else
	{
		printf("failure\n");
	}


	//creating a node at the end of the list
	printf("creating an end node: ");
	T_node *node1 = T_list_new_node(node0);

	if(node1)
	{
		printf("successful\n");
	}
	else
	{
		printf("failure\n");
	}


	//creating a node in the middle of the list
	printf("creating a node in the middle of the list: ");
	T_node *node2 = T_list_new_node(node0);

	if(node2)
	{
		printf("successful\n");
	}
	else
	{
		printf("failure\n");
	}
	return 0;
}