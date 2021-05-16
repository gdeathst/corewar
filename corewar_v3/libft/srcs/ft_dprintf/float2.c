#include "ft_dprintf.h"

static void	putnbr(t_dpf *info, uintmax_t n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', info->fd);
	else
	{
		putnbr(info, n / 10);
		putnbr(info, n % 10);
	}
}

static void	putfltnbr(t_dpf *info, long double n)
{
	if (n < 0)
		n = -n;
	n += 5L / ft_powl(10L, info->prec + 1);
	putnbr(info, n);
	n -= (uintmax_t)n;
	if (info->prec || info->flags.hash)
	{
		ft_putchar_fd('.', info->fd);
		while (info->prec--)
		{
			ft_putchar_fd((uintmax_t)(n *= 10L) + '0', info->fd);
			n -= (uintmax_t)n;
		}
	}
}

static int	print_2(t_dpf *info, long double n, int len)
{
	if (n == n && n != n / 0)
		putfltnbr(info, n);
	else if (n != n)
	{
		if (info->spec != 'F')
			ft_putstr("nan");
		else
			ft_putstr("NAN");
	}
	else if (n == n / 0)
	{
		if (info->spec != 'F')
			ft_putstr("inf");
		else
			ft_putstr("INF");
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar_fd(' ', info->width, info->fd);
	if (info->width > 0)
		return (len + (info->width));
	return (len);
}

int	print2(t_dpf *info, long double n, int len)
{
	if (info->width > 0 && !info->flags.minus && (!info->flags.zero || n != n))
		ft_padchar_fd(' ', info->width, info->fd);
	if (n < 0)
		ft_putchar_fd('-', info->fd);
	else if (n == n && (info->flags.space || info->flags.plus))
	{
		if (info->flags.space)
			ft_putchar_fd(' ', info->fd);
		else
			ft_putchar_fd('+', info->fd);
	}
	if (n == n && info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar_fd('0', info->width, info->fd);
	return (print_2(info, n, len));
}
