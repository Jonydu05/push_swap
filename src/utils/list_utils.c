#include "push_swap.h"
#include <stdio.h> // temporery

void	list_print(t_linkedlist *list) // funcao temporaria
{
	t_node	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		printf("%ld\n", temp->content); // temporario
		temp = temp->next;
	}
}

int	list_len(t_linkedlist *list)
{
	t_node	*temp;

	int	size;

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
	int	size = list_len(list);
	if (size)
		return (0);
	return (1);
}

int	is_list_one_node(t_linkedlist *list)
{
	t_node	*next;

	next = list->head->next;
	if (next)
		return (0);
	return (1);
}

t_node	*get_at(t_linkedlist *list, size_t index)
{
	t_node	*node;
	size_t	i;

	node = list->head;
	i = 0;
	while (i < index && node != NULL)
	{
		node = node->next;
		i++;
	}
	return (node);
}

t_node	*get_by_content(t_linkedlist *list, long content)
{
	t_node	*node;

	node = list->head;
	while (node != NULL && node->content != content)
		node = node->next;
	return (node);
}

void	clear_stack(t_linkedlist *stack)
{
	t_node	*head;
	t_node	*next;

	head = stack->head;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(stack);
}

t_conf	*create_config(void)
{
	t_conf			*config;
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	
	stack_a = malloc(sizeof(t_linkedlist));
	stack_b = malloc(sizeof(t_linkedlist));
	if (!stack_a && !stack_b)
		return (NULL);
	linked_init(stack_a);
	linked_init(stack_b);
	config = malloc(sizeof(t_conf));
	if (!config)
		return (NULL);
	config->stack_a = stack_a;
	config->stack_b = stack_b;
	return (config);
}
