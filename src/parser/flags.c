#include "push_swap.h"

int	is_flag(char *flag)
{
	if (!ft_strncmp(flag, "--simple", 9))
		return (TRUE);
	if (!ft_strncmp(flag, "--medium", 9))
		return (TRUE);
	if (!ft_strncmp(flag, "--complex", 10))
		return (TRUE);
	if (!ft_strncmp(flag, "--adaptive", 11))
		return (TRUE);
	if (!ft_strncmp(flag, "--bench", 8))
		return (TRUE);
	return (FALSE);
}

unsigned int init_flags(unsigned int FLAG, char *flag, t_conf *conf)
{
	unsigned int algorithm;

	if (!ft_strncmp(flag, "--simple", 9))
		FLAG |= SIMPLE;
	if (!ft_strncmp(flag, "--medium", 9))
		FLAG |= MEDIUM;
	if (!ft_strncmp(flag, "--complex", 10))
		FLAG |= COMPLEX;
	if (!ft_strncmp(flag, "--adaptive", 11))
		FLAG |= ADAPTIVE;
	if (!ft_strncmp(flag, "--bench", 8))
		FLAG |= BENCH;
	algorithm = FLAG & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE);
	if (algorithm & (algorithm - 1))
		exit_program(2, conf);
	return FLAG;
}
