#include "push_swap.h"

static int	rotate_stack(t_linkedlist *stack)
{
	long	temp;
	long	value;
	t_node	*node;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (0);
	node = stack->head;
	temp = node->content;
	while (node != NULL && node->next!= NULL)
	{
		value = node->next->content;
		node->next->content = temp;
		node->content = value;
		node = node->next;
		temp = node->content;
	}
	return (1);
}

int	ra(t_linkedlist *stack_a)
{
	if (!reverse_stack(stack_a))
		return (0);
	return (1);
}

int	ra(t_linkedlist *stack_a)
{
	if (!reverse_stack(stack_a))
		return (0);
	return (1);
}

int	rr(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	if (!reverse_stack(stack_a) || !reverse_stack(stack_b))
		return (0);
	return (1);
}
