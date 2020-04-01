NAME = 21sh

SRCS_PATH = src/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./libft/includes

SRCS_NAME = main.c \
			builtins.c \
			children.c \
			error1.c \
			error2.c \
			execute.c \
			ft_cd.c \
			ft_setenv.c \
			ft_unsetenv.c \
			in_path.c \
			intpt.c \
			parse.c \
			sig_handler.c \
			utill.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS_NAME:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(FLAGS) $(INC) $(SRCS)
	@gcc $(FLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	@make -C ./libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
