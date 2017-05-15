/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:48:52 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 18:48:54 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (*alst)
		{
			new->next = *alst;
			*alst = new;
		}
		else
			*alst = new;
	}
}
