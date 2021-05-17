#include "ft_printf.h"

static int	print(t_pf *info, char *str, int len)
{
	if (info->width > 0 && !info->flags.minus && !info->flags.zero)
		ft_padchar(' ', info->width);
	if (info->width > 0 && !info->flags.minus && info->flags.zero)
		ft_padchar('0', info->width);
	if ((info->spec != 'S' && !info->mods.l) && str)
		ft_putnstr(str, info->prec);
	else if ((info->spec != 'S' && !info->mods.l) && !str)
		ft_putnstr("(null)", info->prec);
	else
	{
		if (str)
			ft_putnwcstr((wchar_t *)str, info->prec);
		else
			ft_putnwcstr(L"(null)", info->prec);
	}
	if (info->width > 0 && info->flags.minus)
		ft_padchar(' ', info->width);
	if (info->width > 0)
		return (len + info->width);
	return (len);
}

int	form_string(va_list arg, t_pf *info)
{
	char	*str;
	int		len;

	if (info->spec != 'S' && !info->mods.l)
	{
		str = va_arg(arg, char *);
		if (str)
			len = (int)ft_strnlen(str, info->prec);
		else
			len = (int)ft_strnlen("(null)", info->prec);
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
