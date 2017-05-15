/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:39:08 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:39:09 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memdup(const void *s, size_t n)
{
	void			*ret;

	ret = ft_memalloc(n);
	if (ret)
	{
		ft_memmove(ret, s, n);
		return (ret);
	}
	return (NULL);
}
