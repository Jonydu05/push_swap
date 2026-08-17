#include "include/push_swap.h"

int	is_flag(char *flag)
{
	if (!ft_strncmp(flag, "--simple", ft_strlen(flag)))
		return (TRUE);
	if (!ft_strncmp(flag, "--medium", ft_strlen(flag)))
		return (TRUE);
	if (!ft_strncmp(flag, "--complex", ft_strlen(flag)))
		return (TRUE);
	if (!ft_strncmp(flag, "--adaptive", ft_strlen(flag)))
		return (TRUE);
	if (!ft_strncmp(flag, "--bench", ft_strlen(flag)))
		return (TRUE);
	return (FALSE);
}

unsigned int init_flags(unsigned int FLAG, char *flag)
{
	unsigned int algorithm;

	if (!ft_strncmp(flag, "--simple", ft_strlen(flag)))
		FLAG |= SIMPLE;
	if (!ft_strncmp(flag, "--medium", ft_strlen(flag)))
		FLAG |= MEDIUM;
	if (!ft_strncmp(flag, "--complex", ft_strlen(flag)))
		FLAG |= COMPLEX;
	if (!ft_strncmp(flag, "--adaptive", ft_strlen(flag)))
		FLAG |= ADAPTIVE;
	if (!ft_strncmp(flag, "--bench", ft_strlen(flag)))
		FLAG |= BENCH;	
	algorithm = FLAG & (SIMPLE | MEDIUM | COMPLEX | ADAPTIVE);
	if (algorithm && algorithm - 1)
		exit_program(2);
	return FLAG;
}
