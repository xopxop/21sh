/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:58:06 by dthan             #+#    #+#             */
/*   Updated: 2020/05/04 12:58:58 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** cmd_name : WORD     //Apply rule 7a
*/

t_astnode *cmd_name(t_token **token)
{
	return (word(token, TOKEN_SPECIFIER_NOT_HIPHEN));
}
