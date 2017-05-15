/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:57:14 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/19 18:21:24 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char)(s1[i])) != ((unsigned char)(s2[i])))
			return (((unsigned char)(s1[i])) - ((unsigned char)(s2[i])));
		else if (!((unsigned char)(s1[i])) && !((unsigned char)(s2[i])))
			return (0);
		i++;
	}
	return (0);
}
