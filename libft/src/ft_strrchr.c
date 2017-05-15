/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:49:44 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/14 12:38:11 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strrchr(const char *s, int c)
{
	size_t			len;

	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	while (len > 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len -= 1;
	}
	if (s[len] == c)
		return ((char *)s + len);
	return (NULL);
}
