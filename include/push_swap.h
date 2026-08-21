/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norminette <norminette@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 00:00:00 by norminette        #+#    #+#             */
/*   Updated: 2026/08/20 00:00:00 by norminette       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

enum					e_flags
{
	NONE = 0,
	SIMPLE = 1 << 0,
	MEDIUM = 1 << 1,
	COMPLEX = 1 << 2,
	ADAPTIVE = 1 << 3,
	BENCH = 1 << 4,
};

typedef struct s_ops
{
	int					all_ops;
	int					pb;
	int					pa;
	int					sa;
	int					sb;
	int					ss;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_ops;

typedef struct s_node
{
	long				content;
	int					index;
	struct s_node		*next;
}						t_node;

typedef struct s_linked
{
	t_node				*head;
	t_node				*tail;
}						t_linkedlist;

typedef struct s_config
{
	t_linkedlist		*stack_a;
	t_linkedlist		*stack_b;
	t_ops				*ops;
	int					argc;
	const char			**argv;
	float				disorder;
	unsigned int		active_flag;
}						t_conf;

/* Configuration */
t_conf					*create_config(int argc, const char **argv);

/* List Node */
void					linked_init(t_linkedlist *list);
t_node					*node_init(void);
t_node					*push_front(t_linkedlist *stack);
void					pop_front(t_linkedlist *stack);
int						add_content(t_node *node, long content);

/* List Utils */
void					list_print(t_linkedlist *list);
int						list_len(t_linkedlist *list);
int						is_list_clean(t_linkedlist *list);
int						is_list_one_node(t_linkedlist *list);
void					exit_program(int exit_code, t_conf *config);

/* Flags & Inputs */
int						is_flag(char *flag);
unsigned int			init_flags(unsigned int flag_val, char *flag,
							t_conf *conf);
void					clean_exit(char **numbers, char *inputs);
int						handle_flags(t_conf *config);
char					*cat_inputs(int total, t_conf *config);
char					**parse_numbers(int total, char **numbers, char *inputs,
							t_conf *config);
void					handle_inputs(t_conf *config);
t_node					*get_by_content(t_linkedlist *list, long content);
void					clear_list(t_linkedlist *stack);

/* Stack Operations */
int						pa(t_linkedlist *stack_a, t_linkedlist *stack_b,
							t_ops *ops);
int						pb(t_linkedlist *stack_b, t_linkedlist *stack_a,
							t_ops *ops);
int						sa(t_linkedlist *stack_a, t_ops *ops);
int						sb(t_linkedlist *stack_b, t_ops *ops);
int						ss(t_linkedlist *stack_a, t_linkedlist *stack_b,
							t_ops *ops);
int						ra(t_linkedlist *stack_a, t_ops *ops);
int						rb(t_linkedlist *stack_b, t_ops *ops);
int						rr(t_linkedlist *stack_a, t_linkedlist *stack_b,
							t_ops *ops);
int						rra(t_linkedlist *stack_a, t_ops *ops);
int						rrb(t_linkedlist *stack_b, t_ops *ops);
int						rrr(t_linkedlist *stack_a, t_linkedlist *stack_b,
							t_ops *ops);

/* Algorithm Utils */
void					index_stack(t_linkedlist *stack);
int						is_sorted(t_linkedlist *stack);
int						get_max_bits(int size);
int						get_max_pos(t_linkedlist *stack);
int						get_chunk_size(int n);

/* Algorithms */
void					selection_sort(t_linkedlist *stack_a,
							t_linkedlist *stack_b, t_ops *ops);
void					radix_sort(t_linkedlist *stack_a,
							t_linkedlist *stack_b, t_ops *ops);
void					chunk_based(t_linkedlist *stack_a,
							t_linkedlist *stack_b, t_ops *ops);

#endif
