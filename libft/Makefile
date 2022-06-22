# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 20:27:25 by vnaud             #+#    #+#              #
#    Updated: 2022/06/22 13:48:52 by vnaud            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END="\033[0m"
_GREY="\033[0;30m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_BLUE="\033[0;34m"
_PURPLE="\033[0;35m"
_CYAN="\033[0;36m"
_WHITE="\033[0;37m"

NAME			= libft.a

INCS			= \
				includes/libft.h \
				includes/libchar.h \
				includes/liblst.h \
				includes/libmem.h \
				includes/libprint.h \
				includes/libstr.h \
				includes/ft_gnl.h \
				includes/ft_printf.h \
				includes/liberr.h \
				\

SRCS			= \
				ft_gnl/get_next_line.c \
				ft_gnl/get_next_line_utils.c \
				\
				ft_printf/ft_printf.c \
				\
				libchar/ft_isalnum.c \
				libchar/ft_isalpha.c \
				libchar/ft_isascii.c \
				libchar/ft_isdigit.c \
				libchar/ft_isgraph.c \
				libchar/ft_islower.c \
				libchar/ft_isprint.c \
				libchar/ft_ispunct.c \
				libchar/ft_isspace.c \
				libchar/ft_isupper.c \
				libchar/ft_iswhitespace.c \
				libchar/ft_tolower.c \
				libchar/ft_toupper.c \
				\
				liberr/ft_exit_msg.c \
				liberr/ft_usage_err.c \
				\
				liblst/ft_lstadd_back.c \
				liblst/ft_lstadd_front.c \
				liblst/ft_lstclear.c \
				liblst/ft_lstdelone.c \
				liblst/ft_lstiter.c \
				liblst/ft_lstlast.c \
				liblst/ft_lstmap.c \
				liblst/ft_lstnew.c \
				liblst/ft_lstsize.c \
				\
				libmem/ft_bzero.c \
				libmem/ft_calloc.c \
				libmem/ft_memalloc.c \
				libmem/ft_memccpy.c \
				libmem/ft_memchr.c \
				libmem/ft_memcmp.c \
				libmem/ft_memcpy.c \
				libmem/ft_memdel.c \
				libmem/ft_memmove.c \
				libmem/ft_memndel.c \
				libmem/ft_memset.c \
				\
				libprint/ft_putchar.c \
				libprint/ft_putchar_fd.c \
				libprint/ft_putendl.c \
				libprint/ft_putendl_fd.c \
				libprint/ft_puthex.c \
				libprint/ft_putnbr.c \
				libprint/ft_putnbr_fd.c \
				libprint/ft_putnstr.c \
				libprint/ft_putnstr_fd.c \
				libprint/ft_putptr.c \
				libprint/ft_putsstr.c \
				libprint/ft_putsstr_fd.c \
				libprint/ft_putstr.c \
				libprint/ft_putstr_fd.c \
				libprint/ft_putunbr.c \
				\
				libstr/ft_atoi.c \
				libstr/ft_atoi_base.c \
				libstr/ft_atol.c \
				libstr/ft_itoa.c \
				libstr/ft_itoa_base.c \
				libstr/ft_strcat.c \
				libstr/ft_strcdup.c \
				libstr/ft_strchr.c \
				libstr/ft_strclear.c \
				libstr/ft_strcmp.c \
				libstr/ft_strcnew.c \
				libstr/ft_strcpy.c \
				libstr/ft_strdup.c \
				libstr/ft_strequ.c \
				libstr/ft_striteri.c \
				libstr/ft_strjoin.c \
				libstr/ft_strlcat.c \
				libstr/ft_strlcpy.c \
				libstr/ft_strlen.c \
				libstr/ft_strmapi.c \
				libstr/ft_strncat.c \
				libstr/ft_strncmp.c \
				libstr/ft_strncpy.c \
				libstr/ft_strndup.c \
				libstr/ft_strnequ.c \
				libstr/ft_strnew.c \
				libstr/ft_strnstr.c \
				libstr/ft_strrchr.c \
				libstr/ft_strsplit.c \
				libstr/ft_strstr.c \
				libstr/ft_strsub.c \
				libstr/ft_strtolower.c \
				libstr/ft_strtoupper.c \
				libstr/ft_strtrim.c \
				libstr/ft_sstrdel.c \
				libstr/ft_sstrdup.c \
				\

INCSDIR			= includes/
SRCSDIR			= srcs/
OBJDIR			= objs/
OBJPATH			= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf

all:			start $(NAME)
				@echo $(_END)

start:
				@echo $(_CYAN)
				@echo -n "LIBFT"
				@echo $(_END)

$(NAME):		$(OBJDIR) $(OBJPATH)
				@ar rcs $(NAME) $(OBJPATH)

$(OBJDIR)%.o:	$(SRCSDIR)%.c $(INCS)
				@echo $(_GREEN)
				@echo -n "Compiling libft: $<..."
				@$(CC) -c $< -o $@ $(CFLAGS) -I $(INCSDIR)

$(OBJDIR):
				@mkdir -p $(OBJDIR)
				@mkdir -p $(dir $(OBJPATH))

clean:
				@echo $(_RED)
				@echo -n "clean libft..."
				@echo $(_END)
				@$(RM) $(OBJDIR)

fclean:			clean
				@echo $(_RED)
				@echo -n "fclean libft..."
				@echo $(_END)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
