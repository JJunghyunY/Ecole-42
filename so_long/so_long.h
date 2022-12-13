/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:02 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/12 22:20:28 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define TILE "./asset/tile.xpm"
# define WALL "./asset/wall.xpm"
# define RAT "./asset/rat.xpm"
# define BOX_OPEN "./asset/box_open.xpm"
# define BOX_CLOSE "./asset/box_close.xpm"
# define CAT_UP "./asset/cat_up.xpm"
# define CAT_DOWN "./asset/cat_down.xpm"
# define CAT_RIGHT "./asset/cat_right.xpm"
# define CAT_LEFT "./asset/cat_left.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		hei;
	int		wid;
	char	*str;
	int		c_rat;
	int		c_move;
	int		c_exit;
	char	**map;

	void	*tile;
	void	*wall;
	void	*cat_up;
	void	*cat_down;
	void	*cat_right;
	void	*cat_left;
	void	*rat;
	void	*box_close;
	void	*box_open;
}	t_game;

void	checkerset(t_game *checker, t_game *game);
int		end_game(t_game *game);
void	ret_error(char *errmsg);
void	print_cat_move(int c_move, int flag);
int		exit_game(t_game *game);

char	*solong_strjoin(char const *s1, char const *s2);
char	**str_to_matrix(char *str, int height, int width);
void	count_rat(t_game *game);
void	ft_putnbr(int n);

void	img_set(t_game *game);
void	map_set(t_game *game, int pressed_key, int c_rat);
void	map_read(char *filename, t_game *game);
void	put_box_image(t_game *g, int hei, int wid, int c_rat);
void	put_cat_image(t_game *game, int height, int width, int key_code);

int		deal_key(int key, t_game *game);
void	press_w(t_game *game);
void	press_a(t_game *game);
void	press_s(t_game *game);
void	press_d(t_game *game);

void	map_check(t_game *game);
int		check_pce(t_game *game);
int		check_around_wall(t_game *game);
int		cat_to_exit(t_game *game);
void	dfs(int x, int y, char **map, t_game *checker);

#endif