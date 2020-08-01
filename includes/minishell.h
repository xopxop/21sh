/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 11:22:29 by dthan             #+#    #+#             */
/*   Updated: 2020/07/30 03:15:00 by ihwang           ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <dirent.h>
# include <fcntl.h>
# include <term.h>
# include <termios.h>

# include "shell_error.h"
# include "ast.h"
# include "token.h"
# include "utilities.h"
# include "line_edition.h"

#define READ_END 0
#define WRITE_END 1

# define PARENT 1 //For signal
# define CHILD 0 // For signal
# define F_TYPE_MASK 0170000 //For ft_cd
# define KEY 1//For get_env
# define VAL 0//For get_env
/* NORM and CHILD_FAILURE
** For ft_exit function,
** NORM, when a user types 'exit' and
** CHILD_FAILURE, when a child process has faild to
** execute the other binary
*/

typedef struct 			s_heredoc
{
	char				*heredoc;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct 			s_redirect
{
	char				*redirect_op;
	char				*redirect_src;
	char				*redirect_des;
	struct s_redirect	*next;
}						t_redirect;

typedef struct	s_exe
{
	int			ac;
	char		**av;
	t_redirect	*redi;
	t_heredoc	*heredoc;
}				t_exe;

char **g_env;
int						g_status;

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

char					*get_env(char *name, int keyval);
int	ft_isspace(int c);
char	*ft_strndup(char *str, size_t len);
void	ft_arraydel(char **string_array);
char		*is_in_path(t_exe *c);
void		make_child_path(t_exe *c, char *path);
void		make_child_binary(t_exe *c);
int			possible_to_access_dir(t_exe *c);
int			possible_to_access_file(t_exe *c);

/*
** Prompt
*/

void					get_prompt(void);
//char	*get_input(int level);

/*
** Commands
*/

void		ft_env(void);
void		ft_pwd(void);
void		ft_echo(t_exe *c);
void		ft_exit(int opt);
void		ft_cd(t_exe *c);
void		ft_setenv(t_exe *c);
void		ft_unsetenv(t_exe *c);

/*
** Signal
*/

void					sig_controller(int option);
void					post_signal(t_l *l);
int						iseof_in_line(char * line);
void					eof_handler(t_l *l);

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

void	find_heredoc(t_astnode *ast, t_exe *exe);
void	run (t_exe *exec);
void	get_av_cmd_name(t_astnode *ast, t_exe *exe);
void	get_av_cmd_suffix(t_astnode *ast, t_exe *exe, int opt);

void clear_exe(t_exe *exe);
#endif
