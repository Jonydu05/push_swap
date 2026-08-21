#include "push_swap.h"

static int	swap_stack(t_linkedlist *stack)
{
	long	temp_content;
	int		temp_index;
	t_node	*next;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (FALSE);
	next = stack->head->next;
	temp_content = stack->head->content;
	temp_index = stack->head->index;
	stack->head->content = next->content;
	stack->head->index = next->index;
	next->content = temp_content;
	next->index = temp_index;
	return (TRUE);
}

int	sb(t_linkedlist *stack_b, t_ops *ops)
{
	ops->all_ops++;
	ops->sb++;
	ft_putstr_fd("sb\n", 1);
	return (swap_stack(stack_b));
}

int	sa(t_linkedlist *stack_a, t_ops *ops)
{
	ops->all_ops++;
	ops->sa++;
	ft_putstr_fd("sa\n", 1);
	return (swap_stack(stack_a));
}

int	ss(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	if (!sa(stack_a, ops) || !sb(stack_b, ops))
		return (0);
	return (1);
}
