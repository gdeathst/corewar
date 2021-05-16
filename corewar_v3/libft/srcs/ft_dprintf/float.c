#include "ft_dprintf.h"

static int	nlen(long long n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	dform_float(va_list arg, t_dpf *info)
{
	long double	n;
	int			len;

	if (!info->mods.ll)
		n = va_arg(arg, double);
	else
		n = va_arg(arg, long double);
	if (n == n && n != n / 0)
	{
		if (!info->prec)
			len = nlen(n) + 0;
		else
			len = nlen(n) + (info->prec + 1);
	}
	else
		len = 3;
	if (n == n && (n < 0 || info->flags.plus || info->flags.space))
		len++;
	info->width -= len;
	return (print2(info, n, len));
}
