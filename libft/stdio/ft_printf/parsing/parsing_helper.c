/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:52:04 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:35:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
** ft_skip_atoi will take the number from the string
** Return value: the number from the str
*/

int	ft_skip_atoi(const char *format, size_t *pos)
{
	int i;

	i = 0;
	while (ft_isdigit(format[*pos]))
		i = i * 10 + format[(*pos)++] - '0';
	return (i);
}

int	ft_isspecifier(char specifier)
{
	char *list_specifier;

	list_specifier = "cspdiuoxXf%";
	while (list_specifier)
	{
		if (specifier == *list_specifier)
			return (1);
		list_specifier++;
	}
	return (0);
}
