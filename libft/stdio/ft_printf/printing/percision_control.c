/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:46:54 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 00:03:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	prec_ctrl_str(t_info *info, char **str)
{
	if (info->percision < 0)
		return ;
	if (ft_strlen(*str) <= (size_t)info->percision)
		return ;
	(*str)[info->percision] = '\0';
}

void	prec_ctrl_nums(t_info *info, char **str, int negative)
{
	char *new;
	char *orig;

	orig = *str;
	if (info->percision + negative <= (int)ft_strlen(*str))
	{
		if (info->percision == 0 && !(ft_strcmp("0", *str)))
			*str[0] = 0;
		return ;
	}
	if (negative)
		(*str)++;
	new = ft_strnew(info->percision + negative);
	ft_memset(new + negative, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + info->percision - ft_strlen(*str) + negative, *str);
	if (negative)
		new[0] = '-';
	free(orig);
	*str = new;
}

void	prec_ctrl_oct_hex(t_info *info, char **str)
{
	char	*new;

	if (info->percision <= (int)ft_strlen(*str))
	{
		if (info->percision == 0 && !(ft_strcmp("0", *str)))
			*str[0] = 0;
		return ;
	}
	new = ft_strnew(info->percision);
	ft_memset(new, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + info->percision - ft_strlen(*str), *str);
	free(*str);
	*str = new;
}
