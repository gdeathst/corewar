#include "libft.h"

int			ft_iswhite(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == ' ') || \
		(c == '\r') || (c == '\f'))
		return (1);
	return (0);
}
