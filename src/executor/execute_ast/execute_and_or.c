/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_and_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:35:52 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:35:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_and_or(t_astnode *ast, t_exe *exe)
{
	execute_pipeline(ast, exe);
}
