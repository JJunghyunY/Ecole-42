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

char	*my_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (my_strlen(s1) +1));
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

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	// char	*src;
	// size_t	i;
	// size_t	slen;

	// if (!s)
	// 	return (NULL);
	// slen = my_strlen(s);
	// if (start > slen)
	// 	return (my_strdup(""));
	// if (slen > len)
	// 	src = (char *)malloc(sizeof(char) * len + 1);
	// if (slen <= len)
	// 	src = (char *)malloc(sizeof(char) * slen - start + 1);
	// if (!src)
	// 	return (NULL);
	// i = 0;
	// while (i < len && s[start])
	// {
	// 	src[i] = s[start];
	// 	start++;
	// 	i++;
	// }
	// src[i] = '\0';
	// return (src);
    char	*p;
	size_t	i;
	size_t	num_chars;

	i = 0;
	num_chars = 0;
	if (!s || len <= 0)
		return (NULL);
	if (start < my_strlen(s))
		num_chars = my_strlen(s) - (size_t)start;
	if (len < num_chars)
		num_chars = len;
	p = (char *)malloc((num_chars + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (num_chars && start < my_strlen(s))
	{
		p[i] = ((char *)s)[start + i];
		i++;
		num_chars--;
	}
	p[i] = '\0';
	return (p);
}

char	*my_strchr(const char *s, int c)
{
	// int				i;
	// unsigned char	ch;

	// if(!s)
	// 	return (NULL);
	// ch = (unsigned char)c;
	// i = 0;
	// while (s[i])
	// {
	// 	if (s[i] == ch)
	// 		return ((char *)s + i +1);
	// 	i++;
	// }
	// if (s[i] == ch)
	// 	return ((char *)s + i);
	// return (NULL);
    int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{	
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) +1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd1;
// 	int fd2;
//     char *line;
    
//     fd1 = open("test.txt", O_RDONLY);
//     line = get_next_line(fd1);
//     printf("%p\n", line);
//     printf("%s\n", line);
// 	line = get_next_line(fd1);
//     printf("%p\n", line);
//     printf("%s\n", line);

//     fd2 = open("test.txt", O_RDONLY);
//     line = get_next_line(fd2);
//     printf("%p\n", line);
//     printf("%s\n", line);

//     // line = get_next_line(fd2);
//     // printf("%p\n", line);
//     // printf("%s\n", line);
// 	// line = get_next_line(fd1);
//     // printf("%p\n", line);
//     // printf("%s\n", line);


// 	close(fd1);
// //	close(fd2);
//     return (0);
// }