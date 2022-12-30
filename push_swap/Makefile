# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 11:19:13 by junyoo            #+#    #+#              #
#    Updated: 2022/12/30 17:33:32 by junyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= push_swap

LIBFT_DIR	= ./libft
LIBFT		= libft.a

SRCS		= push_swap.c arg_check.c deque.c deque_utils.c sort_sandglass.c \
			cmd_push.c cmd_swap.c cmd_rotate.c cmd_reverse_rotate.c

OBJS		= $(SRCS:.c=.o)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

$(NAME):	$(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@ 

all:	$(NAME)
	
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY:	all clean fclean re
