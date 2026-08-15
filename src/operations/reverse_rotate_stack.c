#include "push_swap.h"

static int	reverse_rotate_stack(t_linkedlist *stack)
{
	long	temp;
	t_node	*node;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (0);
	node = stack->head;
	while (node != NULL && node->next!= NULL)
	{
		temp = stack->tail->content;
		stack->tail->content = node->content;
		node->content = temp;
		node = node->next;
	}
	return (1);
}

int	rra(t_linkedlist *stack_a)
{
	if (!reverse_rotate_stack(stack_a))
		return (0);
	return (1);
}

int	rrb(t_linkedlist *stack_b)
{
	if (!reverse_rotate_stack(stack_b))
		return (0);
	return (1);
}

int	rrr(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	if (!reverse_rotate_stack(stack_a) || !reverse_rotate_stack(stack_b))
		return (0);
	return (1);
}
