/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezio <pezio@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:24:08 by pezio             #+#    #+#             */
/*   Updated: 2026/08/22 15:24:25 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_linkedlist *list)
{
	t_node	*temp;
	int		size;

	size = 0;
	temp = list->head;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	is_list_clean(t_linkedlist *list)
{
	int	size;

	size = list_len(list);
	if (size)
		return (FALSE);
	return (TRUE);
}

int	is_list_one_node(t_linkedlist *list)
{
	t_node	*next;

	next = list->head->next;
	if (next)
		return (FALSE);
	return (TRUE);
}

t_node	*get_by_content(t_linkedlist *list, long content)
{
	t_node	*node;

	node = list->head;
	while (node != NULL && node->content != content)
		node = node->next;
	return (node);
}
