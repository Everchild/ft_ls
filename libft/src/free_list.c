/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:12 by sbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 15:49:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				free_list(t_dblist **list)
{
	t_node			*cur;
	t_node			*next;

	if (list && *list)
	{
		cur = (*list)->start;
		while (cur)
		{
			next = cur->next;
			ft_memdel((void **)&(cur->content));
			ft_memdel((void **)&cur);
			cur = next;
		}
		ft_memdel((void **)list);
	}
}
