#include "push_swap.h"

static int	push_stack(t_linkedlist *stack_base, t_linkedlist *stack_get)
{
	t_node	*new_node;

	if (is_list_clean(stack_get))
		return (FALSE);
	new_node = push_front(stack_base);
	if (!new_node)
		return (FALSE);
	new_node->content = stack_get->head->content;
	new_node->index = stack_get->head->index;
	pop_front(stack_get);
	return (TRUE);
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
