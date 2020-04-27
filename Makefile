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

NAME = 21sh

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/error.c \
srcs/environ/tool_for_env.c \
srcs/lexer/lexical_analysis.c \
srcs/lexer/get_token_info.c \
srcs/lexer/lexer_helper.c \
srcs/utilities/tool_for_checking.c \
srcs/parser/syntax_analysis.c \
srcs/parser/AST/and_or.c \
srcs/parser/AST/ast_tool.c \
srcs/parser/AST/cmd_name.c \
srcs/parser/AST/cmd_suffix.c \
srcs/parser/AST/word.c \
srcs/parser/AST/command.c \
srcs/parser/AST/complete_command.c \
srcs/parser/AST/file_name.c \
srcs/parser/AST/io_file.c \
srcs/parser/AST/io_here.c \
srcs/parser/AST/io_redirect.c \
srcs/parser/AST/list.c \
srcs/parser/AST/pipe_sequence.c \
srcs/parser/AST/pipeline.c \
srcs/parser/AST/simple_command.c \
srcs/parser/AST/here_end.c \
srcs/parser/print_ast.c \
srcs/executor/executor.c \
srcs/executor/executor_tools.c \
srcs/executor/internal_cmd/cd_cmd.c \
srcs/executor/internal_cmd/echo_cmd.c \
srcs/executor/internal_cmd/env_cmd.c \
srcs/executor/internal_cmd/exit_cmd.c \
srcs/executor/internal_cmd/setenv_cmd.c \
srcs/executor/internal_cmd/unsetenv_cmd.c \
srcs/executor/execute_ast/execute_complete_command.c \
srcs/executor/execute_ast/execute_list.c \
srcs/executor/execute_ast/execute_and_or.c \
srcs/executor/execute_ast/execute_pipeline.c \
srcs/executor/execute_ast/execute_pipe_sequence.c \
srcs/executor/execute_ast/execute_command.c \
srcs/executor/execute_ast/execute_simple_command.c \
srcs/executor/execute_ast/execute_cmd_name.c \
srcs/executor/execute_ast/execute_cmd_suffix.c

SRCS_OBJ = main.o error.o \
tool_for_env.o  \
lexical_analysis.o get_token_info.o lexer_helper.o \
tool_for_checking.o \
syntax_analysis.o \
and_or.o \
ast_tool.o \
cmd_name.o \
cmd_suffix.o \
word.o \
command.o \
complete_command.o \
file_name.o \
io_file.o \
io_here.o \
io_redirect.o \
list.o \
pipe_sequence.o \
pipeline.o \
simple_command.o \
here_end.o \
print_ast.o \
executor.o \
executor_tools.o \
cd_cmd.o \
echo_cmd.o \
env_cmd.o \
exit_cmd.o \
setenv_cmd.o \
unsetenv_cmd.o \
execute_complete_command.o \
execute_list.o \
execute_and_or.o \
execute_pipeline.o \
execute_pipe_sequence.o \
execute_command.o \
execute_simple_command.o \
execute_cmd_name.o \
execute_cmd_suffix.o

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
