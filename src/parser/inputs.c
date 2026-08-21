#include "push_swap.h"

void	clean_exit(char **numbers, char *inputs)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	free(inputs);
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
	return (inputs);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_numbers(int total, char **numbers, char *inputs, t_conf *config)
{
	int		i;
	long	num;

	i = total;
	while (i >= 0)
	{
		if (!is_valid_number(numbers[i]))
		{
			clean_exit(numbers, inputs);
			exit_program(1, config);
		}
		num = ft_atol(numbers[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			clean_exit(numbers, inputs);
			exit_program(1, config);
		}
		if (get_by_content(config->stack_a, num) != NULL)
		{
			clean_exit(numbers, inputs);
			exit_program(1, config);
		}
		add_content(push_front(config->stack_a), num);
		i--;
	}
}

void	handle_inputs(t_conf *config)
{
	char			*inputs;
	int				total;
	char			**numbers;

	config->active_flag = NONE;
	if (config->argc < 2)
		return (exit_program(1, config));
	total = handle_flags(config);
	inputs = cat_inputs(total, config);
	if (!(config->active_flag & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE)))
		config->active_flag |= ADAPTIVE;
	total = 0;
	numbers = ft_split(inputs, ' ');
	while (numbers[total])
		total++;
	parse_numbers(total - 1, numbers, inputs, config);
	clean_exit(numbers, inputs);
}
