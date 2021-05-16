/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:28:10 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 21:01:49 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	dset_width(const char **format, va_list arg, t_dpf *info)
{
	while (ft_isdigit(**format) || **format == '*')
	{
		info->width = 0;
		if (**format != '*')
			while (ft_isdigit(**format))
				info->width = 10 * info->width + (*(*format)++ - '0');
		else
		{
			info->width = va_arg(arg, int);
			if (info->width < 0)
			{
				info->width *= -1;
				info->flags.minus = 1;
			}
			(*format)++;
		}
	}
}
