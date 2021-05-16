#include "libft.h"

int		ft_isaldigit(char *s)
{
	while (*s)
		if (!ft_isdigit(*s))
			return (0);
		else
			s++;
	return (1);
}
