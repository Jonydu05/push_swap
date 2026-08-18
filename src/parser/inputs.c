#include "push_swap.h"

void handle_inputs(int argc, char const *argv[], t_conf *config)
{
	unsigned int	ACTIVE_FLAGS = NONE;
	char			*inputs;
	int				i;
	int				total_len;
	char			**numbers;
	long 			num;
	t_node			*new_node;

	if (argc < 2)
		return (exit_program(1, config));
	i = 1;
	total_len = 0;
	while (i < argc)
	{
		if (is_flag(((char *)argv[i])))
		{
			ACTIVE_FLAGS = init_flags(ACTIVE_FLAGS, ((char *)argv[i]), config);
			i++;
			continue ;
		}
		total_len += ft_strlen(argv[i]);
		i++;
	}
	total_len += argc - 2 + 1;
	inputs = ft_calloc(total_len, sizeof(char));
	if (!inputs)
		exit_program(1, config);
	i = 1;
	while (i < argc)
	{
		if (is_flag(((char *)argv[i])))
		{
			
			i++;
			continue ;
		}
		ft_strlcat(inputs, argv[i], total_len);
		ft_strlcat(inputs, " ", total_len);
		i++;
	}
	if (!(ACTIVE_FLAGS & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE)))
    {
        ACTIVE_FLAGS |= ADAPTIVE;
    }
	i = 0;
	numbers = ft_split(inputs, ' ');
	while (numbers[i])
		i++;
	i--;
	while (i >= 0)
	{
		num = ft_atol(numbers[i]);
		// TODO: free numbers in case of error or exit_program
		if (num < -2147483648 || num > 2147483647)
			exit_program(2, config);
		if (get_by_content(config->stack_a, num) != NULL)
			exit_program(2, config);
		new_node = push_front(config->stack_a);
		add_content(new_node, num);
		free(numbers[i]);
		i--;
	}
	list_print(config->stack_a);
	free(inputs);
	free(numbers);
}
