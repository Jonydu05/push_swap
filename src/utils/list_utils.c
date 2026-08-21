#include "push_swap.h"
#include <stdio.h>

void	list_print(t_linkedlist *list) // TEMP FUNCTION
{
	t_node	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		printf("%ld\n", temp->content);
		temp = temp->next;
	}
}

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
