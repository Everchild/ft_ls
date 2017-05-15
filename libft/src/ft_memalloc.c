/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:12 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:41:12 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void				*ft_memalloc(size_t size)
{
	void			*ret;

	ret = NULL;
	if (size > 0)
		ret = malloc(size);
	if (ret)
	{
		ft_bzero(ret, size);
		return (ret);
	}
	return (NULL);
}
