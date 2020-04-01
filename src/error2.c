/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:03:11 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 15:50:10 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	print_semicolon_error(char *line)
{
	ft_putstr("syntax error near unexpected token `;'\n");
	ft_strdel(&line);
}
