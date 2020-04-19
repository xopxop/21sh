/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 11:22:29 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 18:18:07 by ihwang           ###   ########.fr       */
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
# include <dirent.h>
# include <fcntl.h>

# include "shell_error.h"
# include "ast.h"
# include "token.h"
# include "utilities.h"
# include "line_edition.h"
# include "sh.h"

#define READ_END 0
#define WRITE_END 1

# define NORM 0
# define CHILD_FAILURE 1
/* NORM and CHILD_FAILURE
** For ft_exit function,
** NORM, when a user types 'exit' and
** CHILD_FAILURE, when a child process has faild to
** execute the other binary
*/

typedef struct	s_exe
{
	int			ac;
	char		**av;
	char		*redirect_op;
	char		*redirect_des;
}				t_exe;

char **g_env;

typedef struct stat t_stat;
typedef struct dirent t_dir;

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
char		*is_in_path(t_exe *c);
void		make_child_path(t_exe *c, char *path/*, t_h **h*/);
void		make_child_binary(t_exe *c/*, t_h **h*/);
int			possible_to_access_dir(t_exe *c);
int			possible_to_access_file(t_exe *c);

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
void		ft_exit(t_exe *coms, int opt);
void		ft_cd(t_exe *c);
void		ft_setenv(t_exe *c);
void		ft_unsetenv(t_exe *c);

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

void	run (t_exe *exec);
void	get_av_cmd_name(t_astnode *ast, t_exe *exe);
void	get_av_cmd_suffix(t_astnode *ast, t_exe *exe);

#endif
