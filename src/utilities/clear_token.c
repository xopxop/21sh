/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:56:39 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:45:41 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	clear_token(t_token *token)
{
	t_token *temp;

	while (token)
	{
		ft_strdel(&token->data);
		temp = token;
		token = token->next;
		free(temp);
	}
}
