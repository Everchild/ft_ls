/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 20:13:12 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		findlen(long long n)
{
	int				ret;

	ret = 1;
	while (n > 9)
	{
		n /= 10;
		ret += 1;
	}
	return (ret);
}

static void			do_itoa(long long n, char **ret, size_t len,
		unsigned long long n_abs)
{
	size_t				i;

	i = 0;
	if (n < 0)
	{
		(*ret)[len - 1] = '-';
		len--;
	}
	while (i < len)
	{
		(*ret)[i] = (n_abs % 10) + '0';
		n_abs /= 10;
		i++;
	}
	ft_strrev(ret);
}

char				*ft_itoa(long long n)
{
	char				*ret;
	size_t				len;
	unsigned long long	n_abs;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	n_abs = ft_abs(n);
	len = findlen(n_abs);
	len += n < 0 ? 1 : 0;
	ret = ft_strnew(len);
	if (ret)
	{
		do_itoa(n, &ret, len, n_abs);
		return (ret);
	}
	return (NULL);
}
