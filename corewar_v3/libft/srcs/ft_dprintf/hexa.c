/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpf_form_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:44:55 by aromny-w          #+#    #+#             */
/*   Updated: 2020/02/12 22:27:41 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	puthexnbr(t_dpf *info, uintmax_t n, char a)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd(n + ('0'), info->fd);
		else
			ft_putchar_fd(n + (a - 10), info->fd);
	}
	else
	{
		puthexnbr(info, n / 16, a);
		puthexnbr(info, n % 16, a);
	}
}

static int	nlen(uintmax_t n)
{
	int	len;

	len = 1;
	while (n / 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	print(t_dpf *info, uintmax_t n, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar_fd(' ', info->width, info->fd);
	if (n && info->flags.hash)
	{
		if (info->spec != 'X')
			ft_putstr_fd("0x", info->fd);
		else
			ft_putstr_fd("0X", info->fd);
	}
	if (info->prec > 0)
		ft_padchar_fd('0', info->prec, info->fd);
	else if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar_fd('0', info->width, info->fd);
	if (len)
	{
		if (info->spec != 'X')
			puthexnbr(info, n, 'a');
		else
			puthexnbr(info, n, 'A');
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + (info->width));
	return (len);
}

static uintmax_t	cast(uintmax_t n, t_dmods mods)
{
	if (mods.q)
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

int	dform_hexa(va_list arg, t_dpf *info)
{
	uintmax_t	n;
	int			len;

	n = cast(va_arg(arg, uintmax_t), info->mods);
	len = 0;
	if (!(!n && !info->prec))
	{
		if (nlen(n) > info->prec)
			len = nlen(n);
		else
			len = info->prec;
		if (n > 0 && info->flags.hash)
			len += 2;
		info->width -= len;
		info->prec -= nlen(n);
	}
	return (print(info, n, len));
}
