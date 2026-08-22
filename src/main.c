#include "push_swap.h"

float	compute_disorder(t_conf *config)
{
	t_node	*current;
	t_node	*runner;
	int		mistakes;
	int		total_pairs;

	if (!config || !config->stack_a || !config->stack_a->head
		|| !config->stack_a->head->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = config->stack_a->head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content > runner->content)
				mistakes++;
			total_pairs++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

void	handle_adaptive(t_conf *config)
{
	int	len;

	len = list_len(config->stack_a);
	if (len <= 5)
		selection_sort(config->stack_a, config->stack_b, config->ops);
	else if (len <= 100)
	{
		if (config->disorder < 0.1)
			selection_sort(config->stack_a, config->stack_b, config->ops);
		else
			chunk_based(config->stack_a, config->stack_b, config->ops);
	}
	else
	{
		if (config->disorder < 0.1)
			selection_sort(config->stack_a, config->stack_b, config->ops);
		else if (config->disorder < 0.4)
			chunk_based(config->stack_a, config->stack_b, config->ops);
		else
			radix_sort(config->stack_a, config->stack_b, config->ops);
	}
}

void	handle_sort_algo(t_conf *config)
{
	config->disorder = compute_disorder(config);
	if (config->disorder <= 0)
		return ;
	if (config->active_flag & SIMPLE)
		selection_sort(config->stack_a, config->stack_b, config->ops);
	else if (config->active_flag & MEDIUM)
		chunk_based(config->stack_a, config->stack_b, config->ops);
	else if (config->active_flag & COMPLEX)
		radix_sort(config->stack_a, config->stack_b, config->ops);
	else if (config->active_flag & ADAPTIVE)
		handle_adaptive(config);
}

int	main(int argc, char const *argv[])
{
	t_conf	*config;

	config = create_config(argc, argv);
	if (!config)
		return (1);
	handle_inputs(config);
	handle_sort_algo(config);
	if (config->active_flag & BENCH)
		handle_benchmark(config);
	exit_program(0, config);
	return (0);
}
