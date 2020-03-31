/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:20:02 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/09 20:05:10 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	measure(char *str, char c)
{
	int		i;
	int		bal;
	int		nb;

	i = -1;
	bal = 0;
	nb = 1;
	while (str[++i])
	{
		if (ft_is_d_quote(str[i]) && bal % 2 == 0)
			bal++;
		else if (ft_is_d_quote(str[i]) && bal % 2 == 1)
			bal--;
		else if (str[i] == c && !bal)
			nb++;
	}
	return (nb);
}

static int	get_str(char *str, char c, char **ret, int i)
{
	int		bal;
	int		flag;

	bal = 0;
	flag = 1;
	ret[0] = ft_strnew(PATH_MAX);
	ret[0][0] = '\0';
	while (str[++i] && flag)
		if (ft_is_d_quote(str[i]) && bal % 2 == 0)
		{
			ft_addchar(ret[0], str[i]);
			bal++;
		}
		else if (ft_is_d_quote(str[i]) && bal % 2 == 1)
		{
			ft_addchar(ret[0], str[i]);
			bal--;
		}
		else if (str[i] == c && !bal)
			flag = 0;
		else
			ft_addchar(ret[0], str[i]);
	if (ret[0][0] == '\0')
		ft_strdel(ret);
	return (i - 1);
}

char		**ft_split_shell(char *str, char c)
{
	int		nb;
	char	**split;
	char	*temp;
	int		dot;
	int		i;

	nb = measure(str, c);
	split = (char**)malloc(sizeof(char*) * (nb + 1));
	i = -1;
	dot = -1;
	while (++i < nb)
	{
		dot = get_str(str, c, &temp, dot);
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
