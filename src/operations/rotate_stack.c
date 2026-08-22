/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezio <pezio@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:20:09 by pezio             #+#    #+#             */
/*   Updated: 2026/08/22 15:20:25 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_linkedlist *stack)
{
	t_node	*first;

	if (is_list_clean(stack) || is_list_one_node(stack))
		return (FALSE);
	first = stack->head;
	stack->head = first->next;
	first->next = NULL;
	stack->tail->next = first;
	stack->tail = first;
	return (TRUE);
}

int	ra(t_linkedlist *stack_a, t_ops *ops)
{
	ops->all_ops++;
	ops->ra++;
	ft_putstr_fd("ra\n", 1);
	return (rotate_stack(stack_a));
}

int	rb(t_linkedlist *stack_b, t_ops *ops)
{
	ops->all_ops++;
	ops->rb++;
	ft_putstr_fd("rb\n", 1);
	return (rotate_stack(stack_b));
}

int	rr(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	if (!ra(stack_a, ops) || !rb(stack_b, ops))
		return (FALSE);
	return (TRUE);
}
