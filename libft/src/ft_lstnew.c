/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:37:24 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:37:26 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			init_to_null(t_list **lst)
{
	(*lst)->content = NULL;
	(*lst)->content_size = 0;
}

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*ret;
	void			*cpy_content;

	ret = (t_list *)ft_memalloc(sizeof(t_list));
	if (ret)
	{
		if (!content || !content_size)
			init_to_null(&ret);
		else
		{
			cpy_content = ft_memalloc(content_size);
			if (cpy_content)
			{
				ret->content = ft_memmove(cpy_content, content, content_size);
				ret->content_size = content_size;
			}
			else
				return (NULL);
		}
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}
