#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Unistd.h included functions read, write
# include <unistd.h>
# include "../libft/libft.h"

// Stdlib.h included functions malloc, free and exit
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

enum e_flags {
	NONE = 0,
	SIMPLE = 1 << 0,
	MEDIUM = 1 << 1,
	COMPLEX = 1 << 2,
	ADAPTIVE = 1 << 3,
	BENCH = 1 << 4,
};

typedef struct s_ops
{
	int	all_ops;
	int	pb;
	int	pa;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_node
{
	long			content;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_linked
{
	t_node	*head;
	t_node	*tail;
}	t_linkedlist;

typedef struct s_config
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	t_ops			*ops;
	int				argc;
	const char		**argv;
} t_conf;

t_conf	*create_config(int argc, const char **argv);

// Functions of list_node.c

/**
* @brief This function make a safe initialize linked list type
*
* @param list A pointer variable type t_linkedlist
*
* @return Void
*/
void			linked_init(t_linkedlist *list);

/**
* @brief This function make a safe initialize node type
*
* @return Return pointer of node allocated
*/
t_node			*node_init(void);

/**
* @brief This function push a new node to first position in a stack structury
*
* @param stack The stack is a pointer of t_linkedlist type
*
* @return Return pointer of new node allocated case fail return NULL
*/
t_node			*push_front(t_linkedlist *stack);

/**
* @brief This function make safe delete of node
*
* @param stack The stack is a pointer of t_linkedlist type
*
* @return Void
*/
void			pop_front(t_linkedlist *stack);

/**
* @brief This function add new value content of pointed node t_node type
*
* The function NOT accept value number passed the INT_MAX or INT_MIN

* @param node The node is a pointer of t_node typr
* @param content The content is a value decimal long type
*
* @return Returned a integer boolean one to valid content or zero to invalid content
*/
int				add_content(t_node *node, long content);

// Functions of list_utils.c

/**
* @brief This function printed using a printf function the content of nodes
*
* @param list A pointer variable type t_linkedlist
*
* @return Void
*/
void	list_print(t_linkedlist *list);

/**
* @brief This function count number of nodes in linked list
*
* @param list A pointer variable of t_linkedlist type
*/
int		list_len(t_linkedlist *list);

/**
* @brief This function verify if the linked list is clean
*
* @param list A variable pointer of t_linkedlist type
*
* @return Return one if is clean of nodes or zero if is false
*/
int		is_list_clean(t_linkedlist *list);

/**
* @brief This function verify if the linked list have one content
*
* @param list A variable pointer of t_linkedlist type
*
* @return Return one if have one node  or zero if is false
*/
int		is_list_one_node(t_linkedlist *list);

/**
 * @brief This function exit the program with a error message
 *
 * @param exit_code The exit code is a integer value to identify the error
 *
 * @brief 0 - Success;
 * @brief 1 - Invalid input list;
 * @brief 2 - Invalid input flags;
 * @brief 3 - Unknown error;
 * @
 *
 * @return Void
 */
void exit_program(int exit_code, t_conf *config);

// flags.c

/**
 * @brief This function just verifies if the argument is some flag
 *
 * @param flag The string to be compared
 *
 * @return TRUE if is some flag or FALSE if its not.
 */
int	is_flag(char *flag);

/**
 * @brief This function initialize the flags
 *
 * @param FLAG the byte where the flags are stored (using bitwise for efficiency)
 * @param flag the string to compare
 *
 * @return Return the FLAG updated with the new flags
 */
unsigned int init_flags(unsigned int FLAG, char *flag, t_conf *conf);

void	clean_exit(char **numbers, char *inputs);
int		handle_flags(unsigned int FLAG, t_conf *config);
char	*cat_inputs(int total, t_conf *config);
char	**parse_numbers(int total, char **numbers, char *inputs, t_conf *config);
void	handle_inputs(t_conf *config);

t_node	*get_by_content(t_linkedlist *list, long content);
t_node	*get_at(t_linkedlist *list, size_t index);

void	clear_stack(t_linkedlist *stack);

// Operations to use stack

int	pa(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);
int	pb(t_linkedlist *stack_b, t_linkedlist *stack_a, t_ops *ops);
int	sa(t_linkedlist *stack_a, t_ops *ops);
int	sb(t_linkedlist *stack_b, t_ops *ops);
int	ss(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);
int	ra(t_linkedlist *stack_a, t_ops *ops);
int	rb(t_linkedlist *stack_a, t_ops *ops);
int	rr(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);
int	rra(t_linkedlist *stack_a, t_ops *ops);
int	rrb(t_linkedlist *stack_b, t_ops *ops);
int	rrr(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);

// Algorithm utils

void	index_stack(t_linkedlist *stack_a);
int	is_sorted(t_linkedlist *stack);
int	get_max_bits(int size);

// selection_sort

void	selection_sort(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);

// radix_sort

void	radix_sort(t_linkedlist *stack_a, t_linkedlist *stack_b, t_ops *ops);

#endif
