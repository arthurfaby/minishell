_END = "\033[0m"
_CYAN = "\033[0;36m"
_GREEN = "\033[0;32m"

NAME			= minishell

SRCS			= \
				minishell.c \
				\
				allocs/free.c \
				allocs/init.c \
				\
				builtins/cd/ft_cd.c \
				builtins/echo/ft_echo.c \
				builtins/env/ft_env.c \
				builtins/env/ft_env_modif.c \
				builtins/env/ft_env_utils.c \
				builtins/exit/ft_exit.c \
				builtins/export/ft_export.c \
				builtins/pwd/ft_pwd.c \
				builtins/unset/ft_unset.c \
				\
				exec/builtins.c \
				exec/child.c \
				exec/command.c \
				exec/exec.c \
				exec/pipe.c \
				exec/redirection.c \
				\
				parser.c \
				parser_utils.c \
				\
				prompt/prompt.c \
				\
				signal/handler.c \
				signal/signal.c \
				\
				tokenizer/free.c \
				tokenizer/get.c \
				tokenizer/set.c \
				tokenizer/tokenizer.c \
				tokenizer/tree.c \
				\
				parser/parser.c \
				parser/parser_treat.c \
				parser/parser_utils.c \
				parser/parser_size.c \
				parser/parser_size_utils.c \
				\

OBJS			= $(SRCS:.c=.o)

INCSDIR			= includes
SRCSDIR			= ./

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -Llibft -lft -Ilibft/includes -I$(INCSDIR) -L/usr/local/lib -I/usr/local/include -lreadline
RM				= rm -rf

.c.o:
				@echo $(_GREEN)
				@echo -n "Compiling minishell: $<..."
				@$(CC) $(CFLAGS) -c $< -o $@ 

all:			start $(NAME)

start:
				@echo $(_CYAN)
				@echo -n "MINISHELL"
				@echo $(_END)

$(NAME):		$(OBJS)
				@echo ""
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
