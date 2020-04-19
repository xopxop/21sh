/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:36:24 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:36:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_pipeline(t_astnode *ast, t_exe *exe)
{
	execute_pipe_sequence(ast, exe);
}
