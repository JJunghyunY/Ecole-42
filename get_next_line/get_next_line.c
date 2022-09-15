/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:42:57 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/16 05:22:31 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*new_fd_lst(t_list **lst, int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
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

char	*subtract_line(char *ret_line)
{
	char	*subline;
	int		index;

	if (!ret_line)
		return (NULL);
	index = 0;
	while (ret_line[index] != '\n' && ret_line[index] != '\0')
		index++;
	index++;
	subline = my_substr(ret_line, index, my_strlen(ret_line) - index);
	if (!subline)
		return (NULL);
	if (subline[0] == '\0')
	{
		free(subline);
		return (NULL);
	}
	ret_line[index] = '\0';
	return (subline);
}

static char	*read_join_line(char *text, int fd)
{
	char	buf[BUFFER_SIZE +1];
	char	*res;
	int		read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		if (read_size == -1)
			return (NULL);
		buf[read_size] = '\0';
		res = text;
		text = my_strjoin(text, buf);
		free(res);
		if (my_strchr(text, '\n'))
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = head;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (!lst)
	{
		lst = new_fd_lst(&head, fd);
		if (!lst)
			return (NULL);
	}
	ret_line = read_join_line(lst->text, fd);
	lst->text = subtract_line(ret_line);
	if (!ret_line)
		clear_list(&head, fd, lst->text);
	return (ret_line);
}
