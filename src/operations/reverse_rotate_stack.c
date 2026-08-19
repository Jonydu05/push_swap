#include "push_swap.h"

static int	reverse_rotate_stack(t_linkedlist *stack)
{
	t_node	*current;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (0);
	current = stack->head;
	while (current->next != stack->tail)
		current = current->next;
	current->next = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = current;
	return (1);
}

int	rra(t_linkedlist *stack_a, t_ops *ops)
{
	ops->all_ops++;
	ops->rra++;
	ft_putstr_fd("rra\n", 1);
	return (reverse_rotate_stack(stack_a));
}

int	rrb(t_linkedlist *stack_b, t_ops *ops)
{
	ops->all_ops++;
	ops->rrb++;
	ft_putstr_fd("rrb\n", 1);
	return (reverse_rotate_stack(stack_b));
}

int	rrr(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	if (!rra(stack_a, ops) || !rrb(stack_b, ops))
		return (0);
	return (1);
}
