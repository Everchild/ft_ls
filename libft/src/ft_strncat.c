/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:49:17 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 20:21:54 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t			i;
	char			*pdest;

	i = 0;
	pdest = dest + ft_strlen(dest);
	while (src[i] && i < n)
	{
		pdest[i] = src[i];
		i += 1;
	}
	pdest[i] = '\0';
	return (dest);
}
