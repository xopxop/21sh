/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:36:35 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 00:01:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	space_flag(t_info *info, char **str)
{
	if (info->flags & SPACE && info->specifier)
		*str = ft_strjoin_and_free_string2(" ", *str);
}

void	plus_flag(t_info *info, char **str)
{
	if (info->flags & PLUS_SIGN)
		*str = ft_strjoin_and_free_string2("+", *str);
}

void	hash_flag(t_info *info, char **str)
{
	if (info->flags & HASH_SIGN)
	{
		if (info->specifier == spec_octal)
			*str = ft_strjoin_and_free_string2("0", *str);
		else if (((info->specifier == spec_hexupcase || info->specifier == \
				spec_hexlowcase) && **str != 0) || info->specifier == spec_ptr)
			*str = ft_strjoin_and_free_string2("0x", *str);
		else if (info->specifier == spec_float && info->percision == 0)
			*str = ft_strjoin_and_free_string1(*str, ".");
	}
}

void	flag_control(t_info *info, char **str, int negative)
{
	hash_flag(info, str);
	if (((info->specifier == spec_int || info->specifier == spec_float) && \
				!negative) || info->specifier == spec_ptr)
	{
		space_flag(info, str);
		plus_flag(info, str);
	}
}

void	flag_ignore(t_info *info, char *str)
{
	if (info->flags & MINUS_SIGN && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->flags & PLUS_SIGN && info->flags & SPACE)
		info->flags ^= SPACE;
	if (info->flags & HASH_SIGN && (info->specifier == spec_int || \
				info->specifier == spec_uint))
		info->flags ^= HASH_SIGN;
	if (info->flags & HASH_SIGN && info->percision > (int)ft_strlen(str) && \
			info->specifier == spec_octal)
		info->flags ^= HASH_SIGN;
	if (info->flags & ZERO && info->percision > -1)
		info->flags ^= ZERO;
	if (info->flags & HASH_SIGN && ((!ft_strcmp("0x", str) || \
					!ft_strcmp("0", str)) && info->percision != 0))
		info->flags ^= HASH_SIGN;
}
