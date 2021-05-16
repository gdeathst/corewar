#include "libft.h"

void	ft_putwcstr(const wchar_t *s)
{
	while (*s)
		ft_putwchar(*s++);
}
