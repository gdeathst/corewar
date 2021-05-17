#include "ft_printf.h"

static int	is_numeric(int c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x')
		return (1);
	if (c == 'D' || c == 'O' || c == 'U' || c == 'X')
		return (1);
	return (0);
}

void	set_spec(const char **format, t_pf *info)
{
	info->spec = **format;
	if (!info->flags.hash && info->spec == 'p')
		info->flags.hash = 1;
	if (info->flags.zero)
		if (info->flags.minus || (info->prec >= 0 && is_numeric(info->spec)))
			info->flags.zero = 0;
	if (info->flags.space && info->flags.plus)
		info->flags.space = 0;
	if (info->spec == 'f' && info->prec == -1)
		info->prec = 6;
}
