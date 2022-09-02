/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:42:47 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/02 12:06:47 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	count(char const *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	if (c == '\0')
		return (1);
	while (s[++i])
	{
		if (s[i] != c)
			if (s[i +1] == c || s[i +1] == '\0')
				cnt += 2;
	}
	return (cnt);
}

static char	**split_free(char **str, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		free(str[i]);
		i++;
	}
	return (NULL);
}

static int	ret_split(char **ret, char const *s, char c)
{
	size_t	i;
	int		ret_idx;
	int		flag;

	i = 0;
	ret_idx = -1;
	flag = 0;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (i - flag > 0)
			{
				ret[++ret_idx] = ft_substr(s, flag, i - flag);
				if (!ret)
					return (ret_idx +1);
			}
			flag = i;
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
	ret[ret_idx + 1] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char    **ret;
	int	    checker;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!ret)
		return (NULL);
	checker = ret_split(ret, s, c);
	if (checker)
		return (split_free(ret, checker -1));
	return (ret);
}