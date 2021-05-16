#include "libft.h"

int	ft_ispunct(int c)
{
	if (ft_isgraph(c) && !ft_isalnum(c))
		return (1);
	return (0);
}
