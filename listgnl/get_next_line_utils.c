/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:42:47 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/14 19:13:14 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;
	size_t	slen;

	if (!s || len <= 0)
		return (NULL);
	i = 0;
	slen = 0;
	if (start < my_strlen(s))
		slen = my_strlen(s) - (size_t)start;
	if (len < slen)
		slen = len;
	src = (char *)malloc(sizeof(char) * slen + 1);
	if (!src)
		return (NULL);
	while (slen && start < my_strlen(s))
	{
		src[i] = ((char *)s)[start + i];
		i++;
		slen--;
	}
	src[i] = '\0';
	return (src);
}

char	*my_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i +1);
		i++;
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
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
	str = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) +1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	clear_list(t_list **head, int fd, char *text)
{
	t_list	*prev;
	t_list	*seek;

	if (text)
		free(text);
	seek = *head;
	if (seek->fd == fd)
	{
		seek = seek->next;
		free(*head);
		(*head) = seek;
		return ;
	}
	while (seek)
	{
		if (seek->fd == fd)
		{
			prev->next = seek->next;
			free(seek);
			return ;
		}
		prev = seek;
		seek = seek->next;
	}
}
