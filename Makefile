# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 11:58:53 by vnaud             #+#    #+#              #
#    Updated: 2022/06/02 08:25:19 by vnaud            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCS			= \
				minishell.h \
				\

SRCS			= \
				minishell.c \
				prompt.c \
				command.c \
				parser.c \
				exec.c \
				\

OBJS			= $(SRCS:.c=.o)

INCSDIR			= ./
SRCSDIR			= ./

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -Llibft -lft -Ilibft/includes -I.
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
