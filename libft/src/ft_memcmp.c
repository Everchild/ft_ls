/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:29 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/08 00:55:47 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char const	*ps1;
	unsigned char const	*ps2;

	i = 0;
	ps1 = (unsigned char const *)s1;
	ps2 = (unsigned char const *)s2;
	while (i < n)
	{
		if ((unsigned char)ps1[i] != (unsigned char)ps2[i])
			return ((unsigned char)ps1[i] - (unsigned char)ps2[i]);
		i += 1;
	}
	return (0);
}
