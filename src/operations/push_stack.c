#include "push_swap.h"

static int	push_stack(t_linkedlist *stack_base, t_linkedlist *stack_get)
{
	long	temp;

	if (is_list_clean(stack_get))
		return (0);
	temp = stack_get->head->content;
	pop_front(stack_get);
	add_content(push_front(stack_base), temp);
	return (1);
}

int	pa(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	if (!push_stack(stack_a, stack_b))
		return (0);
	return (1);
}

int	pb(t_linkedlist *stack_b, t_linkedlist *stack_a)
{
	if (!push_stack(stack_b, stack_a))
		return (0);
	return (1);
}
