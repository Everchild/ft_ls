/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:48:26 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 18:48:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strcpy(char *dest, const char *src)
{
	size_t			i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = src[i];
	return (dest);
}
