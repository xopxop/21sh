/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:06:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:00:15 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*trimming(char const *s, char c, int count_flag)
{
	char		*copy;
	char		*pt_copy;

	copy = (char*)malloc(ft_strlen(s) + 2);
	*copy = 0;
	pt_copy = copy;
	while (*s)
	{
		if (*s != c && count_flag)
		{
			count_flag = 0;
			*copy += 1;
		}
		else if (*s != c)
			*++pt_copy = *s++;
		else if (*s == c && count_flag)
			s++;
		else if (*s++ == c && !count_flag)
		{
			count_flag = 1;
			*++pt_copy = '\0';
		}
	}
	*++pt_copy = '\0';
	return (copy);
}

static void		malloc_sub(char **d_pt, char *s_pt, int amt_strings)
{
	size_t		len;
	int			i;

	i = 0;
	while (i < amt_strings)
	{
		len = ft_strlen(s_pt);
		d_pt[i++] = (char*)malloc(len + 1);
		s_pt = s_pt + len + 1;
	}
}

static void		distribute_strings(char **d_pt, char *s_pt, int amt_strings)
{
	int			i;
	size_t		len;

	i = 0;
	while (i < amt_strings)
	{
		len = ft_strlen(s_pt);
		ft_strcpy(d_pt[i++], s_pt);
		s_pt = s_pt + len + 1;
	}
	d_pt[i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**d_pt;
	char		*s_pt;
	int			count_flag;
	int			i;

	count_flag = 1;
	s_pt = trimming(s, c, count_flag);
	d_pt = (char**)malloc(sizeof(char*) * (s_pt[0] + 1));
	if (!d_pt)
		return (NULL);
	malloc_sub(d_pt, s_pt + 1, (int)s_pt[0]);
	i = -1;
	while (++i < (int)s_pt[0])
		if (!d_pt[i])
			return (NULL);
	distribute_strings(d_pt, s_pt + 1, (int)s_pt[0]);
	free(s_pt);
	return (d_pt);
}
