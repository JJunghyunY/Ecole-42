/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:41:44 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/12 16:42:08 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	checkerset(t_game *checker, t_game *game)
{
	checker->c_rat = game->c_rat;
	checker->c_exit = 1;
	checker->hei = game->hei;
	checker->wid = game->wid;
	checker->map = str_to_matrix(game->str, game->hei, game->wid);
	game->map = str_to_matrix(game->str, game->hei, game->wid);
}

char	*solong_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2 != '\n')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	**str_to_matrix(char *str, int height, int width)
{
	char	**matrix;
	int		i;
	int		j;

	matrix = (char **)malloc(sizeof(char *) * (height +1));
	if (!matrix)
		ret_error("malloc failed");
	i = 0;
	j = 0;
	while (i < height)
	{
		matrix[i] = ft_substr(str, i * width, width);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	count_rat(t_game *game)
{
	int	i;
	int	c_rat;
	int	c_cat;
	int	c_exit;

	i = 0;
	c_rat = 0;
	c_cat = 1;
	c_exit = 1;
	while (game->str[i])
	{
		if (game->str[i] == 'C')
			c_rat ++;
		else if (game->str[i] == 'P')
			c_cat --;
		else if (game->str[i] == 'E')
			c_exit --;
		else if (game->str[i] != '0' && game->str[i] != '1')
			ret_error("unexpected input on map");
		i++;
	}
	if (c_cat || c_exit)
		ret_error("There must be only one of Cat and Exit");
	game->c_rat = c_rat;
	game->c_move = 0;
}

void	ft_putnbr(int n)
{
	long long	temp;
	int			i;
	char		str[15];

	temp = (long long)n;
	i = 0;
	if (n < 0)
	{
		temp *= -1;
		write (1, "-", 1);
	}
	else if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	while (temp)
	{
		str[i++] = (temp % 10) + '0';
		temp /= 10;
	}
	while (--i >= 0)
		write(1, str + i, 1);
}
