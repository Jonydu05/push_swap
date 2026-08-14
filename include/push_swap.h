#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Unistd.h included functions read, write
# include <unistd.h>
# include "../libft/libft.h"

// Stdlib.h included functions malloc, free and exit
# include <stdlib.h>

typedef struct s_node
{
	long			content;
	struct s_node	*next;
}	t_node;

typedef struct s_linked
{
	t_node	*head;
	t_node	*tail;
}	t_linkedlist;

// Functions of list_node.c

/**
* @brief This function make a safe initialize linked list type
*
* @param list A pointer variable type t_linkedlist
*
* @return Void
*/
void			linked_init(t_linkedlist *list);

/**
* @brief This function make a safe initialize node type
*
* @return Return pointer of node allocated
*/
t_node			*node_init(void);

/**
* @brief This function push a new node to first position in a stack structury
*
* @param stack The stack is a pointer of t_linkedlist type
*
* @return Return pointer of new node allocated case fail return NULL
*/
t_node			*push_front(t_linkedlist *stack);

/**
* @brief This function make safe delete of node
*
* @param stack The stack is a pointer of t_linkedlist type
*
* @return Void
*/
void			pop_front(t_linkedlist *stack);

/**
* @brief This function add new value content of pointed node t_node type
*
* The function NOT accept value number passed the INT_MAX or INT_MIN

* @param node The node is a pointer of t_node typr
* @param content The content is a value decimal long type
*
* @return Returned a integer boolean one to valid content or zero to invalid content
*/
int				add_content(t_node *node, long content);

// Functions of list_utils.c

/**
* @brief This function printed using a printf function the content of nodes
*
* @param list A pointer variable type t_linkedlist
*
* @return Void
*/
void	list_print(t_linkedlist *list);

/**
* @brief This function count number of nodes in linked list
*
* @param list A pointer variable of t_linkedlist type
*/
int		list_len(t_linkedlist *list);

/**
* @brief This function verify if the linked list is clean
*
* @param list A variable pointer of t_linkedlist type
*
* @return Return one if is clean of nodes or zero if is false
*/
int		is_list_clean(t_linkedlist *list);

/**
* @brief This function verify if the linked list have one content
*
* @param list A variable pointer of t_linkedlist type
*
* @return Return one if have one node  or zero if is false
*/
int		is_list_one_node(t_linkedlist *list);

// Operations to use stack

int	pa(t_linkedlist *stack_a, t_linkedlist *stack_b);
int	pb(t_linkedlist *stack_b, t_linkedlist *stack_a);
int	sa(t_linkedlist *stack_a);
int	sb(t_linkedlist *stack_b);
int	ss(t_linkedlist *stack_a, t_linkedlist *stack_b);

#endif
