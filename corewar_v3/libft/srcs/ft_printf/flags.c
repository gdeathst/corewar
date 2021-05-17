#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

void	set_flags(const char **format, t_flags *flags)
{
	while (is_flag(**format))
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
