#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct	s_list
{
	int				fd;
	char			*text;
	struct s_list	*next;
}				t_list;

char			*get_next_line(int fd);
static char     *subtract_line(char *text);
static char	    *read_join_line(char *text, int fd);
static char     *after_newline(char *text);
static t_list	*new_fd_lst(t_list **lst, int fd);
char	        *ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);

#endif