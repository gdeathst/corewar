#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buf;
	char *bufstart;

	if (s == NULL)
		return (NULL);
	if (!(buf = ft_strnew(len)))
		return (NULL);
	bufstart = buf;
	while (len--)
		*buf++ = s[start++];
	*buf = '\0';
	return (bufstart);
}
