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
	if (info->spec != 'X')
		ft_putstr_fd("0x", info->fd);
	else
		ft_putstr_fd("0X", info->fd);
	if (info->prec > 0)
		ft_padchar_fd('0', info->prec, info->fd);
	else if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar_fd('0', info->width, info->fd);
	if (!(!n && !info->prec))
	{
		if (info->spec != 'X')
			puthexnbr(info, n, 'a');
		else
			puthexnbr(info, n, 'A');
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	dform_pointer(va_list arg, t_dpf *info)
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
