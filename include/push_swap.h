#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Unistd.h included functions read, write
# include <unistd.h>

// Stdlib.h included functions malloc, free and exit
# include <stdlib.h>

typedef struct s_node
{
	long			content;
	struct s_node	*next;
}	t_node;

typedef struct s_linked
{
	t_node	*head;
	t_node	*tail;
}	t_linkedlist;

// Functions of list_node.c

void			linked_init(t_linkedlist *list);
t_node			*node_init(void);
t_node			*push_front(t_linkedlist *stack);
void			pop_front(t_linkedlist *stack);
int				add_content(t_node *node, long content);

// Functions of list_utils.c

void	list_print(t_linkedlist *list);
int		list_len(t_linkedlist *list);
int		is_list_clean(t_linkedlist *list);
int		is_list_one_node(t_linkedlist *list);

#endif
