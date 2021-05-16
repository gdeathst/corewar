#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (src || dst)
		while (n--)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
