NAME			= minishell

INCS			= \
				minishell.h \
				\

SRCS			= \
				init.c \
				minishell.c \
				prompt.c \
				parser.c \
				signal.c \
				ft_echo.c \
				ft_cd.c \
				ft_pwd.c \
				env.c \
				env_utils.c \
				env_modif.c \
				ft_export.c \
				ft_unset.c \
				free_data.c \
				parser_utils.c \
				tokenizer.c \
				tokenizer_utils.c \
				tree.c \
				ft_exec.c \
				ft_exec_utils.c \
				ft_exit.c \
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
