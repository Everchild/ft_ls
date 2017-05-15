/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formating_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:42:42 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 17:16:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			init_specs(t_specs *specs)
{
	specs->flags = 0;
	specs->field_width = -1;
	specs->precision = -1;
	ft_bzero(specs->conversion, PRF_LEN_MAX_CONV + 1);
	specs->format = 0;
	specs->result = NULL;
	specs->base = 10;
}

static void			handle_specs(t_prf *env)
{
	env->index++;
	init_specs(env->cur_specs);
	get_flag(env, env->cur_specs);
	get_field_width(env, env->cur_specs);
	get_precision(env, env->cur_specs);
	get_conversion(env, env->cur_specs);
	if (convert_specs(env))
	{
		apply_precision(env->cur_specs, &(env->cur_specs->result));
		apply_opt(env);
	}
}

void				formating_string(t_prf *env)
{
	size_t			save;
	size_t			to_copy;
	char			*tmp;

	while (env->format && env->format[env->index])
	{
		to_copy = 0;
		save = env->index;
		while (env->format[env->index] && env->format[env->index] != '%')
		{
			env->index++;
			to_copy++;
		}
		tmp = ft_strsub(env->format, save, to_copy);
		buff_handler(&(env->buff), FILL, tmp);
		ft_strdel(&tmp);
		env->len_result += to_copy;
		if (env->format[env->index] == '%')
			handle_specs(env);
	}
}
