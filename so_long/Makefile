# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:31:36 by junyoo            #+#    #+#              #
#    Updated: 2022/12/12 22:14:19 by junyoo           ###   ########.fr        #
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

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -l$(MLXNAME) $(MLXFLAGS) $^ -o $@ 
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY:	all clean fclean re
