/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:44:40 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/16 21:48:31 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H

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


#endif
