/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:50:11 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/19 19:05:29 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			size_s2;

	size_s2 = ft_strlen(s2);
	if (!size_s2)
		return ((char *)s1);
	while ((*s1) && (n-- >= size_s2))
	{
		if ((*s1 == *s2) && (ft_memcmp(s1, s2, size_s2) == 0))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
