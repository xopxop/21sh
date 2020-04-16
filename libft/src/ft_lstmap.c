/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:47:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:57:25 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*c_fresh;
	t_list	*mapd_lst;
	t_list	*n_fresh;

	if (!lst)
		return (NULL);
	mapd_lst = f(lst);
	fresh = ft_lstnew(mapd_lst->content, mapd_lst->content_size);
	c_fresh = fresh;
	lst = lst->next;
	while (lst)
	{
		mapd_lst = f(lst);
		n_fresh = ft_lstnew(mapd_lst->content, mapd_lst->content_size);
		if (!n_fresh)
			return (NULL);
		c_fresh->next = n_fresh;
		c_fresh = c_fresh->next;
		lst = lst->next;
	}
	return (fresh);
}
