/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:51:02 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 18:51:34 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				treat_int(t_prf *env, char **result)
{
	int				to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa(to_format);
}

void				treat_uint(t_prf *env, char **result)
{
	unsigned int	to_format;

	to_format = va_arg(env->args, unsigned int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_long(t_prf *env, char **result)
{
	long			to_format;

	to_format = va_arg(env->args, long);
	*result = ft_itoa(to_format);
}

void				treat_ulong(t_prf *env, char **result)
{
	unsigned long	to_format;

	to_format = va_arg(env->args, unsigned long);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}
