#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_conf	*config;

	config = create_config(argc, argv);
	if (!config)
		return (1);
	handle_inputs(config);

	radix_sort(config->stack_a, config->stack_b, config->ops);
	//chunk_based(config->stack_a, config->stack_b, config->ops);
	//selection_sort(config->stack_a, config->stack_b, config->ops);
	list_print(config->stack_a);
	printf("\n\n%d\n", config->ops->all_ops);
	printf("Pa: %d\n", config->ops->pa);
	printf("Pb: %d\n", config->ops->pb);
	printf("Sa: %d\n", config->ops->sa);
	printf("Sb: %d\n", config->ops->sb);
	printf("Ss: %d\n", config->ops->sb);
	printf("Ra: %d\n", config->ops->ra);
	printf("Rb: %d\n", config->ops->rb);
	printf("Rr: %d\n", config->ops->rr);
	printf("Rra: %d\n", config->ops->rra);
	printf("Rrb: %d\n", config->ops->rrb);
	printf("Rrr: %d\n", config->ops->rrr);
	exit_program(0, config);
	return (0);
}
