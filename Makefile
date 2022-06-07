NAME			= minishell

INCS			= \
				minishell.h \
				\

SRCS			= \
				init.c \
				minishell.c \
				prompt.c \
				command.c \
				parser.c \
				exec.c \
				signal.c \
				ft_echo.c \
				ft_cd.c \
				ft_pwd.c \
				ft_env.c \
				modif_env.c \
				ft_export.c \
				ft_unset.c \
				free_data.c \
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
