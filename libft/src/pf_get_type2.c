/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:39:10 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 18:49:09 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				treat_ptr(t_prf *env, char **result)
{
	unsigned long int	to_format;

	to_format = va_arg(env->args, unsigned long int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
	*result = ft_strjoinf("0x", *result, 2);
}

void				treat_uchar(t_prf *env, char **result)
{
	unsigned char	to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_short(t_prf *env, char **result)
{
	short			to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa(to_format);
}

void				treat_ushort(t_prf *env, char **result)
{
	unsigned short	to_format;

	to_format = va_arg(env->args, unsigned int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}
