#include "libft.h"

int	ft_getnbr(const char *str)
{
	int	n;

	n = 0;
	while (ft_isdigit(*str))
		n = 10 * n + (*str++ - '0');
	return (n);
}
