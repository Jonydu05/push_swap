#include "push_swap.h"

static void	otimization_three(t_linkedlist *stack_a, t_ops *ops)
{
	int	top;
	int	medium;
	int	down;

	top = stack_a->head->content;
	medium = stack_a->head->next->content;
	down = stack_a->tail->content;
	if (top > medium && medium > down)
	{
		sa(stack_a, ops);
		rra(stack_a, ops);
	}
	else if (top > medium && top > down && medium < down)
		ra(stack_a, ops);
	else if (top > medium && top < down)
		sa(stack_a, ops);
	else if (top < medium && top < down && medium > down)
	{
		sa(stack_a, ops);
		ra(stack_a, ops);
	}
	else if (top < medium && top > down)
		rra(stack_a, ops);
}

static int	choicer_op(t_linkedlist *stack_a, t_ops *ops)
{
	if (list_len(stack_a) == 2)
	{
		sa(stack_a, ops);
		return (TRUE);
	}
	if (list_len(stack_a) == 3)
	{
		otimization_three(stack_a, ops);
		return (TRUE);
	}
	return (FALSE);
}

static void	push_all(t_linkedlist *a, t_linkedlist *b, t_node *n, t_ops *ops)
{
	n = b->head;
	while (n != NULL)
	{
		n = n->next;
		pa(a, b, ops);
	}
}

static void	move_content_to_peek(t_linkedlist *a, long *min_cont, t_ops *ops)
{
	while (a->head->content != get_by_content(a, *min_cont)->content)
		rra(a, ops);
}

void	selection_sort(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops)
{
	long	min_content;
	t_node	*node;
	t_node	*j_node;

	node = stack_a->head;
	while (node != NULL)
	{
		if (choicer_op(stack_a, ops))
			break ;
		min_content = node->content;
		j_node = node;
		while (j_node != NULL)
		{
			if (j_node->content < get_by_content(stack_a, min_content)->content)
				min_content = j_node->content;
			j_node = j_node->next;
		}
		move_content_to_peek(stack_a, &min_content, ops);
		node = node->next;
		pb(stack_b, stack_a, ops);
	}
	push_all(stack_a, stack_b, node, ops);
}
