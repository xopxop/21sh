/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:33:57 by dthan             #+#    #+#             */
/*   Updated: 2019/10/28 18:44:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PROTOTYPE: void ft_lstadd(t_list **alst, t_list *new)
** DESCRIPTION: Adds the element new at the bbeginning of the list
** PARAM.#1: The address of a pointer to the first link of a list
** PARAM.#2: The link to add at the beginning of the list
** RETURN VALUE: None
** Libc function: None
*/

#include "../includes/ft_list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
