/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:48:54 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:48:56 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_prntf *bs, int fhesh, int fchar)
{
	int c;
	int f;

	f = 1;
	c = (int)ft_strlen(bs->str);
	if (c <= bs->nw)
	{
		c = bs->nw - c - fhesh + fchar;
		while (c-- > 0)
		{
			if (bs->spc && f && (bs->tp == 'd' || bs->tp == 'D' ||
				bs->tp == 'i'))
				f = 0;
			else
			{
				if (bs->z)
					print_aka_flags(1, '0', bs);
				else
					print_aka_flags(1, ' ', bs);
			}
		}
	}
}
