/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:45:09 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 15:54:16 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** command : simple_command
**         | compound_command					//not
**         | compound_command redirect_list		//not
**         | function_definition				//not
*/

t_astnode	*command(t_token **token)
{
	return (simple_command(token));
}
