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
	src = (char *)malloc((slen + 1) * sizeof(char));
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

	if(!s)
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