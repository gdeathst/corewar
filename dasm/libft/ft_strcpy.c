#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *buf;

	buf = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (buf);
}
