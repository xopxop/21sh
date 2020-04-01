/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:52:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 14:52:37 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# define KEY 1
# define VAL 0
# define PARENT 1
# define CHILD 0
# define SET 1
# define UNSET 0
# define F_TYPE_MASK 0170000
# define PRINT 1
# define ER 0

# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

char					**g_env;
int						g_status;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

typedef struct			s_cmd
{
	int					ac;
	char				**av;
	struct s_cmd		*next;
}						t_cmd;

void					print_semicolon_error(char *line);
void					print_is_dir(char *str);
void					print_no_cmd(char *str);
void					print_set_unset(char *str, int opt);
int						there_is_p(t_cmd *c);
int						there_is_d(t_cmd *c);
void					make_child_not_env(t_cmd *c);
void					make_child_env(t_cmd *c, char *path);
int						is_eof(char *line);
char					*is_in_path(t_cmd *c);
void					ft_pwd(void);
void					ft_echo(t_cmd *c);
void					ft_exit(t_cmd *comm, int opt);
void					ft_env(void);
void					ft_cd(t_cmd *c);
void					ft_unsetenv(t_cmd *c);
void					ft_setenv(t_cmd *c);
void					sig_controller(int option);
void					cmd_del(t_cmd *c);
char					*get_env(char *name, int keyval);
void					apply_t_d(t_cmd *c);
void					execute_cmd(t_cmd *c, char *path);
void					parse_line(char **line);
void					get_prompt(void);
#endif
