#include "push_swap.h"

static void	swap(t_linkedlist *stack, size_t i, size_t min_index)
{
	long	aux;
	t_node	*part1;
	t_node	*part2;

	part1 = get_at(stack, i);
	part2 = get_at(stack, min_index);
	aux = part1->content;
	part1->content = part2->content;
	part2->content = aux;
}

void	selection_sort(t_linkedlist *stack)
{
	size_t	i;
	size_t	n;
	size_t	j;
	size_t	min_index;
	t_node	*node;

	n = list_len(stack);
	i = 0;
	node = stack->head;
	while (i < n - 1)
	{
		j = i;
		min_index = j;
		while (j < n)
		{
			if (get_at(stack, j)->content < get_at(stack, min_index)->content)
				min_index = j;
			j++;
			if (get_at(stack, i) > get_at(stack, min_index))
				swap(stack, i, min_index);
		}
		i++;
	}
}
