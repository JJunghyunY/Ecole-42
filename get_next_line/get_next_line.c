/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:42:57 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/01 16:58:59 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	static char	*line_saved;
	char		*line_got;
	int			index;

	if (fd > 0)
		return (NULL);
	line_got = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line_got)
		return (NULL);
	index = read (fd, line_got, BUFFER_SIZE);
	while (0 < index)
	{
		index = read (fd, line_got, BUFFER_SIZE);
		line_got[index] = '\0';
		line_saved = ft_strjoin(line_saved, line_got);
	}
	free (line_got);
	line_got = NULL;
	return (line_saved);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
