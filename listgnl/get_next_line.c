#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst;
	char			*ret_line;

	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);
	lst = head;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (!lst)
    {
		lst = new_fd_lst(&head, fd);
		if(!lst)
			return (NULL);
    }
	if (!ft_strchr(lst->text, '\n'))
		lst->text = read_join_line(lst->text, fd);
	ret_line = subtract_line(lst->text);
	lst->text = after_newline(lst->text);
	if (!ret_line)
	{
		free(lst->text);
//		clear_list(&head, fd);
	}
	// if (head == lst)
	// 	head=lst->next;
	return (ret_line);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static char *after_newline(char *text)
{
	int		i;

	if (text)
	{
		if (text[0] == '\0')
		return (NULL);
	}
	text = ft_strchr(text, '\n');
	return (text);
}

static char	*subtract_line(char *text)
{
	char	*subline;
	int		index;

	index = 0;
	if (text)
	{
		if (text[0] == '\0')
		return (NULL);
	}
	while (text[index] != '\n' && text[index] != '\0')
		index++;
	subline = ft_substr(text, 0, index -1);
	if (!subline)
		return (NULL);
	subline[index] = '\0';
	return (subline);
}

static char	*read_join_line(char *text, int fd)
{
	char	*buf;
	int		index;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if(!buf)
		return (NULL);
	index = read(fd, buf, BUFFER_SIZE);
	while (index > 0)
	{
		buf[index] = '\0';
		if(!text)
			text = ft_strdup("");
		text = ft_strjoin(text, buf);
		// if(!text)
		// 	return (NULL);
		if (ft_strchr(text, '\n'))
			break;
		index = read(fd, buf, BUFFER_SIZE);
	}
	return (text);
}

static t_list	*new_fd_lst(t_list **lst, int fd)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->fd = fd;
	new->text = NULL;
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return (new);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

char	*ft_strchr(const char *s, int c)
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


#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%p\n", line);
    printf("%s\n", line);
    close(fd);

    line = get_next_line(fd);
    printf("%p\n", line);
    printf("%s\n", line);


    line = get_next_line(fd);
    printf("%p\n", line);
    printf("%s\n", line);
    return (0);
}