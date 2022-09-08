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

static void	clear_list(t_list **head, int fd)
{
    t_list	*prev;
    t_list	*seek;

    seek = *head;
	if (seek->fd == fd)
	{
		seek = seek->next;
		free(*head);
		(*head) = seek;
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

static char	*after_newline(char *text, t_list **head, int fd)
{
	int		index;
	char	*temp;

	index = 0;
	while (text[index] != '\n' && text[index] != '\0')
		index++;
	temp = my_substr(text, index +1, my_strlen(text) - index);
	if (text[index] != '\n')
	{
		free(text);
		clear_list(head, fd);	
		return (NULL);
	}
	else
		free(text);
	return (temp);
}

char	*subtract_line(char *text)
{
	char	*subline;
	int		index;

	if (!text)
		return (NULL);
	index = 0;
	while (text[index] != '\n' && text[index] != '\0')
		index++;
	if (text[index] == '\n')
		subline = my_substr(text, 0, index +1);
	else
		subline = my_substr(text, 0, index);
	if (!subline)
		return (NULL);
	return (subline);
}

static char	*read_join_line(char *text, int fd)
{
	char	buf[BUFFER_SIZE+1];
	char  	*res;
	int   	read_size;
	
	if (!text)
		text = my_strdup("");
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		if (read_size == -1)
			return (NULL);
		buf[read_size] = '\0';
		res = my_strjoin(text, buf);
		free(text);
		text = my_strdup(res);
		free(res);
		if (my_strchr(buf, '\n'))
			break ;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
    t_list			*lst;
	char			*ret_line;

	ret_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
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
	if (!ret_line)
	{
		free(lst->text);
		clear_list(&head, fd);
	}
	else
		lst->text = after_newline(lst->text, &head, fd);
	return (ret_line);
}

