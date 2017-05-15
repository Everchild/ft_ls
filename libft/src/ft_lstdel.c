/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:39:15 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:39:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*ptr;
	t_list			*next;

	if (alst && *alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			next = ptr->next;
			ft_lstdelone(&ptr, del);
			ptr = next;
		}
		*alst = NULL;
	}
}
