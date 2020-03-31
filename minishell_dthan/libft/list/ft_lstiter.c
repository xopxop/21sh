/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:56:21 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:25:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_lstiter
** PROTOTYPE: void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
** DESCRIPTION: Iterates the list lst and applies the fuction f to each link.
** PARAMS.#1: A pointer to the first link of a list.
** PARAMS.#2: The address of a function to apply to each link of a list.
** RETURN VALUE: None.
** Libc FUNCTIONS: None.
*/

#include "../includes/ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
