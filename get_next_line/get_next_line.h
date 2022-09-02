/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:48:12 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/02 12:08:11 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 199

char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
static char		*ft_strjoin(char const *s1, char const *s2);
static void		*ft_memset(void	*b, int c, size_t	len);
static char		*ft_strdup(const char *s1);
static int		count(char const *s, char c);
static char		**split_free(char **str, size_t idx);
static int		ret_split(char **ret, char const *s, char c);

#endif
