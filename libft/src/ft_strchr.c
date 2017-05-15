/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:49:44 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/14 12:35:02 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i += 1;
	}
	return (NULL);
}
