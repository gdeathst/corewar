#include "ft_dprintf.h"

static int	isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

void	dset_flags(const char **format, t_dflags *flags)
{
	while (isflag(**format))
	{
		if (**format == '#')
			flags->hash = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '-')
			flags->minus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->plus = 1;
		(*format)++;
	}
}
