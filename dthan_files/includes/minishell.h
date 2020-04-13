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

// typedef struct			s_builtin
// {
// 	char				*command;
// 	void				(*func)(char**);
// }						t_builtin;

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

#endif
