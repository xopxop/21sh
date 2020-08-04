/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shell_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:56:58 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:46:08 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		increment_shlvl(void)
{
	char	*shlvl;
	int		nb;
	char	*ascii;

	shlvl = get_env("SHLVL", VAL);
	shlvl++;
	nb = ft_atoi(shlvl);
	nb++;
	ascii = ft_itoa(nb);
	ft_strcpy(shlvl, ascii);
	ft_strdel(&ascii);
}
