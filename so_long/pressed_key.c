/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressed_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:57:54 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/10 04:14:09 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	deal_key(int key, t_game *game)
{
	if (key == 13)
		press_w(game);
	else if (key == 0)
		press_a(game);
	else if (key == 1)
		press_s(game);
	else if (key == 2)
		press_d(game);
	else if (key == 53)
		exit(0);
	return (0);
}

void	press_w(t_game *game)
{
	int	i;

	i = 1;
	while (i++)
		if (game->str[i] == 'P')
			break ;
	if (game->str[i - game->wid] == 'C')
		game->c_rat -= 1;
	if (game->str[i - game->wid] == 'E' && game->c_rat == 0)
		end_game(game);
	else if (game->str[i - game->wid] != '1' && game->str[i - game->wid] != 'E')
	{
		game->str[i] = '0';
		game->str[i - game->wid] = 'P';
		game->c_move += 1;
		map_set(game, 13, game->c_rat);
	}
}

void	press_a(t_game *game)
{
	int	i;

	i = 1;
	while (i++)
		if (game->str[i] == 'P')
			break ;
	if (game->str[i -1] == 'C')
		game->c_rat -= 1;
	if (game->str[i -1] == 'E' && game->c_rat == 0)
		end_game(game);
	else if (game->str[i -1] != '1' && game->str[i -1] != 'E')
	{
		game->str[i] = '0';
		game->str[i -1] = 'P';
		game->c_move += 1;
		map_set(game, 0, game->c_rat);
	}
}

void	press_s(t_game *game)
{
	int	i;

	i = 1;
	while (i++)
		if (game->str[i] == 'P')
			break ;
	if (game->str[i + game->wid] == 'C')
		game->c_rat -= 1;
	if (game->str[i + game->wid] == 'E' && game->c_rat == 0)
		end_game(game);
	else if (game->str[i + game->wid] != '1' && game->str[i + game->wid] != 'E')
	{
		game->str[i] = '0';
		game->str[i + game->wid] = 'P';
		game->c_move += 1;
		map_set(game, 1, game->c_rat);
	}
}

void	press_d(t_game *game)
{
	int	i;

	i = 1;
	while (i++)
		if (game->str[i] == 'P')
			break ;
	if (game->str[i + 1] == 'C')
		game->c_rat -= 1;
	if (game->str[i + 1] == 'E' && game->c_rat == 0)
		end_game(game);
	else if (game->str[i + 1] != '1' && game->str[i + game->wid] != 'E')
	{
		game->str[i] = '0';
		game->str[i +1] = 'P';
		game->c_move += 1;
		map_set(game, 2, game->c_rat);
	}
}
