/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:54:41 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 21:59:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexnbr(uintmax_t n, char a)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n + a - 10);
	}
	else
	{
		puthexnbr(n / 16, a);
		puthexnbr(n % 16, a);
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

static int	print(t_pf *info, uintmax_t n, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar(' ', info->width);
	if (info->spec != 'X')
		ft_putstr("0x");
	else
		ft_putstr("0X");
	if (info->prec > 0)
		ft_padchar('0', info->prec);
	else if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar('0', info->width);
	if (!(!n && !info->prec))
	{
		if (info->spec != 'X')
			puthexnbr(n, 'a');
		else
			puthexnbr(n, 'A');
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar(' ', info->width);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	form_pointer(va_list arg, t_pf *info)
{
	uintmax_t	n;
	int			len;

	n = (uintmax_t)va_arg(arg, void *);
	if (!(!n && !info->prec))
	{
		if (nlen(n) > info->prec)
			len = nlen(n);
		else
			len = info->prec;
		info->prec -= nlen(n);
	}
	else
		len = 0;
	len += 2;
	info->width -= len;
	return (print(info, n, len));
}
