#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TLIB_DOUBLE_LINKED_LIST
#define TLIB_DOUBLE_LINKED_LIST

//data
struct tt_node
{
	void *last;
	void *next;
	void *data; //pointer to some data that is organized by the list
} typedef tt_node;

//functions
//returns NULL if reached the end of the list
tt_node* tt_list_next_node(tt_node *current_node);

tt_node* tt_list_last_node(tt_node *current_node);

//creates a new node after the current one
tt_node* tt_list_new_node(tt_node *current_node);

void tt_list_remove_node(tt_node **current_node);

void tt_list_node_set_data(tt_node *current_node, void *data);

#endif /* TLIB_DOUBLE_LINKED_LIST */

//implementation
#ifdef TLIB_DOUBLE_LINKED_LIST_IMPLEMENTATION

#include <stdlib.h>

//returns NULL if reached the end of the list
tt_node* tt_list_next_node(tt_node *current_node)
{
	return current_node->next;
}

tt_node* tt_list_last_node(tt_node *current_node)
{
	if(!current_node->last)
	{
		return current_node;
	}
	return current_node->last;
}

//creates a new node after the current one
tt_node* tt_list_new_node(tt_node *current_node)
{
	tt_node *node=NULL;
	node=malloc(sizeof(tt_node));
	node->data=NULL;

	//if there is no current node yet (NULL as input)
	if(!current_node)
	{
		tt_node *node=malloc(sizeof(tt_node));
		node->last=NULL;
		node->next=NULL;
		node->data=NULL;
		return node;		
	}

	//if current last node
	if(!current_node->next && current_node->last)
	{
		current_node->next=node;
		node->next=NULL;
		node->last=current_node;
		return node;
	}

	//if current first node
	if(!current_node->next && !current_node->last)
	{
		node->last=current_node;
		current_node->next=node;
		node->next=NULL;
		return node;
	}

	//if current node is in between other nodes
	node->next=current_node->next;
	current_node->next=node;
	node->last=current_node;
	tt_node *following=node->next;
	following->last=node;
	return node;
}

//moves current node to the next node after deletion
//becomes NULL if there are no nodes left
void tt_list_remove_node(tt_node **current_node)
{
	tt_node *node;

	//if first node
	if(!(*current_node)->last && (*current_node)->next)
	{
		node=(*current_node)->next;
		node->last=NULL;
		free(*current_node);
		*current_node=node;
		return;
	}

	//if sole node
	if(!(*current_node)->last && !(*current_node)->next)
	{
		node=NULL;
		free(*current_node);
		(*current_node)=NULL;
		return;
	}

	//if last node
	if((*current_node)->last && !(*current_node)->next)
	{
		node=(*current_node)->last;
		node->next=NULL;
		free(*current_node);
		*current_node=node;
		return;
	}

	//if it's a node in between
	node=(*current_node)->last;
	node->next=(*current_node)->next;
	node=(*current_node)->next;
	node->last=(*current_node)->last;
	node=(*current_node)->last;
	free(*current_node);
	*current_node=node->next;
	return;
}

void tt_list_node_set_data(tt_node *current_node, void *data)
{
	current_node->data=data;
}

#endif /* TLIB_DOUBLE_LINKED_LIST_IMPLEMENTATION */

#ifdef __cplusplus
}
#endif /* __cplusplus */