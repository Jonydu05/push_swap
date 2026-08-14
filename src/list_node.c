#include "push_swap.h"

t_node	*node_init(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = 0;
	node->next = NULL;
	return (node);
}

void	linked_init(t_linkedlist *list)
{
	list->head = NULL;
	list->tail = NULL;
}

int	add_content(t_node	*node, long content)
{
	long max_int = 2147483647;
	long min_int = -2147483648;

	if (content > max_int || content < min_int)
		return (-1);
	node->content = content;
	return (1);
}

t_node	*push_front(t_linkedlist *stack)
{
	t_node	*node;

	node = node_init();
	if (!node)
		return (NULL);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
		return (node);
	}
	node->next = stack->head;
	stack->head = node;
	return (node);
}

void	pop_front(t_linkedlist *stack) // funcao passiva de segmentation fault
{
	t_node	*next;

	next = NULL;
	if (!stack->head)
		return ;
	next = stack->head->next;
	free(stack->head);
	stack->head = next;
}
