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
# include <sys/vlimit.h>

# include "shell_error.h"
# include "ast.h"
# include "token.h"
# include "utilities.h"
# include "sh.h"

typedef struct	s_exe
{
	int			ac;
	char		**av;
}				t_exe;

char **g_env;

/*
**	Lexer
*/

t_token	*lexical_analysis(char *input);

/*
**	Parser
*/

t_astnode	*syntax_analysis(t_token *token);


/*
** Utilities
*/

int	ft_isspace(int c);
char	*ft_strndup(char *str, size_t len);
void	ft_arraydel(char **string_array);

/*
** Prompt
*/

char	*get_input(int level);

/*
** Commands
*/

void		ft_env(void);
void		ft_pwd(void);
void		ft_echo(t_exe *c);

/*
** Executor
*/

void executor(t_astnode *ast);

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

void run (t_exe *exec);

#endif
