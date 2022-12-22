/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:31:12 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/22 03:55:08 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	dq_push_back(t_deque *deque, int value)
{
	t_node	*new_node;

	check_dup_value(deque, value);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->value = value;
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
	return (0);
}

int	dq_push_front(t_deque *deque, int value)
{
	t_node	*new_node;

	check_dup_value(deque, value);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->value = value;
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
	return (0);
}

int	dq_pop_front(t_deque *deque)
{
	t_node	*save;

	if (deque->first == NULL)
		return (0);
	save = deque->first->next;
	free(deque->first);
	if (save == NULL)
	{
		deque->first = save;
		deque->last = save;
		return (1);
	}
	deque->first = save;
	save->prev = NULL;
	return (1);
}

int	dq_pop_back(t_deque *deque)
{
	t_node	*save;

	if (deque->last == NULL)
		return (0);
	save = deque->last->prev;
	free(deque->last);
	if (save == NULL)
	{
		deque->first = save;
		deque->last = save;
		return (1);
	}
	deque->last = save;
	save->next = NULL;
	return (0);
}
