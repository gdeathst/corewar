/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcharacter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:47:09 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 21:03:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	print(t_dpf *info, wchar_t wc, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar_fd('0', info->width, info->fd);
	ft_putwchar_fd(wc, info->fd);
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	dform_wcharacter(va_list arg, t_dpf *info)
{
	wchar_t	wc;
	int		len;

	wc = va_arg(arg, wchar_t);
	if (wc < 128)
		len = 1;
	else if (wc < 2048)
		len = 2;
	else if (wc < 65536)
		len = 3;
	else
		len = 4;
	info->width -= len;
	return (print(info, wc, len));
}
