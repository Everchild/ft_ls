/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:39:23 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:58:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void						*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char const		*ps;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return ((void *)ps + i);
		i += 1;
	}
	return (NULL);
}
