#include "libft.h"

void	ft_putnstr(const char *s, size_t n)
{
	while (*s && n--)
		ft_putchar(*s++);
}
