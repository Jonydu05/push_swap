#include "push_swap.h"
#include <stdio.h>

static int	is_sorted(t_linkedlist *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (TRUE);
	current = stack->head;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

static void	index_stack(t_linkedlist *stack_a)
{
	t_node	*curr;
	t_node	*comp;
	int		rank;

	curr = stack_a->head;
	while (curr)
	{
		rank = 0;
		comp = stack_a->head;
		while (comp)
		{
			if (comp->content < curr->content)
				rank++;
			comp = comp->next;
		}
		curr->index = rank;
		curr = curr->next;
	}
}

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	index_stack(stack_a);
	if (is_sorted(stack_a))
		return ;
	size = list_len(stack_a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((stack_a->head->index >> bit) & 1) == 1)
				ra(stack_a, ops);
			else
				pb(stack_b, stack_a, ops);
			i++;
		}
		while (!is_list_clean(stack_b))
			pa(stack_a, stack_b, ops);
		if (is_sorted(stack_a))
			break ;
		bit++;
	}
}
