#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	n = 0;
	while (ft_isdigit(*str))
	{
		if (n != n * 10 / 10)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		n = 10 * n + (*str++ - '0');
	}
	return (n * sign);
}
