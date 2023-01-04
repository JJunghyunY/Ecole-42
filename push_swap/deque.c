/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:31:12 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 22:17:12 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	check_dup_value(t_deque	*deque, int value)
{
	t_node	*checker;

	checker = deque->first;
	while (checker)
	{
		if (checker->value == value)
			ret_error();
		checker = checker->next;
	}
}

void	dq_push_back(t_deque *deque, int value)
{
	t_node	*new_node;

	check_dup_value(deque, value);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		ret_error();
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = deque->last;
	if (deque->last == NULL && deque->first == NULL)
	{
		deque->last = new_node;
		deque->first = new_node;
	}
	else
	{
		if (deque->last != NULL)
			deque->last->next = new_node;
		deque->last = new_node;
	}
}

void	dq_push_front(t_deque *deque, int value)
{
	t_node	*new_node;

	check_dup_value(deque, value);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		ret_error();
	new_node->value = value;
	new_node->index = 0;
	new_node->prev = NULL;
	if (deque->first == NULL)
	{
		deque->first = new_node;
		deque->last = new_node;
		new_node->next = NULL;
	}
	else
	{
		deque->first->prev = new_node;
		new_node->next = deque->first;
		deque->first = new_node;
	}
}

void	dq_pop_front(t_deque *deque)
{
	t_node	*save;

	if (deque->first == NULL)
		ret_error();
	save = deque->first->next;
	free(deque->first);
	deque->first = NULL;
	if (save == NULL)
	{
		deque->first = NULL;
		deque->last = NULL;
	}
	else
	{
		deque->first = save;
		save->prev = NULL;
	}
}

void	dq_pop_back(t_deque *deque)
{
	t_node	*save;

	if (deque->last == NULL)
		ret_error();
	save = deque->last->prev;
	free(deque->last);
	deque->last = NULL;
	if (save == NULL)
	{
		deque->first = NULL;
		deque->last = NULL;
	}
	else
	{
		deque->last = save;
		save->next = NULL;
	}
}
