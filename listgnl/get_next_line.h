#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    int             fd;
    char            *text;
    struct s_list   *next;
} t_list;

char			*get_next_line(int fd);
char	        *my_strdup(const char *s1);
size_t			my_strlen(const char *s);
char			*my_substr(char const *s, unsigned int start, size_t len);
char			*my_strchr(const char *s, int c);
char			*my_strjoin(char const *s1, char const *s2);

#endif