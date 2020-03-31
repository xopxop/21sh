/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:43:31 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 08:26:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int ct;
	unsigned int i;

	ct = 0;
	while (dest[ct])
		ct++;
	i = 0;
	while (src[i])
	{
		dest[ct] = src[i];
		i++;
		ct++;
	}
	dest[ct] = '\0';
	return (dest);
}
