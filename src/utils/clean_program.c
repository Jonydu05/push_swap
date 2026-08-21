#include "push_swap.h"

void	clear_list(t_linkedlist *stack)
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

void	clear_config(t_conf *config)
{
	clear_list(config->stack_a);
	clear_list(config->stack_b);
	free(config->ops);
	free(config);
}

void exit_program(int exit_code, t_conf *config)
{
	clear_config(config);
	if (exit_code == 0)
		exit(0);
	if (exit_code == 1)
	{
		ft_putstr_fd("Error: Invalid Input List\n", 2);
		exit(1);
	}
	if (exit_code == 2)
	{
		ft_putstr_fd("Error: Invalid Input Flags\n", 2);
		exit(2);
	}
	if (exit_code == 3)
	{
		ft_putstr_fd("Error: Unknown error\n", 3);
		exit(3);
	}
}
