#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*buf;
	char	*lol;

	if (!(buf = (char *)malloc(sizeof(buf) * size)))
		return (NULL);
	lol = buf;
	while (size--)
		*buf++ = 0;
	return (lol);
}
