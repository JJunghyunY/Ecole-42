/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:15 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 19:23:49 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	print_dq(t_deque *dq)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = dq->first;
	printf("\n*******************************************************\n");
	while (temp)
	{
		printf("deque_%d = %d, deque_%d_index = %zu\n", i, temp->value, i, temp->index);
		temp = temp->next;
		i++;
	}
	printf("dq size is %zu\n", dq->size);
	printf("\n*******************************************************\n");
}

static void	sort_dq(t_deque *a, t_deque *b)
{
	size_t	n;

	if (a->first == a->last)
		return ;
	n = is_sorted(a);
	if (n == 1)
		return ;
	else if (n == 2)
		swap(a, b, SA);
	else
		sort_sandglass(a, b);

	// else if (n == 3)
	// 	sort_3(a);
	// else if (n == 4)
	// 	sort_4(a, b);
	// else if (n == 5)
	// 	sort_5(a, b);
	// else if (n <= 6)
	// 	basis_sort(a);
}

static void	clear_dq(t_deque *a, t_deque *b)
{
	t_node	*node;
	
	node = a->first;
	while (node)
	{
		node = node->next;
		dq_pop_front(a);
	}
	node = b->first;
	while (node)
	{
		node = node->next;
		dq_pop_front(b);
	}
}

int	main(int argc, char *argv[])
{
	t_deque	*a;
	t_deque	*b;

	a = init_dq();
	b = init_dq();
	check_arg(argc, argv);
	parse_argv(argc, argv, a);
	index_argv(a);
	sort_dq(a, b);
	clear_dq(a, b);
	return (0);
}

void	ret_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
