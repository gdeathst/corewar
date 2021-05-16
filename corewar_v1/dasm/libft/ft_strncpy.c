#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *buf;

	buf = dst;
	while (len--)
		if (*src != '\0')
			*dst++ = *src++;
		else
			*dst++ = '\0';
	return (buf);
}
