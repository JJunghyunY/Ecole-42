/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:18 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/28 18:29:36 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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

void	ret_error(void);

int		dq_push_back(t_deque *deq, int value);
int		dq_push_front(t_deque *deq, int value);
int		dq_pop_front(t_deque *deq);
int		dq_pop_back(t_deque *deq);

void	check_dup_value(t_deque	*deque, int value);
void	check_arg(int argc, char *argv[]);
void	check_digit(char *argv);

size_t	is_sorted(t_deque *a);

#endif