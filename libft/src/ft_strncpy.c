/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:04 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:45:06 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t			i;

	i = 0;
	ft_bzero(dest, n);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}
