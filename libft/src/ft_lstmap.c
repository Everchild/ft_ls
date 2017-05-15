/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:30:47 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/19 18:04:50 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			ft_delcontent(void *mem, size_t size)
{
	ft_bzero(mem, size);
	ft_memdel(&mem);
}

static t_list		*dofunc(t_list *lst, t_list *(*f)(t_list *elem), void *del)
{
	t_list			*newelem;
	t_list			*begin;
	t_list			*next;

	newelem = f(lst);
	if (newelem == NULL)
		return (NULL);
	begin = newelem;
	while (lst->next != NULL)
	{
		lst = lst->next;
		next = f(lst);
		if (next == NULL)
		{
			ft_lstdel(&begin, del);
			return (NULL);
		}
		newelem->next = next;
		newelem = next;
	}
	return (begin);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	void			*del;

	del = &ft_delcontent;
	if (lst && f)
		return (dofunc(lst, f, del));
	return (NULL);
}
