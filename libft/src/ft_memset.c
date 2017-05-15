/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:29 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:55:35 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	ret = s;
	i = 0;
	while (i < n)
	{
		ret[i] = c;
		i += 1;
	}
	return (ret);
}
