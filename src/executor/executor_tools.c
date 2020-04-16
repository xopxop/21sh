/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:48:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:48:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		count_av(t_astnode *ast)
{
	int ct;

	ct = 0;
	while (ast)
	{
		ct++;
		ast = ast->right;
	}
	return (ct);
}

void	create_av(t_astnode *ast, char **av)
{
	int i;

	i = 0;
	av[i++] = ft_strdup(ast->left->data);
	if (ast->right && (ast->right->type != AST_cmd_suffix))
		av[i++] = ft_strdup(ast->right->data);
	else if (ast->right && (ast->right->type == AST_cmd_suffix))
	{
		ast = ast->right;
		while (ast && ast->type == AST_cmd_suffix)
		{
			av[i++] = ft_strdup(ast->left->data);
			ast = ast->right;
		}
		av[i++] = ft_strdup(ast->data);
	}
	av[i] = NULL;
}
