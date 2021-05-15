#include <stdlib.h>
#include "libft.h"

char			*ft_strnew(size_t size)
{
	char *buf;
	char *lol;

	if (!(buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	lol = buf;
	size++;
	while (size--)
		*buf++ = '\0';
	return (lol);
}
