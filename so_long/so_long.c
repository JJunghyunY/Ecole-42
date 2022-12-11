/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:00:43 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/11 22:28:34 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*g;

	if (argc == 2)
	{
		g = malloc(sizeof(t_game));
		map_read(argv[1], g);
		map_check(g);
		g->mlx = mlx_init();
		g->win = mlx_new_window(g->mlx, g->wid * 50, g->hei * 50, "so_long");
		img_set(g);
		map_set(g, 2, g->c_rat);
		mlx_key_hook(g->win, deal_key, g);
		mlx_hook(g->win, 17, 0, end_game, g);
		mlx_loop(g->mlx);
	}
	else
		perror ("please input only one map");
	return (0);
}

int	end_game(t_game *game)
{
	print_cat_move(game->c_move + 1, 0);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(0);
}

void	ret_error(char *errmsg)
{
	perror (errmsg);
	exit(0);
}

void	print_cat_move(int c_move, int flag)
{
	if (flag)
		write(1, "cat moved ", 10);
	else
		write(1, "\ngame over!! your cat moved ", 28);
	ft_putnbr(c_move);
	write(1, " steps\n", 7);
}

void	ft_putnbr(int n)
{
	long long	temp;
	int			i;
	char		str[15];

	temp = (long long)n;
	i = 0;
	if (n < 0)
	{
		temp *= -1;
		write (1, "-", 1);
	}
	else if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	while (temp)
	{
		str[i++] = (temp % 10) + '0';
		temp /= 10;
	}
	while (--i >= 0)
		write(1, str + i, 1);
}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c