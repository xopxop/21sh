/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:27:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/09 19:29:47 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		measure(char const *s)
{
	int			i;
	int			bal;
	int			nb;

	i = -1;
	bal = 0;
	nb = 0;
	while (s[++i])
	{
		if (ft_is_d_quote(s[i]) && bal % 2 == 0)
			bal++;
		else if (ft_is_d_quote(s[i]) && bal % 2 == 1)
		{
			bal--;
			nb++;
		}
		else if ((!ft_iswhite(s[i]) && s[i + 1] == '\0' && !bal) ||
				(!ft_iswhite(s[i]) && ft_iswhite(s[i + 1]) && !bal))
			nb++;
	}
	return (nb);
}

static int		get_str(char *str, char **ret, int i)
{
	int			bal;
	int			flag;

	bal = 0;
	flag = 1;
	ret[0] = ft_strnew(PATH_MAX);
	ret[0][0] = '\0';
	while (str[i] && flag)
	{
		if (ft_is_d_quote(str[i]) && bal % 2 == 0)
			bal++;
		else if (ft_is_d_quote(str[i]) && bal % 2 == 1)
		{
			bal--;
			flag = 0;
		}
		else if (!ft_iswhite(str[i]) || (ft_iswhite(str[i]) && bal))
			ft_addchar(ret[0], str[i]);
		else if (ft_iswhite(str[i]) && !bal)
			flag = 0;
		i++;
	}
	if (ret[0][0] == '\0')
		ft_strdel(ret);
	return (i);
}

char			**ft_split_d_quote(char const *s)
{
	int			nb;
	int			dot;
	int			i;
	char		**split;
	char		*temp;

	nb = measure(s);
	split = (char**)malloc(sizeof(char*) * (nb + 1));
	i = -1;
	dot = 0;
	while (++i < nb)
	{
		dot = get_str((char*)s, &temp, dot);
		if (temp)
		{
			split[i] = (char*)malloc(sizeof(char) * PATH_MAX);
			ft_strcpy(split[i], temp);
			ft_strdel(&temp);
		}
		else
			--i;
	}
	split[i] = NULL;
	return (split);
}
