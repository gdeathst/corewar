#include "ft_dprintf.h"

static int	print(t_dpf *info, int c, int len)
{
	if (info->width > 0 && !info->flags.minus)
	{
		if (!info->flags.zero)
			ft_padchar_fd(' ', info->width, info->fd);
		else
			ft_padchar_fd('0', info->width, info->fd);
	}
	ft_putchar_fd(c, info->fd);
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + (info->width));
	return (len);
}

int	dform_character(va_list arg, t_dpf *info)
{
	int		c;
	int		len;

	if (info->mods.l)
		return (dform_wcharacter(arg, info));
	c = va_arg(arg, int);
	len = 1;
	info->width--;
	return (print(info, c, len));
}
