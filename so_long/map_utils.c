/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:34 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/06 22:22:12 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

void	map_set(t_game *game, int key_code, int c_rat)
{
	int	height;
	int	width;

	printf("cat movd %d steps\n", game->c_move);
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

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		perror ("following error occured ");
		exit (0);
	}
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) -1;
	game->str = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
			game->str = my_strjoin(game->str, line);
	}
	close(fd);
	count_rat(game);
	printf("%s\n", game->str);
}

void	count_rat(t_game *game)
{
	int	i;
	int	c_rat;

	i = 0;
	c_rat = 0;
	while (game->str[i++])
	{
		if (game->str[i] == 'C')
			c_rat ++;
	}
	game->c_rat = c_rat;
	game->c_move = 0;
}
