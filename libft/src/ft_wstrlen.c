/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:38:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/11 18:01:21 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_wstrlen(const wchar_t *s)
{
	size_t			len;

	len = 0;
	while (*s)
	{
		if (*s <= 0x7f)
			len++;
		else if (*s <= 0x7ff)
			len += 2;
		else if (*s <= 0x7ffff)
			len += 3;
		else
			len += 4;
		s++;
	}
	return (len);
}
