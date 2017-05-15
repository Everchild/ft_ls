/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:23 by sbrochar          #+#    #+#             */
/*   Updated: 2016/12/10 16:01:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				swap_nodes(t_dblist **list, t_node **n1, t_node **n2)
{
	t_node			*tmp;

	tmp = *n1;
	if ((*list)->start == *n1)
		(*list)->start = *n2;
	else if ((*list)->end == *n1)
		(*list)->end = *n2;
	else if ((*list)->start == *n2)
		(*list)->start = *n1;
	else if ((*list)->end == *n2)
		(*list)->end = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
