#include "get_next_line.h"

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

static char	*read_join_line(char *text, int fd)
{
	char	buf[BUFFER_SIZE+1];
	int		index;
	
	if (!text)
		text = my_strdup("");
	index = 1;
	while (index)
	{
		index = read(fd, buf, BUFFER_SIZE);
		buf[index] = '\0';
		text = my_strjoin(text, buf);
		if(!text)
		 	return (NULL);
		if (my_strchr(buf, '\n'))
			break;
	}
	return (text);
}

static char	*subtract_line(char *text)
{
	char	*subline;
	int		index;

	if (!text)
		return (NULL);
	index = 0;
	if (text)
	{
		if (text[0] == '\0')
			return (NULL);
	}
	while (text[index] != '\n' && text[index] != '\0')
		index++;
	subline = my_substr(text, 0, index);
	if (!subline)
		return (NULL);
	return (subline);
}

static char	*after_newline(char *text)
{
	int		index;
	char	*temp;

	if (text)
	{
		if (text[0] == '\0')
			return (NULL);
	}
	index = 0;
	while (text[index] != '\n' && text[index] != '\0')
		index++;
	temp = my_substr(text, index +1, my_strlen(text) - index);
	free(text);
	text = temp;
	return (text);
}

void	clear_list(t_list **lst, int fd)
{
    t_list	*prev;
    t_list	*seek;

    seek = *lst;
	if (seek->fd == fd)
	{
		seek = seek->next;
		free(seek);
		(*lst) = seek;
		return ;
	}
    while (seek && seek->fd != fd) 
		seek = seek->next;
	prev = seek;
	if (prev->fd == fd)
	{
		seek->next = prev->next;
		free(prev);
		return ;
	}
}

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
	if (!my_strchr(lst->text, '\n'))
		lst->text = read_join_line(lst->text, fd);
	ret_line = subtract_line(lst->text);
	lst->text = after_newline(lst->text);
	if (!ret_line)
	{
		free(lst->text);
//		clear_list(&lst, fd);
		free(lst);
	}
	return (ret_line);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd1;
	int fd2;
    char *line;
    
    fd1 = open("test.txt", O_RDONLY);
    line = get_next_line(fd1);
    printf("%p\n", line);
    printf("%s\n", line);
	line = get_next_line(fd1);
    printf("%p\n", line);
    printf("%s\n", line);

    fd2 = open("test.txt", O_RDONLY);
    line = get_next_line(fd2);
    printf("%p\n", line);
    printf("%s\n", line);

    // line = get_next_line(fd2);
    // printf("%p\n", line);
    // printf("%s\n", line);
	// line = get_next_line(fd1);
    // printf("%p\n", line);
    // printf("%s\n", line);


	close(fd1);
//	close(fd2);
    return (0);
}