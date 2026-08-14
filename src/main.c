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
	add_content(push_front(stack), 1); // tail: 0x1
	add_content(push_front(stack), 2); // middle: 0x2
	add_content(push_front(stack), 3); // head: 0x3
	list_print(stack);
	pop_front(stack); // head: 0x2
	list_print(stack);
	// Esse codigo de teste causa naturalmente 2 leaks propositas, por conta
	// Da nao liberacao dos dois nodes via pop
	free(stack);
	return (0);
}
