#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_linkedlist	*stack;

	stack = malloc(sizeof(t_linkedlist));
	if (!stack)
		return (1);
	linked_init(stack);
	add_content(push_front(stack), 1); // tail
	add_content(push_front(stack), 2); // middle node
	add_content(push_front(stack), 3); // head
	list_print(stack);
	pop_front(stack); // 2 head
	list_print(stack);
	return (0);
}
