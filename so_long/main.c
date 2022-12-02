#include "./mlx/mlx.h"
#include "./source/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_game
{
	int		height;
	int		width;
	char	*str;
}	t_game;

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

// void	action_w()
// {

// }

int	deal_key(int key, void *param)
{
	printf("keycode : %d\n", key);
	// if (key == 13)
	// 	action_w();
	return (0);
}

void	map_set(t_game *game)
{
	void	*mlx_ptr;
	void	*win_ptr;

	int	height = 0;
	int	width = 0;
	int	game_height = game -> height;
	int	game_width = game -> width;

	void	*img_wall;
	void	*img_tile;
	void	*img_cat;
	void	*img_rat;
	void	*img_box;

	int img_width;
	int img_height;

	printf("%s", game -> str);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 700, 300, "junyoo");
	img_wall = mlx_xpm_file_to_image(mlx_ptr, "./asset/wall.xpm", &img_width, &img_height);
	img_tile = mlx_xpm_file_to_image(mlx_ptr, "./asset/tile.xpm", &img_width, &img_height);
	img_cat = mlx_xpm_file_to_image(mlx_ptr, "./asset/cat_right.xpm", &img_width, &img_height);
	img_rat = mlx_xpm_file_to_image(mlx_ptr, "./asset/rat.xpm", &img_width, &img_height);
	img_box = mlx_xpm_file_to_image(mlx_ptr, "./asset/box_open.xpm", &img_width, &img_height);

	char	*str = game -> str;

	int i = 0;
	while (height < game_height)
	{
		width = 0;
		while (width < game_width)
		{
			if (game -> str[i] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_wall, width * 50, height * 50);
			else if (game -> str[i] == '0')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_tile, width * 50, height * 50);
			else if (game -> str[i] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_cat, width * 50, height * 50);
			else if (game -> str[i] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_rat, width * 50, height * 50);
			else if (game -> str[i] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_box, width * 50, height * 50);
			width ++;
			i++;
		}
		height++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
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
	map_set(game);
}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c