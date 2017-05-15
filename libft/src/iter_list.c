/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:56 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:45:57 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*iter_list(t_dblist **list, int (*f)(t_node *))
{
	t_node			*cur;

	if (list && *list && f)
	{
		cur = (*list)->start;
		while (cur && f(cur))
			cur = cur->next;
		return (cur);
	}
	return (NULL);
}
