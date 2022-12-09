/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:00:43 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/10 04:05:01 by junyoo           ###   ########.fr       */
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
	game->c_move++;
	printf("game over your cat moved %d steps\n", game->c_move);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	ret_error(char *errmsg)
{
	perror (errmsg);
	exit(0);
}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c