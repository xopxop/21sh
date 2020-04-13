/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:38:01 by dthan             #+#    #+#             */
/*   Updated: 2019/10/29 23:32:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_lstmap
** PROTOTYPE: t_list *ft_lstmap(t_list *lst, t_list *elem);
** DESCRIPTION: Iterates a list lst and applies the fucntion f to each link to
** create a "fresh" list (using malloc(3) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
** PARAMS.#1: A pointer's to the first link of a list.
** PARAMS.#2: The address of a fucntion to apply to each link of a list.
** RETURN VALUE: The new list.
** Libc FUNCTIONS: malloc(3), free(3).
*/

#include "../includes/ft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	newlst->next = ft_lstmap(lst->next, f);
	return (newlst);
}
