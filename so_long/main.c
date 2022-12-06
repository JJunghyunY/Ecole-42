/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:00:43 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/06 22:42:27 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	end_game(t_game *game)
{
	game->c_move++;
	printf("game over your cat moved %d steps\n", game->c_move);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
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

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2 != '\n')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1)));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	map_check(t_game *game)
{
	if (game->hei == game->wid)
	{
		perror ("Not a rectangular map");
		exit(0);
	}
	else if (game->hei <= 3, game->wid <= 3)
	{
		perror ("Map is too small");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_game	*g;

	if (argc == 2)
	{
		g = malloc(sizeof(t_game));
		map_read(argv[1], g);
		map_check(g);
		g->mlx = mlx_init();
		g->win = mlx_new_window(g->mlx, g->wid * 50,g->hei * 50, "so_long");
		img_set(g);
		map_set(g, 2, g->c_rat);
		mlx_key_hook(g->win, deal_key, g);
		mlx_hook(g->win, 17, 0, end_game, g);
		mlx_loop(g->mlx);
	}
	else
		printf("map_error\n");
	return (0);
}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c