#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_conf	*config;

	config = create_config(argc, argv);
	if (!config)
		return (1);
	handle_inputs(config);

	// Executa o algoritmo Radix Sort
	radix_sort(config->stack_a, config->stack_b);
	list_print(config->stack_a);
	exit_program(0, config);
	return (0);
}
