#include "libft.h"

int			ft_strclr(char *s)
{
	if (s != NULL)
		while (*s)
			*s++ = 0;
	return (1);
}
