/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:46:49 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 18:46:55 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;

	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (ret && s)
	{
		ret = ft_strncpy(ret, &s[start], len);
		return (ret);
	}
	return (NULL);
}
