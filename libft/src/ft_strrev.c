/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:15:23 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/17 15:31:54 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_strrev(char **s)
{
	char			*cpy;
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(*s);
	cpy = ft_strdup(*s);
	while (len > 0)
	{
		(*s)[i] = cpy[len - 1];
		i++;
		len--;
	}
	ft_strdel(&cpy);
}
