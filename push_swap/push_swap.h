/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:18 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 16:46:15 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_node
{
	int				value;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	size_t	size;
	t_node	*first;
	t_node	*last;
}	t_deque;

typedef enum e_cmd_case
{
	SA		= 0,
	SB		= 1,
	SS		= 2,
	PA		= 3,
	PB		= 4,
	RA		= 5,
	RB		= 6,
	RR		= 7,
	RRA		= 8,
	RRB		= 9,
	RRR		= 10
}	t_cmd_case;

void	ret_error(void);

void	check_arg(int argc, char *argv[]);

t_deque	*init_dq(void);
size_t	is_sorted(t_deque *a);
void	parse_argv(int argc, char *argv[], t_deque *a);
void	index_argv(t_deque *a);

void	dq_push_back(t_deque *deq, int value);
void	dq_push_front(t_deque *deq, int value);
void	dq_pop_front(t_deque *deq);
void	dq_pop_back(t_deque *deq);

void	push(t_deque *a, t_deque *b, t_cmd_case cmd_case);
void	swap(t_deque *a, t_deque *b, t_cmd_case cmd_case);
void	rotate(t_deque *a, t_deque *b, t_cmd_case cmd_case);
void	reverse_rotate(t_deque *a, t_deque *b, t_cmd_case cmd_case);

void	sort_sandglass(t_deque *a, t_deque *b);

#endif