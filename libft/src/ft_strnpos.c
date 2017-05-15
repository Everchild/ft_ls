/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:27 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:40:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strnpos(char *s, char c, size_t n)
{
	size_t			i;

	i = 0;
	if (s)
	{
		while (s && s[i] && i < n)
		{
			if ((unsigned char)s[i] == (unsigned char)c)
				return (i);
			i += 1;
		}
	}
	return (-1);
}
