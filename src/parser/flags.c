#include "push_swap.h"

int	is_flag(char *flag)
{
	if (flag[0] == '-' && flag[1] == '-')
		return (TRUE);
	return (FALSE);
}

unsigned int init_flags(unsigned int FLAG, char *str_flag, t_conf *conf)
{
	unsigned int algorithm;

	if (!ft_strncmp(str_flag, "--simple", 9))
		FLAG |= SIMPLE;
	else if (!ft_strncmp(str_flag, "--medium", 9))
		FLAG |= MEDIUM;
	else if (!ft_strncmp(str_flag, "--complex", 10))
		FLAG |= COMPLEX;
	else if (!ft_strncmp(str_flag, "--adaptive", 11))
		FLAG |= ADAPTIVE;
	else if (!ft_strncmp(str_flag, "--bench", 8))
		FLAG |= BENCH;
	else
		exit_program(2, conf);
	algorithm = FLAG & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE);
	if (algorithm & (algorithm - 1))
		exit_program(2, conf);
	return (FLAG);
}
