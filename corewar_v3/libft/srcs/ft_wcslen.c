#include "libft.h"

size_t	ft_wcslen(const wchar_t *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s < 128)
			len++;
		else if (*s < 2048)
			len += 2;
		else if (*s < 65536)
			len += 3;
		else
			len += 4;
		s++;
	}
	return (len);
}
