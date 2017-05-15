/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 19:49:42 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 20:02:23 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			register_conversion(t_prf *env, t_specs *specs, int to_copy,
		int save)
{
	char			*tmp;

	tmp = ft_strsub(env->format, save, to_copy);
	ft_strcpy(specs->conversion, tmp);
	ft_strdel(&tmp);
	specs->format = specs->conversion[to_copy - 1];
	if (specs->format == 'o' || specs->format == 'O')
		specs->base = 8;
	else if (specs->format == 'x' || specs->format == 'X'
			|| specs->format == 'p')
		specs->base = 16;
}

void				get_conversion(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;

	save = env->index;
	if (!(env->format[env->index])
			|| (!ft_strchr(ALL_MODIFIERS, env->format[env->index])
				&& !ft_strchr(ALL_FORMATS, env->format[env->index])))
		return ;
	to_copy = 1;
	while (env->format && env->format[env->index]
			&& !ft_strchr(ALL_FORMATS, env->format[env->index]))
	{
		env->index++;
		to_copy++;
	}
	if (to_copy <= PRF_LEN_MAX_CONV)
		register_conversion(env, specs, to_copy, save);
	env->index++;
}
