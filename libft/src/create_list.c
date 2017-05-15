/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:48:02 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 18:48:09 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dblist			*create_list(void)
{
	t_dblist		*list;

	list = (t_dblist*)ft_memalloc(sizeof(t_dblist));
	if (list)
	{
		list->start = NULL;
		list->end = NULL;
		list->nb_nodes = 0;
		return (list);
	}
	return (NULL);
}
