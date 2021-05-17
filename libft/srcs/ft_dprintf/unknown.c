#include "ft_dprintf.h"

static int	print(t_dpf *info, int c, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar_fd('0', info->width, info->fd);
	ft_putchar_fd(c, info->fd);
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	dform_unknown(t_dpf *info)
{
	int	len;

	len = 1;
	info->width--;
	return (print(info, info->spec, len));
}
