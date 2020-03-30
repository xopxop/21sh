/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:38:41 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 02:06:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#define IS_FLAG(x) ((x)=='-'||(x)=='+'||(x)==' '||(x)=='#'||(x)=='0')

/*
** the ft parsing flags will pare the flags at the position of the string format
** using bitwise operand to store flags
** NOTE: Also, using loop ft to keep parsing flags
*/

void	get_flags(const char *format, size_t *pos, t_info *info)
{
	while (IS_FLAG(format[*pos]))
	{
		if (format[*pos] == '-')
			info->flags |= MINUS_SIGN;
		else if (format[*pos] == '+')
			info->flags |= PLUS_SIGN;
		else if (format[*pos] == ' ')
			info->flags |= SPACE;
		else if (format[*pos] == '#')
			info->flags |= HASH_SIGN;
		else if (format[*pos] == '0')
			info->flags |= ZERO;
		(*pos)++;
	}
}

/*
** same like ft get_percision, it will take the number or the argument then put
** it into the int field_width of the struct into
** However, there is a note here, if the argument is < 0 (ex: -10...)
** we regconize there is a minus flag here and using OR bitwise operand to store
** the minus sign flag
*/

void	get_field_width(const char *format, size_t *pos, va_list arg, \
		t_info *info)
{
	while (ft_isdigit(format[*pos]) || format[*pos] == '*')
	{
		if (ft_isdigit(format[*pos]))
			info->field_width = ft_skip_atoi(format, pos);
		else if (format[*pos] == '*')
		{
			(*pos)++;
			info->field_width = va_arg(arg, int);
			info->dup_first_args = info->field_width;
			if (info->field_width < 0)
			{
				info->field_width *= -1;
				info->flags |= MINUS_SIGN;
			}
		}
	}
}

/*
** get_percision ft will parese the percision then put the result into the int
** percision in the info struct
** If at the position of the format string is digit, using ft_skip_atoi to take
** the digit in the format string and covert it into interger
** If there is an argument/va_list with the format[*position] == '*'
** the int percision will take the argument instead
*/

void	get_precision(const char *format, size_t *pos, va_list arg, \
		t_info *info)
{
	if (format[*pos] == '.')
	{
		(*pos)++;
		if (ft_isdigit(format[*pos]))
			info->percision = ft_skip_atoi(format, pos);
		else if (format[*pos] == '*')
		{
			(*pos)++;
			info->percision = va_arg(arg, int);
			if (info->dup_first_args != 0)
				info->dup_first_args = info->percision;
		}
		else
			info->percision = 0;
	}
}

/*
** get_length function will parse the length/ conversion qualifier then put
** the result into t_length of the struc info
** 'h' --> len_h
** "hh" --> len_hh
** 'l' --> len_l
** 'll' -->len_ll
** 'L' -->len_lup
** nothing -->len_none
*/

void	get_length(const char *format, size_t *pos, t_info *info)
{
	if ((format[*pos] == 'l' && format[*pos + 1] == 'l') || \
			(format[*pos] == 'h' && format[*pos + 1] == 'h'))
	{
		info->length = (format[*pos + 1] == 'l') ? len_ll : len_hh;
		*pos += 2;
	}
	else if (format[*pos] == 'h' || format[*pos] == 'l' || \
			format[*pos] == 'L')
	{
		if (format[*pos] == 'h')
			info->length = len_h;
		else if (format[*pos] == 'l')
			info->length = len_l;
		else if (format[*pos] == 'L')
			info->length = len_lup;
		(*pos)++;
	}
}

/*
** Ft get_specifier will take the format string at the position to parse then
** put the result into t_specifier in the struc info
** If:
** 'c' --> character
** 's' --> string
** 'p' --> Address
** 'd' || 'i' --> signed decimal interger
** 'u' --> unsigned decimal interger
** 'x' || 'X' --> unsigned hexadecimal interger lower/ upper case
** 'o' --> unsigned octal
** 'f' --> decimal floating point (lower case)
** '%' --> percentage sign
*/

void	get_specifier(const char *format, size_t *pos, t_info *info)
{
	if (ft_isspecifier(format[*pos]))
	{
		if (format[*pos] == 'c')
			info->specifier = spec_char;
		else if (format[*pos] == 's')
			info->specifier = spec_str;
		else if (format[*pos] == 'p')
			info->specifier = spec_ptr;
		else if (format[*pos] == 'd' || format[*pos] == 'i')
			info->specifier = spec_int;
		else if (format[*pos] == 'u')
			info->specifier = spec_uint;
		else if (format[*pos] == 'o')
			info->specifier = spec_octal;
		else if (format[*pos] == 'x')
			info->specifier = spec_hexlowcase;
		else if (format[*pos] == 'X')
			info->specifier = spec_hexupcase;
		else if (format[*pos] == 'f')
			info->specifier = spec_float;
		else if (format[*pos] == '%')
			info->specifier = spec_percentsign;
		(*pos)++;
	}
}
