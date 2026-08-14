#include "push_swap.h"

int	pb(t_linkedlist *stack_b, t_linkedlist *stack_a)
{
	long	temp;

	if (is_list_clean(stack_a))
		return (0);
	temp = stack_a->head->content;
	pop_front(stack_a);
	add_content(push_front(stack_b), temp);
	return (1);
}
