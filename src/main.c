#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;

	stack_a = malloc(sizeof(t_linkedlist));
	stack_b = malloc(sizeof(t_linkedlist));
	if (!stack_a && !stack_b)
		return (1);
	linked_init(stack_a);
	handle_inputs(argc, argv, stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
