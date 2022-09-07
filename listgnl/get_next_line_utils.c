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

	if (!s)
		return (NULL);
	slen = my_strlen(s);
	if (start > slen)
		return (my_strdup(""));
	if (slen > len)
		src = (char *)malloc(sizeof(char) * len + 1);
	if (slen <= len)
		src = (char *)malloc(sizeof(char) * slen - start + 1);
	if (!src)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		src[i] = s[start];
		start++;
		i++;
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

	if (!s1 || !s2)
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

// char	*my_strdup(const char *s1)
// {
// 	char	*str;
// 	int		i;

// 	str = (char *)malloc(sizeof(char) * (my_strlen(s1) +1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// size_t	my_strlen(const char *s)
// {
// 	size_t	len;

// 	if (s == NULL)
// 		return (0);
// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// char	*my_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*src;
// 	size_t	i;
// 	size_t	slen;

// 	if (!s)
// 		return (NULL);
// 	slen = my_strlen(s);
// 	if (start > slen)
// 		return (my_strdup(""));
// 	if (slen > len)
// 		src = (char *)malloc(sizeof(char) * len + 1);
// 	if (slen <= len)
// 		src = (char *)malloc(sizeof(char) * slen - start + 1);
// 	if (!src)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && s[i])
// 	{
// 		src[i] = s[start];
// 		start++;
// 		i++;
// 	}
// 	src[i] = '\0';
// 	return (src);
// }

// char	*my_strchr(const char *s, int c)
// {
// 	int				i;
// 	unsigned char	ch;

// 	if(!s)
// 		return (NULL);
// 	ch = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == ch)
// 			return ((char *)s + i +1);
// 		i++;
// 	}
// 	if (s[i] == ch)
// 		return ((char *)s + i);
// 	return (NULL);
// }

// char	*my_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) +1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }