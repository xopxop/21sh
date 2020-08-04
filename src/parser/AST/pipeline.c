/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:32:29 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:45:05 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** pipeline :      pipe_sequence
**          | Bang pipe_sequence    //not
*/

t_astnode	*pipeline(t_token **token)
{
	return (pipe_sequence(token));
}
