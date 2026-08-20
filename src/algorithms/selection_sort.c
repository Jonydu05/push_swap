#include "push_swap.h"

static void	otimization_three(t_linkedlist *stack_a, t_ops *ops)
{
	int	top;
	int	medium;
	int	down;

	top = stack_a->head->index;
	medium = stack_a->head->next->index;
	down = stack_a->tail->index;
	if (top > medium && medium > down)
	{
		sa(stack_a, ops);
		rra(stack_a, ops);
	}
	else if (top > medium && top > down && medium < down)
		ra(stack_a, ops);
	else if (top > medium && top < down)
		sa(stack_a, ops);
	else if (top < medium && top < down && medium > down)
	{
		sa(stack_a, ops);
		ra(stack_a, ops);
	}
	else if (top < medium && top > down)
		rra(stack_a, ops);
}

static int	choicer_op(t_linkedlist *stack_a, t_ops *ops)
{
	if (list_len(stack_a) == 2)
	{
		if (stack_a->head->index > stack_a->head->next->index)
			sa(stack_a, ops);
		return (TRUE);
	}
	if (list_len(stack_a) == 3)
	{
		otimization_three(stack_a, ops);
		return (TRUE);
	}
	return (FALSE);
}

static void	push_all(t_linkedlist *a, t_linkedlist *b, t_ops *ops)
{
	while (b->head != NULL)
		pa(a, b, ops);
}

static void	move_min_to_top(t_linkedlist *a, int min_index, t_ops *ops)
{
	t_node	*curr;
	int		pos;
	int		len;

	pos = 0;
	curr = a->head;
	while (curr && curr->index != min_index)
	{
		pos++;
		curr = curr->next;
	}
	len = list_len(a);
	if (pos <= len / 2)
	{
		while (a->head->index != min_index)
			ra(a, ops);
	}
	else
	{
		while (a->head->index != min_index)
			rra(a, ops);
	}
}

void	selection_sort(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	t_node	*node;
	int		min_index;

	index_stack(stack_a);
	while (list_len(stack_a) > 3)
	{
		if (choicer_op(stack_a, ops))
			break ;
		node = stack_a->head;
		min_index = node->index;
		while (node != NULL)
		{
			if (node->index < min_index)
				min_index = node->index;
			node = node->next;
		}
		move_min_to_top(stack_a, min_index, ops);
		pb(stack_b, stack_a, ops);
	}
	choicer_op(stack_a, ops);
	push_all(stack_a, stack_b, ops);
}
