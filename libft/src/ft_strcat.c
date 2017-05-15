/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:50 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:40:51 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strcat(char *dest, const char *src)
{
	char			*pdest;

	pdest = dest + ft_strlen(dest);
	pdest = ft_strcpy(pdest, src);
	return (dest);
}
