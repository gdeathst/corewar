#include "libft.h"

void			ft_strrev(char *s)
{
	char *end;
	char c;

	end = s + ft_strlen(s) - 1;
	while (s < end)
	{
		c = *s;
		*s++ = *end;
		*end-- = c;
	}
}
