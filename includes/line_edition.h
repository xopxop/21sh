/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:44:40 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/19 22:20:01 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H

# ifdef __APPLE__
#  if __MAC_OS_X_VERSION_MIN_REQUIRED <= 101200
#   define OS "sierra"
#   define LEFT "#4"
#  else
#   define LEFT "kl"
#   define OS "not_sierra"
#  endif
# else
#  define LEFT "kl"
#  define OS "not_apple"
# endif

# define CLIP_SAVE 0
# define CLIP_TAKE 1
# define CLIP_DELT 2
# define PMPT 2

typedef struct			s_l
{
	char				*line;
	int					co;
	int					nb;
	int					x;
	int					y;
	int					curr;
}						t_l;

typedef struct			s_h
{
	char				*data;
	struct s_h			*next;
	short				nb;
	int					len;
}						t_h;

typedef struct termios t_term;


void				ft_get_line(t_l *l, t_h **h);
void				delete_save_history(t_h **h);

#endif
