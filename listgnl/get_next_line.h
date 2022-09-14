/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:48:12 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/14 19:12:55 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*text;
	struct s_list	*next;
}	t_list;

char			*get_next_line(int fd);
void			clear_list(t_list **head, int fd, char *text);
size_t			my_strlen(const char *s);
char			*my_substr(char const *s, unsigned int start, size_t len);
char			*my_strchr(const char *s, int c);
char			*my_strjoin(char const *s1, char const *s2);

#endif