#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strnlen(src, size - 1);
	ft_strncpy(dst, src, len);
	dst[len] = '\0';
	return (ft_strlen(src));
}
