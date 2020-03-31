/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:25:23 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 00:05:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

float	ft_pow(float x, int y)
{
	float temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}

char	*ft_decimal(long double *nbr)
{
	char *str;

	str = ft_itoa_unsigned_longlong((long long)*nbr);
	*nbr = *nbr - (long)*nbr;
	return (str);
}

char	*ft_fractional(long double nbr, t_info *info)
{
	char	*str;
	int		i;

	str = NULL;
	nbr *= 10;
	i = 1;
	if (info->percision > 0)
	{
		str = ft_strnew(info->percision + 1);
		str[0] = '.';
		while (info->percision-- > 0)
		{
			str[i++] = (int)nbr + '0';
			nbr = (nbr - (int)nbr) * 10;
		}
	}
	return (str);
}

void	float_to_string(long double num, t_info *info, char **str)
{
	char	*str_decimal;
	char	*str_fractional;
	int		negative;

	if (special_case(str, num))
		return ;
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		num *= -1;
	}
	if (!negative || info->percision < 6)
		num += (0.5 * ft_pow(0.1, info->percision));
	else
		num += (0.1 * ft_pow(0.1, info->percision));
	str_decimal = ft_decimal(&num);
	str_fractional = ft_fractional(num, info);
	*str = ft_strjoin(str_decimal, str_fractional);
	if (negative)
		*str = ft_strjoin_and_free_string2("-", *str);
	free(str_decimal);
	free(str_fractional);
}

void	type_f(t_info *info, va_list arg, size_t *ct)
{
	long double	num;
	char		*str;
	int			negative;

	negative = 0;
	if (info->length == len_l)
		num = (long double)va_arg(arg, double);
	else if (info->length == len_lup)
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	if (num < 0)
		negative = 1;
	info->percision = (info->percision == -1) ? 6 : info->percision;
	float_to_string(num, info, &str);
	flag_ignore(info, str);
	flag_control(info, &str, negative);
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
