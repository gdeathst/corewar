#include "ft_dprintf.h"

void	dset_width(const char **format, va_list arg, t_dpf *info)
{
	while (ft_isdigit(**format) || **format == '*')
	{
		info->width = 0;
		if (**format != '*')
			while (ft_isdigit(**format))
				info->width = 10 * info->width + (*(*format)++ - '0');
		else
		{
			info->width = va_arg(arg, int);
			if (info->width < 0)
			{
				info->width *= -1;
				info->flags.minus = 1;
			}
			(*format)++;
		}
	}
}
