#include "ft_dprintf.h"

static void	putunbr(t_dpf *info, uintmax_t n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', info->fd);
	else
	{
		putunbr(info, n / 10);
		putunbr(info, n % 10);
	}
}

int	integer2_res_ret(t_dpf *info, intmax_t n, int len)
{
	if (len)
	{
		if (n < 0)
			n *= -1;
		putunbr(info, n);
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + (info->width));
	return (len);
}
