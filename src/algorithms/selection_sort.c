#include "push_swap.h"

//void	selection_sort(t_linkedlist *stack_a, t_linkedlist *stack_b)
//{
//	long	min_content;
//	t_node	*node;
//	t_node	*j_node;
//
//	node = stack_a->head;
//	while (node != NULL)
//	{
//		min_content = node->content;
//		j_node = node;
//		while (j_node != NULL)
//		{
//			if (j_node->content < get_by_content(stack_a, min_content)->content)
//				min_content = j_node->content;
//			j_node = j_node->next;
//		}
//		while (stack_a->head->content != get_by_content(stack_a, min_content)->content)
//			ra(stack_a);
//		node = node->next;
//		pb(stack_b, stack_a);
//	}
//	// desempilhar
//	node = stack_b->head;
//	while (node != NULL)
//	{
//		node = node->next;
//		pa(stack_a, stack_b);
//	}
//}

void	selection_sort(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	long	min_content;
	t_node	*node;
	t_node	*j_node;

	node = stack_a->head;
	while (node != NULL)
	{
		if (stack_a->head->content > stack_a->head->next->content)
		{
			sa(stack_a);
			break ;
		}
		min_content = node->content;
		j_node = node;
		while (j_node != NULL)
		{
			if (j_node->content < get_by_content(stack_a, min_content)->content)
				min_content = j_node->content;
			j_node = j_node->next;
		}
		while (stack_a->head->content != get_by_content(stack_a, min_content)->content)
			ra(stack_a);
		node = node->next;
		pb(stack_b, stack_a);
	}
	node = stack_b->head;
	while (node != NULL)
	{
		node = node->next;
		pa(stack_a, stack_b);
	}
}
