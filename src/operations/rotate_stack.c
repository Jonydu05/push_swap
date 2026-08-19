#include "push_swap.h"

static int rotate_stack(t_linkedlist *stack)
{
    t_node *first;

    if (is_list_clean(stack) || is_list_one_node(stack))
        return (0);

    first = stack->head;
    stack->head = first->next; // O segundo vira o topo
    first->next = NULL;

    stack->tail->next = first; // O antigo topo vai para o fim
    stack->tail = first;       // Atualiza a tail
    return (1);
}

int	ra(t_linkedlist *stack_a)
{
	ft_putstr_fd("ra\n", 1);
	return (rotate_stack(stack_a));
}

int	rb(t_linkedlist *stack_b)
{
	ft_putstr_fd("rb\n", 1);
	return (rotate_stack(stack_b));
}

int	rr(t_linkedlist *stack_a, t_linkedlist *stack_b)
{
	if (!ra(stack_a) || !rb(stack_b))
		return (0);
	return (1);
}
