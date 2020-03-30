/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:03:31 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 01:39:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	pad_right(t_info *info, char **str, char *new)
{
	char	extra;
	int		hash;

	extra = (!ft_isdigit((*str)[0]) && (info->specifier == spec_int \
				|| info->specifier == spec_float)) ? (*str)[0] : 0;
	hash = (info->flags & HASH_SIGN && (info->specifier == spec_hexupcase || \
				info->specifier == spec_hexlowcase)) ? 2 : 0;
	if (info->flags & ZERO)
	{
		ft_strncpy(new, *str, hash);
		ft_memset(new + hash + !!extra, '0', info->field_width - \
				ft_strlen(*str) + !!extra);
		if (extra)
			new[0] = extra;
		ft_strcpy(new + hash + !!extra + info->field_width - \
				(int)ft_strlen(*str), *str + hash + !!extra);
	}
	else
	{
		ft_memset(new, ' ', info->field_width - ft_strlen(*str));
		if (extra)
			new[info->field_width - ft_strlen(*str)] = extra;
		ft_strcpy(new + info->field_width - ft_strlen(*str) + !!extra, *str \
			+ !!extra);
	}
}

void	width_ctrl(t_info *info, char **str)
{
	char *new;

	if (info->field_width == 0 || ft_strlen(*str) >= \
			(size_t)info->field_width)
		return ;
	new = ft_strnew(info->field_width);
	if (info->flags & MINUS_SIGN)
	{
		ft_strcpy(new, *str);
		ft_memset(new + ft_strlen(*str), ' ', info->field_width \
				- ft_strlen(*str));
	}
	else
		pad_right(info, str, new);
	free(*str);
	*str = new;
	return ;
}
