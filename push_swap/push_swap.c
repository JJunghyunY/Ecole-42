/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:19:15 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/14 17:06:50 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"
#include <stdio.h>

// ./push_swap 1 2 3 4 "5" 6 "7" 8

void	ret_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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
		if (!ft_isdigit(argv[i]))
			ret_error();
		i++;
	}
}

void	parse_values(int argc, char *argv[])
{
	int	i;
	int	argvtoi;

	i = 1;
	while (i < argc)
	{
		printf("argv = %s\n", argv[i]);
		check_digit(argv[i]);
		argvtoi = ft_atoi(argv[i]);
		printf("atoid argv = %d\n", argvtoi);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char		cmd;
	t_pushswap	ps;

	if (argc < 2)
		exit(1);
	ps_init(&ps);
	parse_values(argc, argv);
	return (0);
}
