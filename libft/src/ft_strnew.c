/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:30:53 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:30:55 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strnew(size_t size)
{
	char			*ret;

	ret = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (ret)
		return (ret);
	return (NULL);
}
