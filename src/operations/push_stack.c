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

int	pa(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	ops->pa++;
	ops->all_ops++;
	ft_putstr_fd("pa\n", 1);
	return (push_stack(stack_a, stack_b));
}

int	pb(t_linkedlist *stack_b, t_linkedlist *stack_a, t_ops *ops)
{
	ops->pb++;
	ops->all_ops++;
	ft_putstr_fd("pb\n", 1);
	return (push_stack(stack_b, stack_a));
}
