/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:37:54 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/05 17:13:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	size_t			size;

	s = NULL;
	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	s = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (s)
	{
		if (s1)
			s = ft_strcpy(s, s1);
		if (s2)
			s = ft_strcat(s, s2);
		return (s);
	}
	return (NULL);
}
