/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:29:05 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 16:46:44 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

size_t	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->first;
	while (node->next)
	{
		if (node->index > node->next->index)
			return (a->size);
		node = node->next;
	}
	return (1);
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
