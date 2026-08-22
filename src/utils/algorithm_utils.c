/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezio <pezio@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:24:37 by pezio             #+#    #+#             */
/*   Updated: 2026/08/22 15:24:54 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_chunk_size(int n)
{
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (35);
	return (n / 10);
}

int	get_max_pos(t_linkedlist *stack_b)
{
	t_node	*curr;
	int		max_idx;
	int		max_pos;
	int		curr_pos;

	curr = stack_b->head;
	max_idx = curr->index;
	max_pos = 0;
	curr_pos = 0;
	while (curr)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			max_pos = curr_pos;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (max_pos);
}
