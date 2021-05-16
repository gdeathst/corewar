#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d <= s)
		ft_memcpy(d, s, len);
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
