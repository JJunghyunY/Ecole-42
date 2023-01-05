/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:15 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/05 16:13:23 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

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
	else if (n == 3)
		sort_3_arg(a, b);
	else if (n == 4)
		sort_4_arg(a, b);
	else if (n == 5)
		sort_5_arg(a, b);
	else
		sort_sandglass(a, b);
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

void	ret_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
