#define TLIB_DOUBLE_LINKED_LIST_IMPLEMENTATION
#include "Tlib/list.h"

#include <stdio.h>

#define MAGIC_NUMBER 666

int main(void)
{
	//creating an initial node
	printf("creating an initial node: \n");
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
	printf("creating an end node: \n");
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
	printf("creating nodes in the middle of the list: \n");
	T_node *node2 = T_list_new_node(node0);
	T_node *node3 = T_list_new_node(node0);
	T_node *node4 = T_list_new_node(node0);

	if(node2 && node3 && node4)
	{
		printf("successful\n");
	}
	else
	{
		printf("failure\n");
	}

	//testing setting and getting data
	printf("setting and retrieving data: \n");
	int *a = malloc(sizeof(int));
	if(a)
	{
		*a = MAGIC_NUMBER;
	}
	else
	{
		printf("failed\n malloc didn't work\n");
		return 0;
	}

	T_list_node_set_data(node0, a);
	int *b = T_list_node_get_data(node0);
	if(*b == *a)
	{
		printf("successful\n");
	}

	//test moving nodes around
	printf("move a regular node to a regular other place in the list: \n");
	T_list_move_node_after(node4, node3);
	printf("successful\n"); //no segfault

	printf("move the first node after the second node: \n");
	T_list_move_node_after(node0, node3);
	printf("successful\n"); //no segfault

	printf("move a regular node after the last node: \n");
	T_list_move_node_after(node2, node1);
	printf("successful\n"); //no segfault
	return 0;
}