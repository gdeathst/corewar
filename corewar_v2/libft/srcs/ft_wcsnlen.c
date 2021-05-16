#include "libft.h"

size_t	ft_wcsnlen(const wchar_t *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (*s && len + 1 <= maxlen)
	{
		if (*s < 128 && len + 1 <= maxlen)
			len++;
		else if (*s < 2048 && len + 2 <= maxlen)
			len += 2;
		else if (*s < 65536 && len + 3 <= maxlen)
			len += 3;
		else if (len + 4 <= maxlen)
			len += 4;
		else
			break ;
		s++;
	}
	return (len);
}
