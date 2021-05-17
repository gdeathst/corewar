#include "ft_printf.h"

void	help_float2(long double n, t_pf *info)
{
	if (n != n)
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
}
