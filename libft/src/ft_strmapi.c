/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:37:46 by sbrochar          #+#    #+#             */
/*   Updated: 2016/05/13 14:23:18 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*ret;

	i = 0;
	ret = NULL;
	if (s)
		ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret && f)
	{
		while (ret && s && s[i])
		{
			ret[i] = f(i, s[i]);
			i += 1;
		}
		return (ret);
	}
	return (NULL);
}
