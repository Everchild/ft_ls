/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:56:10 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/04 17:56:19 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**ft_tabdup(const char **tab)
{
	char			**ret;
	size_t			nb_elem;
	size_t			i;

	ret = NULL;
	nb_elem = 0;
	i = 0;
	if (tab)
	{
		while (tab[nb_elem])
			nb_elem++;
		ret = (char **)ft_memalloc(sizeof(char *) * (nb_elem + 1));
		while (i < nb_elem)
		{
			ret[i] = ft_strdup(tab[i]);
			i++;
		}
		ret[i] = NULL;
	}
	return (ret);
}
