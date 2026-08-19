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
		if (current->content > current->next->content)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

static void	index_stack(t_linkedlist *stack_a)
{
	t_node	*curr;
	t_node	*comp;
	int		*indices;
	int		size;
	int		i;

	size = list_len(stack_a);
	indices = ft_calloc(size, sizeof(int));
	if (!indices)
		return ;
	curr = stack_a->head;
	i = 0;
	while (curr)
	{
		comp = stack_a->head;
		while (comp)
		{
			if (comp->content < curr->content)
				indices[i]++;
			comp = comp->next;
		}
		curr = curr->next;
		i++;
	}
	curr = stack_a->head;
	i = 0;
	while (curr)
	{
		printf("Value: %ld\n", curr->content); // view
		curr->content = indices[i];
		printf("Index: %ld\n", curr->content);
		curr = curr->next;
		i++;
	}
	free(indices);
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
	size = list_len(stack_a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((stack_a->head->content >> bit) & 1) == 1)
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
