#include "ft_printf.h"

static int	print(t_pf *info, int c, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar(' ', info->width);
	if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar('0', info->width);
	ft_putchar(c);
	if (info->width > 0 && info->flags.minus)
		ft_padchar(' ', info->width);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	form_unknown(t_pf *info)
{
	int	len;

	len = 1;
	info->width--;
	return (print(info, info->spec, len));
}
