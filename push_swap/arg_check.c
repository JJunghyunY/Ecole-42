/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:43:54 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/22 04:17:25 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	check_dup_value(t_deque	*deque, int value)
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

void	check_arg(int argc, char *argv[])
{
	int		i;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		check_digit(argv[i]);
		i++;
	}
}

void	check_digit(char *argv)
{
	int	i;
	int	argvlen;

	i = 0;
	argvlen = ft_strlen(argv);
	if (argvlen == 0)
		ret_error();
	while (i < argvlen)
	{
		if (argv[i] == ' ')
			i++;
		else if (argv[i] == '-' || argv[i] == '+')
		{
			i++;
			if (!ft_isdigit(argv[i]))
				ret_error();
		}
		else if (!ft_isdigit(argv[i]))
			ret_error();
		i++;
	}
}