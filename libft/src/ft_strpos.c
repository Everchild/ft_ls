/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:39:38 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:39:40 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strpos(char *s, char c)
{
	size_t			i;

	i = 0;
	if (s)
	{
		while (s && s[i])
		{
			if ((unsigned char)s[i] == (unsigned char)c)
				return (i);
			i += 1;
		}
	}
	return (-1);
}
