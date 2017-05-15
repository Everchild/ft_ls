/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:30:27 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:30:29 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_realloc(void *ptr, size_t size)
{
	void			*ret;

	if (!ptr)
	{
		ptr = ft_memalloc(size);
		if (ptr)
			return (ptr);
	}
	else if (!size)
		ft_memdel(&ptr);
	else
	{
		ret = ft_memalloc(size);
		if (ret)
		{
			ft_memmove(ret, ptr, size);
			ft_memdel(&ptr);
			return (ret);
		}
	}
	return (NULL);
}
