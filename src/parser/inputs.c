#include "push_swap.h"

void	clean_exit(char **numbers, char *inputs)
{
	int i;

	i = 0;
	while(numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	free(inputs);
}

int	handle_flags(unsigned int FLAG, t_conf *config)
{
	int		i;
	int 	total;

	i = 1;
	total = 0;
	while (i < config->argc)
	{
		if (is_flag(((char *)config->argv[i])))
		{
			FLAG = init_flags(FLAG, ((char *)config->argv[i]), config);
			i++;
			continue ;
		}
		total += ft_strlen(config->argv[i]);
		i++;
	}
	total += config->argc - 2 + 1;
	return (total);
}

char	*cat_inputs(int total, t_conf *config)
{
	char	*inputs;
	int		i;

	inputs = ft_calloc(total, sizeof(char));
	if (!inputs)
		exit_program(1, config);

	i = 1;
	while (i < config->argc)
	{
		if (is_flag(((char *)config->argv[i])))
		{
			i++;
			continue ;
		}
		ft_strlcat(inputs, config->argv[i], total);
		ft_strlcat(inputs, " ", total);
		i++;
	}
	return inputs;
}

char	**parse_numbers(char *inputs, t_conf *config)
{
	int		i;
	char	**numbers;
	long	num;
	t_node	*new_node;

	i = 0;
	numbers = ft_split(inputs, ' ');
	while (numbers[i])
		i++;
	i--;
	while (i >= 0)
	{
		num = ft_atol(numbers[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			clean_exit(numbers, inputs);
			exit_program(2, config);
		}
		if (get_by_content(config->stack_a, num) != NULL)
		{
			clean_exit(numbers, inputs);	
			exit_program(2, config);
		}
		new_node = push_front(config->stack_a);
		add_content(new_node, num);
		i--;
	}
	return (numbers);
}

void	handle_inputs(t_conf *config)
{
	unsigned int	ACTIVE_FLAGS = NONE;
	char			*inputs;
	int				total;
	char			**numbers;

	if (config->argc < 2)
		return (exit_program(1, config));
	total = handle_flags(ACTIVE_FLAGS, config);
	inputs = cat_inputs(total, config);
	if (!(ACTIVE_FLAGS & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE)))
        ACTIVE_FLAGS |= ADAPTIVE;
	numbers = parse_numbers(inputs, config);
	clean_exit(numbers, inputs);
	list_print(config->stack_a);
}
