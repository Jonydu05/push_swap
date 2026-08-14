#include "push_swap.h"

int	pa(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	long	temp;

	if (is_list_clean(stack_b))
		return (0);
	temp = stack_b->head->content;
	pop_front(stack_b);
	add_content(push_front(stack_a), temp);
	return (1);
}
