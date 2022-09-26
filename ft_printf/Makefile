# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 15:39:20 by junyoo            #+#    #+#              #
#    Updated: 2022/09/26 16:45:01 by junyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

AR	= ar
ARFLAGS	= rcs

RM	= rm -f

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all bonus clean fclean re
