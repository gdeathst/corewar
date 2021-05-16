/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:42:43 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 22:25:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putoctnbr(uintmax_t n)
{
	if (n < 8)
		ft_putchar(n + '0');
	else
	{
		putoctnbr(n / 8);
		putoctnbr(n % 8);
	}
}

static int	nlen(uintmax_t n, int hash)
{
	int	len;

	if (!(n > 0 && hash))
		len = 1;
	else
		len = 2;
	while (n / 8)
	{
		n /= 8;
		len++;
	}
	return (len);
}

static int	print(t_pf *info, uintmax_t n, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar(' ', info->width);
	if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar('0', info->width);
	if ((info->prec > 0 || (n > 0 && info->flags.hash)) && info->prec > 0)
		ft_padchar('0', info->prec);
	if ((info->prec > 0 || (n > 0 && info->flags.hash)) && !(info->prec > 0))
		ft_padchar('0', 1);
	if (len && !(!n && !(len - info->prec)))
		putoctnbr(n);
	if (info->width > 0 && info->flags.minus)
		ft_padchar(' ', info->width);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

static uintmax_t	cast(uintmax_t n, t_mods mods, char spec)
{
	if (spec == 'O')
		return ((unsigned long)n);
	else if (mods.q)
		return ((u_quad_t)n);
	else if (mods.z)
		return ((size_t)n);
	else if (mods.t)
		return ((ptrdiff_t)n);
	else if (mods.j)
		return ((uintmax_t)n);
	else if (mods.ll)
		return ((unsigned long long)n);
	else if (mods.l)
		return ((unsigned long)n);
	else if (mods.h)
		return ((unsigned short)n);
	else if (mods.hh)
		return ((unsigned char)n);
	return ((unsigned int)n);
}

int	form_octal(va_list arg, t_pf *info)
{
	uintmax_t	n;
	int			len;

	n = cast(va_arg(arg, uintmax_t), info->mods, info->spec);
	len = 0;
	if (!(!n && !info->prec))
	{
		if (nlen(n, info->flags.hash) > info->prec)
			len = nlen(n, info->flags.hash);
		else
			len = info->prec;
		info->width -= len;
		info->prec -= nlen(n, 0);
	}
	else
	{
		info->prec += info->flags.hash;
		len += info->prec;
		info->width -= info->flags.hash + info->flags.space;
	}
	return (print(info, n, len));
}
