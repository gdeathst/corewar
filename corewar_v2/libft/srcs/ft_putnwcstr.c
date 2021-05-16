#include "libft.h"

void	ft_putnwcstr(const wchar_t *s, size_t n)
{
	while (*s && n)
	{
		if (*s < 128 && n >= 1)
			n--;
		else if (*s < 2048 && n >= 2)
			n -= 2;
		else if (*s < 65436 && n >= 3)
			n -= 3;
		else if (n >= 4)
			n -= 4;
		else
			break ;
		ft_putwchar(*s++);
	}
}
