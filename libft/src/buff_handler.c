/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:33:10 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/11 16:36:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			flush_buff(char **buff)
{
	if (buff)
	{
		ft_putstr(*buff);
		ft_bzero(*buff, BUFF_SIZE + 1);
	}
}

static void			fill_buff(char **buff, char *s)
{
	size_t				place;

	if (s)
	{
		place = BUFF_SIZE - ft_strlen(*buff);
		ft_strncat(*buff, s, place);
		if (ft_strlen(s) > place)
		{
			s += place;
			while (ft_strlen(s))
			{
				flush_buff(buff);
				ft_strncpy(*buff, s, BUFF_SIZE);
				if (ft_strlen(s) > BUFF_SIZE)
					s += BUFF_SIZE;
				else
					break ;
			}
		}
	}
	else
		fill_buff(buff, "(null)");
}

void				buff_handler(char **buff, int action, char *s)
{
	if (*buff)
	{
		if (action == FILL)
			fill_buff(buff, s);
		else if (action == FLUSH)
			flush_buff(buff);
	}
}
