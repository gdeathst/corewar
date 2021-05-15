#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *buf;

	buf = b;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (buf);
}
