/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezio <pezio@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:16:07 by pezio             #+#    #+#             */
/*   Updated: 2026/08/22 15:16:26 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_linkedlist *a, t_linkedlist *b, t_ops *ops)
{
	int	n;
	int	chunk_size;
	int	i;

	n = list_len(a);
	chunk_size = get_chunk_size(n);
	i = 0;
	while (!is_list_clean(a))
	{
		if (a->head->index <= i)
		{
			pb(b, a, ops);
			rb(b, ops);
			i++;
		}
		else if (a->head->index <= i + chunk_size)
		{
			pb(b, a, ops);
			i++;
		}
		else
			ra(a, ops);
	}
}

void	chunk_based(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	int	max_pos;
	int	size_b;

	index_stack(stack_a);
	push_chunks_to_b(stack_a, stack_b, ops);
	while (!is_list_clean(stack_b))
	{
		max_pos = get_max_pos(stack_b);
		size_b = list_len(stack_b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, ops);
		}
		else
		{
			while (max_pos++ < size_b)
				rrb(stack_b, ops);
		}
		pa(stack_a, stack_b, ops);
	}
}
