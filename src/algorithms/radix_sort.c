#include "push_swap.h"
#include <stdio.h>

static long	max(t_linkedlist *stack_a)
{
	t_node *node;

	node = stack_a->head;
	long max_content = node->content;

	while (node)
	{
		if (node->content > max_content)
			max_content = node->content;
		node = node->next;
	}
	return (max_content);
}

static void safe_init(t_node **buckets)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		buckets[j] = node_init();
		j++;
	}
}

static void append(t_node *bucket, long content)
{
    t_node *tmp;

    if (!bucket->next && !bucket->content)
    {
        bucket->content = content;
        bucket->next = node_init();
    }
    else
    {
        tmp = bucket;
        while (tmp->next)
            tmp = tmp->next;
        tmp->content = content;
        tmp->next = node_init();
    }
}

static void inversion_numbers(t_node **buckets, t_node *head)
{
	int	j;
	t_node	*buck;

	j = 0;
	while (j < 10)
	{
		buck = buckets[j];
		while (buck->next)
		{
			head->content = buck->content;
			buck = buck->next;
			head = head->next;
		}
		j++;
	}
}

static void safe_clear(t_node **buckets)
{
    int     j;
    t_node  *tmp;
    t_node  *next;

    j = 0;
    while (j < 10)
    {
        tmp = buckets[j];
        while (tmp)
        {
            next = tmp->next;
            free(tmp);
            tmp = next;
        }
        j++;
    }
    free(buckets);
}

void	radix_sort(t_linkedlist *stack_a)
{
	long max_number;
	int	exp;
	long index;
	t_node *head;
	t_node **buckets;

	exp = 1;
	max_number = max(stack_a);
	while ((int)max_number / exp > 0)
	{
		buckets = malloc(sizeof(t_node *) * 10);

		safe_init(buckets);
		head = stack_a->head;
		while (head)
		{
			index = ((long)head->content / exp) % 10;
			append(buckets[index], head->content);
			head = head->next;
		}
		head = stack_a->head;
		inversion_numbers(buckets, head);
		exp *= 10;
		safe_clear(buckets);

		// printagem
		printf("\n\n");
		list_print(stack_a);
	}
	//safe_clear(buckets);
}

