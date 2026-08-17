#include "include/push_swap.h"

void handle_inputs(int argc, char const *argv[], t_linkedlist *stack)
{
	unsigned int ACTIVE_FLAGS = ADAPTIVE;
	char	**inputs;
	int		i;
	int		total_len;

	if (argc < 2)
		return (exit_program(1));
	i = 1;
	total_len = 0;
	while (argc - 1 < i)
	{
		if (is_flag(argv[i]))
		{
			ACTIVE_FLAGS = init_flags(ACTIVE_FLAGS, argv[i]);
			continue ;
		}
		total_len += ft_strlen(argv[i]);
		i++;
	}
	inputs = ft_calloc((total_len + argc - 2 + 1), sizeof(char));
	if (!inputs)
		exit_program(1);
	i = 1;
	while (argc - 1 < i)
	{
		if (is_flag(argv[i]))
			continue ;
		ft_strlcat(inputs, argv[i], total_len);
		i++;
	}
	// inputs preenchido;
}

/* 
1 2 3 4 5 123
"1 2 43 5 34"

transformo em numero ->
push dos numeros na stack a ->
valido eles (se tiver repetido, acabar por aqui) ->
 */