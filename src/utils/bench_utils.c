/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:26:36 by jzampier          #+#    #+#             */
/*   Updated: 2026/08/22 15:38:35 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(t_conf *config)
{
	float	percent;
	int		int_part;
	int		decimal_part;

	percent = config->disorder * 100;
	int_part = (int)percent;
	decimal_part = (int)((percent - int_part) * 100);
	if (decimal_part < 0)
		decimal_part *= -1;
	ft_dprintf(2, "[bench] disorder: %d.", int_part);
	if (decimal_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_adaptive_strategy(t_conf *config)
{
	int	len;

	ft_dprintf(2, "Adaptive / ");
	len = list_len(config->stack_a);
	if (len <= 5)
		ft_dprintf(2, "O(n2)");
	else if (len <= 100)
	{
		if (config->disorder < 0.1)
			ft_dprintf(2, "O(n2)");
		else
			ft_dprintf(2, "O(n√n)");
	}
	else
	{
		if (config->disorder < 0.1)
			ft_dprintf(2, "O(n2)");
		else if (config->disorder < 0.4)
			ft_dprintf(2, "O(n√n)");
		else
			ft_dprintf(2, "O(n log n)");
	}
}

void	print_strategy(t_conf *config)
{
	ft_dprintf(2, "[bench] strategy: ");
	if (config->active_flag & SIMPLE)
		ft_dprintf(2, "Simple / O(n2)");
	else if (config->active_flag & MEDIUM)
		ft_dprintf(2, "Medium / O(n√n)");
	else if (config->active_flag & COMPLEX)
		ft_dprintf(2, "Complex / O(n log n)");
	else
		print_adaptive_strategy(config);
	ft_dprintf(2, "\n");
}

void	print_operations(t_conf *config)
{
	ft_dprintf(2, "[bench] total_ops: %d\n", config->ops->all_ops);
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		config->ops->sa, config->ops->sb, config->ops->ss,
		config->ops->pa, config->ops->pb);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		config->ops->ra, config->ops->rb, config->ops->rr,
		config->ops->rra, config->ops->rrb, config->ops->rrr);
}

void	handle_benchmark(t_conf *config)
{
	print_disorder(config);
	print_strategy(config);
	print_operations(config);
}
