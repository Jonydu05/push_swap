#include "push_swap.h"

void exit_program(int exit_code, t_conf *config)
{
	clear_stack(config->stack_a);
	clear_stack(config->stack_b);
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
