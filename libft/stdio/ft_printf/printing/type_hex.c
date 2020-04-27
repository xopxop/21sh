/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:31:21 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:42:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4

void	small_x(t_info *info, va_list arg, char **output)
{
	unsigned long long	num;
	char				*str;
	char				*hex;

	hex = "0123456789abcdef";
	num = get_unsigned_argument(info, arg);
	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, hex);
	flag_ignore(info, str);
	prec_ctrl_oct_hex(info, &str);
	flag_control(info, &str, 0);
	width_ctrl(info, &str);
	*output = str;
}

void	big_x(char **output)
{
	char *new;

	new = *output;
	while (*new)
	{
		*new = ft_toupper(*new);
		new++;
	}
}

void	type_x(t_info *info, va_list arg, size_t *ct)
{
	char *output;

	small_x(info, arg, &output);
	if (info->specifier == spec_hexupcase)
		big_x(&output);
	write(STDOUT, output, *ct = ft_strlen(output));
	free(output);
}
