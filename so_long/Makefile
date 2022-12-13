# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:31:36 by junyoo            #+#    #+#              #
#    Updated: 2022/12/12 17:42:13 by junyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MLXNAME		= mlx
MLXDIR		= ./mlx
MLXFLAGS	= -framework OpenGL -framework AppKit

RM			= rm -f

NAME		= so_long

SRCS		= so_long.c so_long_utils.c pressed_key.c map_check.c map_utils.c\
			get_next_line.c get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(SRCS)
	$(CC) $(CFLAGS) -L$(MLXDIR) -l$(MLXNAME) $(MLXFLAGS) $^ -o $@
	$(CC) $(CFLAGS) -c $(SRCS)
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY:	all clean fclean re
