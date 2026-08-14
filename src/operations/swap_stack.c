#include "push_swap.h"

static int	swap_stack(t_linkedlist *stack)
{
	long	temp;
	t_node	*next;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (0);
	temp = stack->head->content;
	next = stack->head->next;
	stack->head->content = next->content;
	next->content = temp;
	return (1);
}

int	sb(t_linkedlist *stack_b)
{
	if (!swap_stack(stack_b))
		return (0);
	return (1);
}

int	sa(t_linkedlist *stack_a)
{
	if (!swap_stack(stack_a))
		return (0);
	return (1);
}

int	ss(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	if (!sa(stack_a) || !sb(stack_b))
		return (0);
	return (1);
}
