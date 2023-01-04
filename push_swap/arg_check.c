/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:43:54 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 22:16:51 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	check_all_space(char *argv)
{
	int	i;
	int	argvlen;
	int	flag;

	argvlen = ft_strlen(argv);
	if (argvlen == 0)
		ret_error();
	i = 0;
	flag = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			flag++;
		i++;
	}
	if (flag == argvlen)
		ret_error();
}

static void	check_digit(char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
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
		if (argv[i] >= '0' && argv[i] <= '9')
		i++;
	}
}

void	check_arg(int argc, char *argv[])
{
	int		i;

	if (argc < 2)
		exit(1);
	i = 1;
	while (i < argc)
	{
		check_all_space(argv[i]);
		check_digit(argv[i]);
		i++;
	}
}
