#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *start;

	start = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (start);
}
