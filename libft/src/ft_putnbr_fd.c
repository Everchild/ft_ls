/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/17 14:33:54 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			findlen(long int n)
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

void				ft_putnbr_fd(int n, int fd)
{
	int				len;
	long int		pow;
	long int		n_abs;

	n_abs = ft_abs(n);
	len = findlen(n_abs);
	pow = ft_pow(10, len - 1);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (pow > 0)
	{
		if (n_abs)
			ft_putchar_fd((n_abs / pow) + '0', fd);
		else
			ft_putchar_fd('0', fd);
		n_abs %= pow;
		pow /= 10;
	}
}
