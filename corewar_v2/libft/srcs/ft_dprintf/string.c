/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpf_form_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:53:16 by aromny-w          #+#    #+#             */
/*   Updated: 2020/02/12 22:28:20 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	print_2(t_dpf *info, int len)
{
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

static int	print(t_dpf *info, char *str, int len)
{
	if (info->width > 0 && !info->flags.minus)
	{
		if (!info->flags.zero)
			ft_padchar_fd(' ', info->width, info->fd);
		else
			ft_padchar_fd('0', info->width, info->fd);
	}
	if ((info->spec != 'S' && !info->mods.l))
	{
		if (str)
			ft_putnstr_fd(str, info->prec, info->fd);
		else
			ft_putnstr_fd("(null)", info->prec, info->fd);
	}
	else
	{
		if (str)
			ft_putnwcstr_fd((wchar_t *)str, info->prec, info->fd);
		else
			ft_putnwcstr_fd(L"(null)", info->prec, info->fd);
	}
	return (print_2(info, len));
}

int	dform_string(va_list arg, t_dpf *info)
{
	char	*str;
	int		len;

	if (info->spec != 'S' && !info->mods.l)
	{
		str = va_arg(arg, char *);
		if (str)
			len = (int)ft_strnlen("(null)", info->prec);
		else
			len = (int)ft_strnlen(str, info->prec);
	}
	else
	{
		str = (char *)va_arg(arg, wchar_t *);
		if (str)
			len = (int)ft_wcsnlen((wchar_t *)str, info->prec);
		else
			len = (int)ft_wcsnlen(L"(null)", info->prec);
	}
	info->width -= len;
	return (print(info, str, len));
}
