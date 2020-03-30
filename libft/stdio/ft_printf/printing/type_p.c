/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:07:20 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:43:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4

void	type_p(t_info *info, va_list arg, size_t *ct)
{
	unsigned long long	num;
	char				*str;
	char				*hex;

	hex = "0123456789abcdef";
	num = (long long)va_arg(arg, long long);
	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, hex);
	flag_ignore(info, str);
	if (!(info->flags & HASH_SIGN))
		info->flags ^= HASH_SIGN;
	prec_ctrl_oct_hex(info, &str);
	flag_control(info, &str, 0);
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
