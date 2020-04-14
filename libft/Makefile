# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 19:29:47 by ihwang            #+#    #+#              #
#    Updated: 2020/03/23 01:05:15 by ihwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS_PATH = obj/
SRCS_PATH = src/

SRCS_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_itoh.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
			ft_memset.c ft_nbrlen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
			ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
			ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
			ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			get_next_line.c ft_strstr_e.c ft_strlst_del.c ft_is_d_quote.c \
			ft_strtrim_d_quote.c ft_addchar.c ft_iswhite.c ft_split_d_quote.c \
			ft_split_shell.c ft_check_d_quote.c ft_isext.c \


OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS) includes/libft.h
	@ar rc $(NAME) $(OBJS)
	@ranlib $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -I includes -c $< -o $@

clean:
	@/bin/rm -rf obj/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
