#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dst);
	while (*src && len + 1 < size)
		dst[len++] = *src++;
	dst[len] = '\0';
	return (ft_strnlen(dst, size) + ft_strlen(src));
}
