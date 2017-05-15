/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/17 15:43:21 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		findlen(unsigned long long int n, unsigned char base)
{
	int				ret;

	ret = 1;
	while (n >= base)
	{
		n /= base;
		ret += 1;
	}
	return (ret);
}

char				*ft_itoa_base(unsigned long long n, unsigned char base)
{
	static char		*charset = "0123456789abcdefghijklmnopqrstuvwxyz";
	char			*ret;
	size_t			len;
	size_t			i;

	len = findlen(n, base);
	ret = ft_strnew(len);
	i = 0;
	if (ret)
	{
		while (i < len)
		{
			ret[i] = charset[n % base];
			n /= base;
			i++;
		}
		ft_strrev(&ret);
		return (ret);
	}
	return (NULL);
}
