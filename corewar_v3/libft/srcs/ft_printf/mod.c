/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:30:40 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 21:18:01 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_modifier(int c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z' || c == 'q')
		return (1);
	if (c == 'L')
		return (1);
	return (0);
}

void	set_mod(const char **format, t_mods *mods)
{
	while (is_modifier(**format))
	{
		if (**format == 'h' && *(*format + 1) == 'h')
			mods->hh = 1;
		else if (**format == 'h')
			mods->h = 1;
		else if (**format == 'l' && *(*format + 1) != 'l')
			mods->l = 1;
		else if ((**format == 'l' && *(*format + 1) == 'l') || **format == 'L')
			mods->ll = 1;
		else if (**format == 'j')
			mods->j = 1;
		else if (**format == 't')
			mods->t = 1;
		else if (**format == 'z')
			mods->z = 1;
		else if (**format == 'q')
			mods->q = 1;
		if (**format != *(*format + 1))
			*format += 1;
		else
			*format += 2;
	}
}
