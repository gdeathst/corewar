#include "libft.h"

void	ft_putnstr_fd(const char *s, size_t n, int fd)
{
	while (*s && n--)
		ft_putchar_fd(*s++, fd);
}
