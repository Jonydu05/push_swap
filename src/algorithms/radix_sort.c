#include "push_swap.h"

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
