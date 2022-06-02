# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 11:58:53 by vnaud             #+#    #+#              #
#    Updated: 2022/06/01 13:45:59 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCS			= \
				minishell.h \
				\

SRCS			= \
				minishell.c \
				prompt.c \
				signal.c \
				\

OBJS			= $(SRCS:.c=.o)

INCSDIR			= ./
SRCSDIR			= ./

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -Llibft -lft -Ilibft/includes -I. -L/usr/local/lib -I/usr/local/include -lreadline
RM				= rm -rf

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $@ 

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -sC libft
				@$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
				@make clean -sC libft
				@$(RM) $(OBJS)

fclean:			clean
				@make fclean -sC libft
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
