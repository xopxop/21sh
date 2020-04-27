/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 11:22:29 by dthan             #+#    #+#             */
/*   Updated: 2020/03/26 11:25:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/signal.h>
// # include <sys/vlimit.h>
# include <stdio.h>

# include "shell_error.h"
# include "ast.h"
# include "token.h"
# include "utilities.h"
#define READ_END 0
#define WRITE_END 1

typedef struct			s_builtin
{
	char				*command;
	void				(*func)(char**);
}						t_builtin;

typedef struct	s_exe
{
	int			ac;
	char		**av;
	char		*redirect_op;
	char		*redirect_des;
	char		*redirect_src;
}				t_exe;

char **env;

/*
**	Environ
*/

char			**ft_new_env(char *var_name, char *var_value, int step, char **env);
char			*ft_call_var(char *var_name);
char			*ft_call_value_of(char *var_name);

/*
**	Lexer
*/

t_token	*lexical_analysis(char *input);

/*
**	Parser
*/

t_astnode	*syntax_analysis(t_token *token);

void printBinaryTree(t_astnode * t);

/*
** Executor
*/
void executor(t_astnode *ast);

void	cd_cmd(char **tokens);
void	echo_cmd(char **args);
void	env_cmd(char **tokens);
void	exit_cmd(char **tokens);
void	setenv_cmd(char **tokens);
void		unsetenv_cmd(char **var_name);


void execute_complete_command(t_astnode *ast, t_exe *exe);
void execute_list(t_astnode *ast, t_exe *exe);
void execute_and_or(t_astnode *ast, t_exe *exe);
void execute_command(t_astnode *ast, t_exe *exe);
void execute_pipeline(t_astnode *ast, t_exe *exe);
void execute_pipe_sequence(t_astnode *ast, t_exe *exec);
void execute_command(t_astnode *ast, t_exe *exe);
void execute_simple_command(t_astnode *ast, t_exe *exe);

/*
** Executor tool
*/

int		count_av(t_astnode *ast);
void	create_av(t_astnode *ast, char **av);

void	run (t_exe exec);
void	get_av_cmd_name(t_astnode *ast, t_exe *exe);
void	get_av_cmd_suffix(t_astnode *ast, t_exe *exe);

#endif
