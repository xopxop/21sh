# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 09:14:51 by dthan             #+#    #+#              #
#    Updated: 2020/03/25 09:14:54 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/error.c srcs/helper.c\
srcs/internal_cmd/cd_cmd.c srcs/internal_cmd/echo_cmd.c srcs/internal_cmd/env_cmd.c \
srcs/internal_cmd/exit_cmd.c srcs/internal_cmd/setenv_cmd.c \
srcs/internal_cmd/unsetenv_cmd.c

SRCS_OBJ = main.o error.o helper.o\
cd_cmd.o echo_cmd.o env_cmd.o exit_cmd.o setenv_cmd.o unsetenv_cmd.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS_CODES) 
	@gcc $(CFLAGS) $(SRCS_OBJ) libft/libft.a -o $(NAME)
	@echo "\033[32mCreated Minishell\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@rm -f $(NAME)
	@echo "\033[32mRemoved and Minishell\033[0m"

re: fclean all
