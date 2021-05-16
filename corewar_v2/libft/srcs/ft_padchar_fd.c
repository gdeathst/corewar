#include "libft.h"

void	ft_padchar_fd(char c, size_t len, int fd)
{
	while (len--)
		ft_putchar_fd(c, fd);
}
