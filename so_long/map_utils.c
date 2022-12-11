/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:34 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/11 15:29:22 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		ret_error("error occured ");
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	while (line)
	{
		game->hei++;
		game->str = solong_strjoin(game->str, line);
		printf("gamestr = %s\n", game->str);
		line = get_next_line(fd);
	}
	close(fd);
	count_rat(game);
}

void	img_set(t_game *game)
{
	int	wid;
	int	hei;

	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &wid, &hei);
	game->tile = mlx_xpm_file_to_image(game->mlx, TILE, &wid, &hei);
	game->cat_up = mlx_xpm_file_to_image(game->mlx, CAT_UP, &wid, &hei);
	game->cat_down = mlx_xpm_file_to_image(game->mlx, CAT_DOWN, &wid, &hei);
	game->cat_right = mlx_xpm_file_to_image(game->mlx, CAT_RIGHT, &wid, &hei);
	game->cat_left = mlx_xpm_file_to_image(game->mlx, CAT_LEFT, &wid, &hei);
	game->rat = mlx_xpm_file_to_image(game->mlx, RAT, &wid, &hei);
	game->box_close = mlx_xpm_file_to_image(game->mlx, BOX_CLOSE, &wid, &hei);
	game->box_open = mlx_xpm_file_to_image(game->mlx, BOX_OPEN, &wid, &hei);
}

void	map_set(t_game *game, int key_code, int c_rat)
{
	int	height;
	int	width;

	print_cat_move(game->c_move, 1);
	height = -1;
	while (++height < game->hei)
	{
		width = -1;
		while (++width < game->wid)
		{
			if (game->str[height * game->wid + width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					width * 50, height * 50);
			else if (game->str[height * game->wid + width] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tile,
					width * 50, height * 50);
			else if (game->str[height * game->wid + width] == 'P')
				put_cat_image(game, height, width, key_code);
			else if (game->str[height * game->wid + width] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->rat,
					width * 50, height * 50);
			else if (game->str[height * game->wid + width] == 'E')
				put_box_image(game, height, width, c_rat);
		}
	}
}

void	put_box_image(t_game *g, int hei, int wid, int c_rat)
{
	if (c_rat == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->box_open,
			wid * 50, hei * 50);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->box_close,
			wid * 50, hei * 50);
}

void	put_cat_image(t_game *game, int height, int width, int key_code)
{
	if (key_code == 13)
		mlx_put_image_to_window(game->mlx, game->win, game->cat_up,
			width * 50, height * 50);
	else if (key_code == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->cat_left,
			width * 50, height * 50);
	else if (key_code == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->cat_down,
			width * 50, height * 50);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->cat_right,
			width * 50, height * 50);
}
