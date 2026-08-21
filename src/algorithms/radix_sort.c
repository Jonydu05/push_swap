#include "push_swap.h"

static void	impar_based(t_linkedlist *a, t_linkedlist *b, int bit, t_ops *ops)
{
	if (((a->head->index >> bit) & 1) == 1)
		ra(a, ops);
	else
		pb(b, a, ops);
}

static void	force_pa(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	while (!is_list_clean(stack_b))
		pa(stack_a, stack_b, ops);
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
			impar_based(stack_a, stack_b, bit, ops);
			i++;
		}
		force_pa(stack_a, stack_b, ops);
		if (is_sorted(stack_a))
			break ;
		bit++;
	}
}
