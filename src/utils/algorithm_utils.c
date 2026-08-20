#include "push_swap.h"

void	index_stack(t_linkedlist *stack_a)
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

int	is_sorted(t_linkedlist *stack)
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

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}
