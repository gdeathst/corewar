/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_uoxbn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:48:46 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:48:48 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(t_prntf *bs)
{
	cast_uox(bs);
	if (bs->prc != -1)
		print_prc(bs);
	(bs->nw != 0 && !bs->m && bs->prc == -1) ? print_width(bs, 0, 0) : 0;
	if (bs->prc == -1)
		print_aka_flags(1, 'p', bs);
	(bs->m && bs->prc == -1) ? print_width(bs, 0, 0) : 0;
}

void	print_o(t_prntf *bs)
{
	cast_uox(bs);
	if (bs->prc != -1)
		print_prc(bs);
	if (bs->nw != 0 && !bs->m && bs->prc == -1)
		(bs->hash) ? print_width(bs, 1, 0) : print_width(bs, 0, 0);
	if (bs->hash && bs->prc == -1 && ft_strcmp(bs->str, "0"))
		print_aka_flags(1, '0', bs);
	if (bs->prc == -1)
		print_aka_flags(1, 'p', bs);
	if (bs->m && bs->prc == -1)
		(bs->hash) ? print_width(bs, 1, 0) : print_width(bs, 0, 0);
}

void	print_x(t_prntf *bs)
{
	cast_uox(bs);
	if (bs->prc != -1)
		print_prc(bs);
	if (bs->hash && !bs->m && bs->prc == -1 && bs->z)
		print_aka_flags(1, bs->tp, bs);
	if (!bs->m && bs->prc == -1)
		(bs->hash && ft_strcmp(bs->str, "0")) ? print_width(bs, 2, 0) :
		print_width(bs, 0, 0);
	if (bs->hash && bs->prc == -1 && !bs->z && ft_strcmp(bs->str, "0"))
		print_aka_flags(1, bs->tp, bs);
	if (bs->prc == -1)
		print_aka_flags(1, 'p', bs);
	if (bs->m && bs->prc == -1)
		(bs->hash && ft_strcmp(bs->str, "0")) ? print_width(bs, 2, 0) :
		print_width(bs, 0, 0);
}

void	print_b(t_prntf *bs)
{
	cast_uox(bs);
	if (bs->prc != -1)
		print_prc(bs);
	(bs->nw != 0 && !bs->m && bs->prc == -1) ? print_width(
			bs, 0, 0) : 0;
	if (bs->prc == -1)
		print_aka_flags(1, 'p', bs);
	(bs->m && bs->prc == -1) ? print_width(bs, 0, 0) : 0;
}

void	do_n(t_prntf *bs)
{
	if (bs->mdf == 'H')
		*((int *)(bs->nbr)) = (unsigned char)bs->r;
	else if (bs->mdf == 'h')
		*((int *)(bs->nbr)) = (unsigned short)bs->r;
	else
		*((int *)(bs->nbr)) = bs->r;
}
