/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:45:44 by dthan             #+#    #+#             */
/*   Updated: 2020/02/18 02:00:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

/*
** Flags uses a binary addressing system
** ZERO : pad with zero
** PLUS_SIGN : show plus
** SPACE : space if plus
** MINUS_SIGN : left justified
** HASH_SIGN : show 0x, etc.
*/

# define STDOUT 1
# define ZERO 1
# define PLUS_SIGN 2
# define SPACE 4
# define MINUS_SIGN 8
# define HASH_SIGN 16

typedef enum e_specifier	t_specifier;

enum	e_specifier
{
	spec_char,
	spec_str,
	spec_ptr,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hexlowcase,
	spec_hexupcase,
	spec_float,
	spec_percentsign,
	spec_none,
};

typedef enum e_length	t_length;

enum	e_length
{
	len_hh,
	len_h,
	len_ll,
	len_l,
	len_lup,
	len_none,
};

typedef struct		s_info
{
	int				flags;
	int				field_width;
	int				percision;
	t_length		length;
	t_specifier		specifier;
	int				dup_first_args;
}					t_info;

/*
** Core file
*/

int					ft_printf(char const *format, ...);
int					full_str_printing(const char *format, va_list args, \
		t_info *info);
int					parse_and_print(const char *format, va_list args, \
		size_t *pos, t_info *info);

/*
** -------------------------Parsing part file---------------------------------
*/
void				parsing(const char *format, va_list args, size_t *pos, \
		t_info *info);
void				struct_init(t_info *info);

/*
** Parsing helper file
*/

int					ft_skip_atoi(const char *format, size_t *pos);
int					ft_isspecifier(char specifier);

/*
** Filling struct file
*/

void				get_flags(const char *format, size_t *pos, t_info *info);
void				get_field_width(const char *format, size_t *pos, \
		va_list arg, t_info *info);
void				get_precision(const char *format, size_t *pos, \
		va_list arg, t_info *info);
void				get_length(const char *format, size_t *pos, t_info *info);
void				get_specifier(const char *format, size_t *pos, \
		t_info *info);

/*
** -------------------------Printing files------------------------------------
*/

int					printing(t_info *info, va_list arg);

/*
** Flag_control.c
*/

void				space_flag(t_info *info, char **str);
void				plus_flag(t_info *info, char **str);
void				hash_flag(t_info *info, char **str);
void				flag_control(t_info *info, char **str, int negative);
void				flag_ignore(t_info *info, char *str);

/*
** Width_control.c
*/

void				width_ctrl(t_info *info, char **str);
void				pad_right(t_info *info, char **str, char *new);

/*
** Percision_control.c
*/

void				prec_ctrl_str(t_info *info, char **str);
void				prec_ctrl_nums(t_info *info, char **str, int negative);
void				prec_ctrl_oct_hex(t_info *info, char **str);

/*
** nbr_to_str.c
*/

char				*ft_number_conversion(unsigned long long num, int mask, \
		int shiff_nbr, char *s);
long long			get_signed_argument(t_info *info, va_list arg);
unsigned long long	get_unsigned_argument(t_info *info, va_list arg);

/*
** Printing helper.c
*/

int					ft_isnan(double num);
int					ft_isinf(double num);
int					special_case(char **s, double num);

/*
** Type character
*/

void				type_c(t_info *info, va_list arg, size_t *ct);

/*
** Type string
*/

void				type_s(t_info *info, va_list arg, size_t *ct);

/*
** Type pointer
*/

void				type_p(t_info *info, va_list arg, size_t *ct);

/*
** Type signed Integer
*/

void				type_di(t_info *info, va_list arg, size_t *ct);

/*
** Type unsigned integer
*/

void				type_u(t_info *info, va_list arg, size_t *ct);

/*
** Type Octal number
*/

void				type_o(t_info *info, va_list arg, size_t *ct);

/*
** Type Hexadecimal number
*/

void				small_x(t_info *info, va_list arg, char **output);
void				big_x(char **output);
void				type_x(t_info *info, va_list arg, size_t *ct);

/*
** Type floating point
*/

float				ft_pow(float x, int y);
char				*ft_decimal(long double *nbr);
char				*ft_fractional(long double nbr, t_info *info);
void				float_to_string(long double num, t_info *info, char **str);
void				type_f(t_info *info, va_list arg, size_t *ct);

/*
** Type percentage
*/

void				type_percent(t_info *info, __attribute__((unused)) \
		va_list arg, size_t *ct);

#endif
