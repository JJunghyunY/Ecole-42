<<<<<<< HEAD
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
=======
# define TILE "./asset/tile.xpm"
# define WALL "./asset/wall.xpm"
# define RAT "./asset/rat.xpm"
# define BOX_OPEN "./asset/box_open.xpm"
# define BOX_CLOSE "./asset/box_close.xpm"
# define CAT_UP "./asset/cat_up.xpm"
# define CAT_DOWN "./asset/cat_down.xpm"
# define CAT_RIGHT "./asset/cat_right.xpm"
# define CAT_LEFT "./asset/cat_left.xpm"

#include "./mlx/mlx.h"
#include "./source/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	char	*str;
	int		col;
	int		row;

	void	*img_tile;
	void	*img_wall;
	void	*img_cat_right;
	void	*img_rat;
	void	*img_box_close;
}	t_game;

char	*my_strjoin(char const *s1, char const *s2);
void	press_w(t_game *game);
char	*ft_strdup(const char *s1);
int		deal_key(int key, t_game *game);
void	map_set(t_game *game);

void	map_set(t_game *game)
{
	int	height = 0;
	int	width = 0;

	int img_width;
	int img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &img_width, &img_height);
	game->img_tile = mlx_xpm_file_to_image(game->mlx_ptr, TILE, &img_width, &img_height);
	game->img_cat_right = mlx_xpm_file_to_image(game->mlx_ptr, CAT_RIGHT, &img_width, &img_height);
	game->img_rat = mlx_xpm_file_to_image(game->mlx_ptr, RAT, &img_width, &img_height);
	game->img_box_close = mlx_xpm_file_to_image(game->mlx_ptr, BOX_CLOSE, &img_width, &img_height);

	int i = 0;
	while (height < game -> height)
	{
		width = 0;
		while (width < game -> width)
		{
			if (game -> str[i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, width * 50, height * 50);
			else if (game -> str[i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_tile, width * 50, height * 50);
			else if (game -> str[i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_cat_right, width * 50, height * 50);
			else if (game -> str[i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_rat, width * 50, height * 50);
			else if (game -> str[i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_box_close, width * 50, height * 50);
			width ++;
			i++;
		}
		height++;
	}
	mlx_key_hook(game->win_ptr, deal_key, (void *)0);
	mlx_loop(game->mlx_ptr);
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

void press_w(t_game *game)
{
	int	i;

	i = 0;
	while(i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break;
	}
		game->str[i] = '0';
		game->str[i - game->width] = 'P';
		printf("cat position is %d", i);
}

int	deal_key(int key, t_game *game)
{
	printf("%d\n",key);
	if (key == 13)
		press_w(game);
	// else if (key = 0)
	// 	press_a();
	// else if (key == 1)
	// 	press_s();
	// else if (key == 2)
	// 	press_d();
	return (0);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game -> height = 0;
	game -> width = ft_strlen(line) - 1;
	game -> str = ft_strdup(line);
	free(line);
	while (line)
	{
		game -> height++;
		line = get_next_line(fd);
		if (line)
			game -> str = my_strjoin(game -> str, line);
	}
	close(fd);
	printf("%s\n", game -> str);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	map_read(argv[1], game);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 700, 300, "junyoo");
	map_set(game);
>>>>>>> 9cb8d60b2ef146185b49fabe813cc8f84b56022d
}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c