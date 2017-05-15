/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:44 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 20:13:56 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (!ft_strlen(s1) && !ft_strlen(s2))
		return (0);
	while (s1 && s2 && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i += 1;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
