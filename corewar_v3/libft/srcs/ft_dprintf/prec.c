#include "ft_dprintf.h"

void	dset_prec(const char **format, va_list arg, t_dpf *info)
{
	if (**format == '.')
	{
		info->prec = 0;
		(*format)++;
		if (**format != '*')
			while (ft_isdigit(**format))
				info->prec = 10 * info->prec + (*(*format)++ - '0');
		else
		{
			info->prec = va_arg(arg, int);
			if ((info->prec) < 0)
				info->prec = -1;
			(*format)++;
		}
	}
}
