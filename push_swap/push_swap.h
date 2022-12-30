/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:18 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 20:13:05 by junyoo           ###   ########.fr       */
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
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
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
void	sort_3_arg(t_deque *a, t_deque *b);
void	sort_4_arg(t_deque *a, t_deque *b);
void	sort_5_arg(t_deque *a, t_deque *b);

#endif