/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:43 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/14 15:02:31 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strndup(const char *s, size_t n)
{
	char			*ret;

	ret = NULL;
	ret = (char *)ft_memalloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s, n);
	return (ret);
}
