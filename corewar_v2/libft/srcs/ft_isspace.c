#include "libft.h"

int	ft_isspace(int c)
{
	if (ft_isblank(c) || (c >= '\n' && c <= '\r'))
		return (1);
	return (0);
}
