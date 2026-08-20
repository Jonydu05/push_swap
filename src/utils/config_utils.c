#include "push_swap.h"

void	init_ops(t_ops *ops)
{
	ops->all_ops = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

t_conf	*create_config(int argc, const char **argv)
{
	t_conf			*config;
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	t_ops			*ops;

	stack_a = malloc(sizeof(t_linkedlist));
	stack_b = malloc(sizeof(t_linkedlist));
	ops = malloc(sizeof(t_ops));
	if (!stack_a || !stack_b || !ops)
		return (NULL);
	linked_init(stack_a);
	linked_init(stack_b);
	init_ops(ops);
	config = malloc(sizeof(t_conf));
	if (!config)
		return (NULL);
	config->stack_a = stack_a;
	config->stack_b = stack_b;
	config->argc = argc;
	config->argv = argv;
	config->ops = ops;
	return (config);
}

//float	compute_disorder(t_conf *config)
//{
//	t_node	*head;
//	t_node	*next;
//	int		mistakes;
//	int		total_pairs;
//
//	head = config->stack_a->head;

void	exit_program(int exit_code, t_conf *config)
{
	clear_stack(config->stack_a);
	clear_stack(config->stack_b);
	if (exit_code == 0)
		exit(0);
	if (exit_code == 1)
	{
		ft_putstr_fd("Error: Invalid Input List\n", 2);
		exit(1);
	}
	if (exit_code == 2)
	{
		ft_putstr_fd("Error: Invalid Input Flags\n", 2);
		exit(2);
	}
	if (exit_code == 3)
	{
		ft_putstr_fd("Error: Unknown error\n", 3);
		exit(3);
	}
}
