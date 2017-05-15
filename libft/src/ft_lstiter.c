/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:49:27 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 18:49:28 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list			*ptr;

	if (lst && f)
	{
		ptr = lst;
		while (ptr)
		{
			f(ptr);
			ptr = ptr->next;
		}
	}
}
