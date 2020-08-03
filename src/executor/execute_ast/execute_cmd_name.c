/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 10:50:56 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 02:28:34 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_av_cmd_name(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_WORD)
	{
		exe->ac = 1;
		exe->av[0] = ast->data;
		exe->av[1] = NULL;
	}
}
