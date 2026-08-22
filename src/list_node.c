/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezio <pezio@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:17:57 by pezio             #+#    #+#             */
/*   Updated: 2026/08/22 15:18:18 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = 0;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	linked_init(t_linkedlist *list)
{
	list->head = NULL;
	list->tail = NULL;
}

int	add_content(t_node	*node, long content)
{
	node->content = content;
	return (TRUE);
}

t_node	*push_front(t_linkedlist *stack)
{
	t_node	*node;

	node = node_init();
	if (!node)
		return (NULL);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
		return (node);
	}
	node->next = stack->head;
	stack->head = node;
	return (node);
}

void	pop_front(t_linkedlist *stack)
{
	t_node	*next;

	if (!stack || !stack->head)
		return ;
	next = stack->head->next;
	free(stack->head);
	stack->head = next;
	if (!stack->head)
		stack->tail = NULL;
}
