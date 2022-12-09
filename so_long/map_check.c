/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:30:25 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/10 04:10:48 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	map_check(t_game *game)
{
	if (game->hei == game->wid)
		ret_error("Not a rectangular map");
	else if (check_pce(game))
		exit(0);
	else if (check_around_wall(game))
		ret_error("Map is not surrounded by wall");
	else if (cat_to_exit(game))
		ret_error("Map is not valid");
}

int	check_pce(t_game *game)
{
	if (!ft_strchr(game->str, 'P'))
	{
		perror ("There's no Cat in map");
		return (1);
	}
	else if (!ft_strchr(game->str, 'C'))
	{
		perror ("There's no Rat in map");
		return (1);
	}
	else if (!ft_strchr(game->str, 'E'))
	{
		perror ("There's no Box in map");
		return (1);
	}
	return (0);
}

int	check_around_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->str[i])
	{
		if (i <= game->wid)
			if (game->str[i] != '1')
				return (1);
		if (i % (game->wid) == 0)
		{
			if (game->str[i] != '1')
				return (1);
			else if (game->str[i + game->wid - 1] != '1')
				return (1);
		}
		if (i >= game->wid * (game->hei - 1))
			if (game->str[i] != '1')
				return (1);
		i++;
	}
	return (0);
}

int	cat_to_exit(t_game *game)
{
	int		i;
	int		j;
	t_game	*checker;

	checker = malloc(sizeof(t_game));
	checker->c_rat = game->c_rat;
	checker->c_exit = 1;
	checker->hei = game->hei;
	checker->wid = game->wid;
	checker->map = str_to_matrix(game->str, game->hei, game->wid);
	game->map = str_to_matrix(game->str, game->hei, game->wid);
	i = 0;
	while (i < game->hei)
	{
		j = 0;
		while (j < game->wid)
		{
			if (game->map[i][j] == 'P')
				dfs(i, j, game->map, checker);
			j++;
		}
		i++;
	}
	if (checker->c_exit != 0 || checker->c_rat != 0)
		return (1);
	return (0);
}

void	dfs(int x, int y, char **map, t_game *checker)
{
	int			i;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	if (checker->map[x][y] == '1')
		return ;
	checker->map[x][y] = '1';
	if (map[x][y] == '1')
		return ;
	else if (map[x][y] == 'E')
		checker->c_exit -= 1;
	else if (map[x][y] == 'C')
		checker->c_rat -= 1;
	i = 0;
	while (i < 4)
	{
		if (x + dx[i] < 5 || y + dy[i] < 13)
			dfs(x + dx[i], y + dy[i], map, checker);
		i++;
	}
}
