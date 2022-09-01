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
#include <unistd.h>
#define BUFFER_SIZE 1000

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memset(void	*b, int c, size_t	len);
static int	count(char const *s, char c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);



char	*get_next_line(int fd)
{
	static char		**split_ret;
	char		*line_ret;
	char		*temp;
	int			index;

	if (split_ret)
		return (*split_ret++);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	index = read (fd, temp, BUFFER_SIZE);
	while (index)
	{
		line_ret = ft_strjoin(line_ret, temp);
		ft_memset(temp, 0x00, BUFFER_SIZE);
		index = read (fd, temp, BUFFER_SIZE);
	}
	split_ret = ft_split(line_ret, '\n');
	return (*split_ret++);
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

void	*ft_memset(void	*b, int c, size_t	len)
{
	int				i;
	unsigned char	*temp;
	unsigned char	ch;

	temp = b;
	ch = c;
	i = 0;
	while (len--)
	{
		temp[i] = ch;
		i++;
	}
	return (b);
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
				cnt++;
	}
	return (cnt);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) +1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen > len)
		src = (char *)malloc(sizeof(char) * len + 1);
	if (slen <= len)
		src = (char *)malloc(sizeof(char) * slen - start + 1);
	if (!src)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		src[i] = s[start];
		start++;
		i++;
	}
	src[i] = '\0';
	return (src);
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

int	ret_split(char **ret, char const *s, char c)
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
			if (i - flag)
			{
				ret[++ret_idx] = ft_substr(s, flag, i - flag);
				if (!ret)
					return (ret_idx +1);
			}
			flag = i +1;
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
	char	**ret;
	int		checker;

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

#include <stdio.h>
int	main(void)
{
	int		temp;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}