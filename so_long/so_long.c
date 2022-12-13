/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:00:43 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/12 17:53:28 by junyoo           ###   ########.fr       */
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
		mlx_hook(g->win, 17, 0, exit_game, g);
		mlx_loop(g->mlx);
	}
	else
		perror ("please input only one map");
	return (0);
}

int	exit_game(t_game *game)
{
	write(1, "user exited game\n", 17);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(0);
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

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c