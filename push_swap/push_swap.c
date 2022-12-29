/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:15 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/29 19:13:05 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	sort_dq(t_deque *a, t_deque *b)
{
	size_t	n;

	if (a->first == a->last)
		return ;
	n = is_sorted(a);
	if (n == 1)
		return ;
	else if (n == 2)
		swap(a, b, SA);
	// else if (n == 3)
	// 	sort_3(a);
	// else if (n == 4)
	// 	sort_4(a, b);
	// else if (n == 5)
	// 	sort_5(a, b);
	// else if (n <= 6)
	// 	basis_sort(a);
}

void	ret_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	index_argv(t_deque *a)
{
	t_node	*temp;
	t_node	*temp_2;

	temp = a->first;
	while (temp)
	{
		temp_2 = a->first;
		while (temp_2)
		{
			if (temp->value > temp_2->value)
				temp->index++;
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}
}

void	parse_argv(int argc, char *argv[], t_deque *a)
{
	int		i;
	char	**splitted;

	i = 1;
	while (i < argc)
	{	
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			ret_error();
		while (*splitted)
		{
			dq_push_back(a, ft_atoi(*splitted));
			a->size++;
			splitted++;
		}
		i++;
	}
}

t_deque	*init_dq(void)
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	if (!deque)
		ret_error();
	deque->first = NULL;
	deque->last = NULL;
	deque->size = 0;
	return (deque);
}

int	main(int argc, char *argv[])
{
	t_deque	*a;
	t_deque	*b;
	t_node	*temp;

	a = init_dq();
	b = init_dq();
	check_arg(argc, argv);
	parse_argv(argc, argv, a);
	index_argv(a);
	sort_dq(a, b);
	// clear_dq(a, b);

	temp = a->first;
	while (temp)
	{
		printf("deque_a = %d, deque_a_index = %zu\n", temp->value, temp->index);
		temp = temp->next;
	}
	printf("a size is %zu\n\n", a->size);
	temp = b->first;
	while (temp)
	{
		printf("deque_b = %d, deque_b_index = %zu\n", temp->value, temp->index);
		temp = temp->next;
	}
	printf("b size is %zu\n\n", b->size);
	return (0);
}
