#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_conf	*config;

	config = create_config();
	handle_inputs(argc, argv, config);
	exit_program(0, config);
	return (0);
}
