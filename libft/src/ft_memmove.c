/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:42 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:36:45 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	unsigned const char	*psrc;

	i = 0;
	pdest = dest;
	psrc = src;
	if (dest >= src && dest < (src + n))
	{
		while (n > 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n -= 1;
		}
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i += 1;
		}
	}
	return (dest);
}
