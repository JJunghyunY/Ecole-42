/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:43:54 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 17:15:03 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	check_int(char *argv)
{
	int			i;
	int			sign;
	long long	int_checker;

	i = 0;
	sign = 1;
	int_checker = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			int_checker = int_checker * 10 + (argv[i] - '0');
		else if (argv[i] == '-')
			sign = sign * -1;
		i++;
	}
	int_checker = int_checker * sign;
	if (int_checker > 2147483647 || int_checker < -2147483648)
		ret_error();
}

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
		exit(0);
	i = 1;
	while (i < argc)
	{
		check_all_space(argv[i]);
		check_digit(argv[i]);
		check_int(argv[i]);
		i++;
	}
}
